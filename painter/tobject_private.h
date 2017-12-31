#ifndef TOBJECT_PRIVATE_H
#define TOBJECT_PRIVATE_H

#include <memory>

namespace tui {

namespace no_public {

template<typename Interface>
///
/// \brief The TObjectPrivate class
///
class TObjectPrivate
{
    using DPointer = std::shared_ptr<Interface>;
protected:
    TObjectPrivate( Interface *interface ):
        _d( interface ) {}
    TObjectPrivate( const TObjectPrivate<Interface> &obj ):
        _d( obj._d ) {}
public:
    virtual ~TObjectPrivate(){}
public:

    template<typename T>
    ///
    /// \brief Преобразовать к конкртеной реализации
    /// \return умнвй указатель на объект
    ///
    std::shared_ptr<T> convert() const {

        return std::dynamic_pointer_cast<T>( _d );
    }
protected:
    DPointer        _d;
};

}

}



#endif // TOBJECT_PRIVATE_H
