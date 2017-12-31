#include "ncurses_painter_device.h"

#include <QDebug>
#include <QRect>

#include <ncurses.h>
#include <thread>
#include <cmath>

#include "event/tmove_event.h"
#include "event/tresize_event.h"

#include "event/tmouse_event.h"
#include "event/tmove_event.h"
#include "event/tmouse_move_event.h"
#include "event/tmouse_wheel_event.h"
#include "event/tmouse_key_event.h"
#include "event/tmouse_click_event.h"
#include "event/tmouse_double_click_event.h"


NCursesPainterDevice::NCursesPainterDevice(tui::TPainterDevice *parent):
    tui::TAbstractPainterDevice(),
    _pos( 0, 0 ),
    _actualPos( 0,0 ),
    _w( COLS ),
    _h( LINES ),
    _parent( nullptr ),
    _keyHandlerStatus ( false, false ),
    _window( nullptr )
{
    if ( parent ) {
        _w = 5;
        _h = 5;
    }

    setParent ( parent );

    startTimer ( 300 );
}

NCursesPainterDevice::~NCursesPainterDevice()
{
    if ( isInitedKeyHandler () ) {

        destroyKeyHandler ();
    }

    removeWindow ();
}

void NCursesPainterDevice::timerEvent(QTimerEvent *event)
{
    if ( _parent ) {

        killTimer ( event->timerId () );
        return;
    }

    refresh ();
    int w = COLS, h = LINES;
    if ( _w != w || _h != h ) {

        resize ( w, h );
    }
}

void NCursesPainterDevice::setParent(tui::TPainterDevice *device)
{
    if ( _parent ) {

        disconnect ( device, &tui::TPainterDevice::moveEvent,
                  this,   &NCursesPainterDevice::parentMoved );

        disconnect ( device, &tui::TPainterDevice::updated,
                  this,   &NCursesPainterDevice::parentUpdated );

        _parent = nullptr;
    }

    if ( device ) {

        _parent =  device;

        connect ( device, &tui::TPainterDevice::moveEvent,
                  this,   &NCursesPainterDevice::parentMoved );

        connect ( device, &tui::TPainterDevice::updated,
                  this,   &NCursesPainterDevice::parentUpdated );

        createWindow ();
        move ( _pos );
    }
}

tui::TPainterDevice *NCursesPainterDevice::parent() const
{
    return _parent;
}

QRect NCursesPainterDevice::rect() const
{
    return QRect( _pos, QSize( _w, _h ) );
}

QPoint NCursesPainterDevice::pos() const
{
    return _pos;
}

QPoint NCursesPainterDevice::centerPos() const
{
    return _pos + QPoint( _w / 2, _h / 2 );
}

int NCursesPainterDevice::x() const
{
    return _pos.x ();
}

int NCursesPainterDevice::y() const
{
    return _pos.y ();
}

int NCursesPainterDevice::cx() const
{
    return _pos.x () + _w / 2;
}

int NCursesPainterDevice::cy() const
{
    return _pos.y () + _h / 2;
}

bool NCursesPainterDevice::move(const QPoint &p)
{
    QPoint parentPos    = _parent ? _parent->actualPos () : QPoint( 0, 0 );

    // Проверяем на возможность перемещения
    if ( !_window || p + parentPos == _actualPos ) return false;

    QPoint desire       = p + parentPos;
    QPoint old          = _pos;
    QPoint actualOld    = _actualPos;

    mvwin ( _window, desire.y (), desire.x () );

    _actualPos  = QPoint( getbegx ( _window ),
                          getbegy ( _window ) );
    _pos        = _actualPos - parentPos;

    if ( _pos != old ) {

        emit moveEvent ( new tui::TMoveEvent( _pos, old ) );
    }
    else if ( actualOld != _actualPos ) {

        emit updated ();
    }

    // Окно успешно передвинуто
    if ( p == _pos ) {
        return true;
    }

    return false;
}

bool NCursesPainterDevice::move(int x, int y)
{
    QPoint p( x, y );
    return move( p );
}

bool NCursesPainterDevice::moveToCenter(const QPoint &p)
{
    QPoint movePoint (
                p.x () - _w / 2,
                p.y () - _h / 2
                );

    return move(  movePoint );
}

bool NCursesPainterDevice::moveToCenter(int x, int y)
{
    QPoint p( x, y );
    return moveToCenter ( p );
}

QPoint NCursesPainterDevice::actualPos() const
{
    return _actualPos;
}

QPoint NCursesPainterDevice::actualCenterPos() const
{
    return _actualPos - QPoint( _w / 2, _h / 2 );
}

QSize NCursesPainterDevice::size() const
{
    return QSize( _w, _h );
}

int NCursesPainterDevice::width() const
{
    return _w;
}

int NCursesPainterDevice::height() const
{
    return _h;
}

bool NCursesPainterDevice::resize(int w, int h)
{
    if ( w == _w && h == _h ) return false;

    QSize old( _w, _h );

    if ( !_window ) {

        _w = COLS;
        _h = LINES;

        resize_term ( _h, _w );
    }
    else {

        wresize ( _window, h, w );

        _w = getmaxx ( _window );
        _h = getmaxy ( _window );
    }

    if ( _w != old.width () || _h != old.height () ) {

        QSize current( _w, _h );

        emit resizeEvent ( new tui::TResizeEvent( current,  old ) );
    }

    if ( _w == w && _h == h ) {

        return true;
    }

    return false;
}

