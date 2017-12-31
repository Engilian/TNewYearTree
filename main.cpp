#include <QCoreApplication>

#include "core/new_year_core.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto *c = new NewYearCore();
    c->startTimer( 100 );

    return a.exec();
}