bool NCursesPainterDevice::resize(const QSize &size)
{
    return resize ( size.width (), size.height () );
}

void NCursesPainterDevice::createWindow()
{
    if ( _window ) {
        removeWindow ();
    }

    WINDOW *parentWindow = nullptr;

    if ( parent () ) {

        auto nw = _parent->convert<NCursesPainterDevice>();

        if ( nw ) {

            parentWindow = nw->_window;
        }
    }

    if ( parentWindow ) {

        _window = subwin ( parentWindow, 1, 1, 0, 0 );

        _window = newwin ( _h, _w,
                           _pos.x () + getbegx ( parentWindow ),
                           _pos.y () + getbegx ( parentWindow ) );
    }
    else {

        _window = newwin ( _h, _w, _pos.y (), _pos.x () );
    }

    //    _panel = new_panel ( _window );
}

void NCursesPainterDevice::removeWindow()
{
    if ( _window ) {

        delwin ( _window );
    }
}

void NCursesPainterDevice::initKeyHandler()
{
    std::thread th( std::bind( &NCursesPainterDevice::_keyHandlerWork, this ) );
    th.detach ();
}

bool NCursesPainterDevice::isInitedKeyHandler() const
{
    return _keyHandlerStatus.first || _keyHandlerStatus.second;
}

void NCursesPainterDevice::destroyKeyHandler()
{
    _keyHandlerStatus.first = false;

    while ( _keyHandlerStatus.second ) {

        std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    }
}

void NCursesPainterDevice::_keyHandlerWork()
{
    _keyHandlerStatus.first     = true;
    _keyHandlerStatus.second    = true;

    MEVENT  mEvent;

    WINDOW *win = _window ? _window : stdscr;

    keypad( win, TRUE);
    mousemask( ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    printf("\033[?1003h\n");

    int key;
    while ( _keyHandlerStatus.first ) {


        key = wgetch ( stdscr );

        if ( key == ERR ) {

            // ERROR
        }
        else if ( key == KEY_MOUSE ) {

            if ( getmouse ( &mEvent ) == OK ) {

                QPoint mPosition( mEvent.x, mEvent.y );

                tui::TMouseEvent *event = nullptr;

                switch (mEvent.bstate) {
                // LEFT
                case BUTTON1_PRESSED:
                    event = new tui::TMouseKeyEvent( tui::TMouseButton::LEFT_BUTTON,
                                                     true,
                                                     mPosition );
                    break;
                case BUTTON1_RELEASED:
                    event = new tui::TMouseKeyEvent( tui::TMouseButton::LEFT_BUTTON,
                                                     false,
                                                     mPosition );
                    break;
                case BUTTON1_CLICKED:
                    event = new tui::TMouseClickEvent( tui::TMouseButton::LEFT_BUTTON,
                                                       mPosition );
                    break;

                case BUTTON1_DOUBLE_CLICKED:
                    event = new tui::TMouseDoubleClickEvent( tui::TMouseButton::LEFT_BUTTON,
                                                             mPosition );
                    break;

                    // Center
                case BUTTON2_PRESSED:
                    event = new tui::TMouseKeyEvent( tui::TMouseButton::MIDDLE_BUTTON,
                                                     true,
                                                     mPosition );
                    break;
                case BUTTON2_RELEASED:
                    event = new tui::TMouseKeyEvent( tui::TMouseButton::MIDDLE_BUTTON,
                                                     false,
                                                     mPosition );
                    break;
                case BUTTON2_CLICKED:
                    event = new tui::TMouseClickEvent( tui::TMouseButton::MIDDLE_BUTTON,
                                                       mPosition );
                    break;

                case BUTTON2_DOUBLE_CLICKED:
                    event = new tui::TMouseDoubleClickEvent( tui::TMouseButton::MIDDLE_BUTTON,
                                                             mPosition );
                    break;

                    // Right
                case BUTTON3_PRESSED:
                    event = new tui::TMouseKeyEvent( tui::TMouseButton::RIGHT_BUTTON,
                                                     true,
                                                     mPosition );
                    break;
                case BUTTON3_RELEASED:
                    event = new tui::TMouseKeyEvent( tui::TMouseButton::RIGHT_BUTTON,
                                                     false,
                                                     mPosition );
                    break;
                case BUTTON3_CLICKED:
                    event = new tui::TMouseClickEvent( tui::TMouseButton::RIGHT_BUTTON,
                                                       mPosition );
                    break;

                case BUTTON3_DOUBLE_CLICKED:
                    event = new tui::TMouseDoubleClickEvent( tui::TMouseButton::RIGHT_BUTTON,
                                                             mPosition );
                    break;

                case REPORT_MOUSE_POSITION:
                    static QPoint last( 0, 0);

                    if ( mPosition != last ) {
                        event = new tui::TMouseMoveEvent( static_cast<tui::TMouseButton>( mEvent.bstate ),
                                                          mPosition,
                                                          QPoint( last ) );
                        last = mPosition;
                    }
                    break;
                default:
                    break;
                }

                if ( event ) {

                    emit mouseEvent ( event );
                }
            }
        }
        else {

            if ( key != ERR ) {
                emit keyEvent ( new tui::TKeyEvent( key,
                                                    static_cast<char>( key ) ) );

            }
        }
    }
    printf("\033[?1003l\n");

    _keyHandlerStatus.second = false;
}

void NCursesPainterDevice::parentMoved(tui::TMoveEvent *)
{
    move ( _pos );
}

void NCursesPainterDevice::parentUpdated()
{
    move( _pos );
}

