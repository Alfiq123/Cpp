#include <QCoreApplication>

#include "cat.h"
#include <QDebug>

void test(Cat &cat)
{
    qInfo() << "Address:" << &cat;
}

void test2(Cat *cat)
{
    qInfo() << "Pointer:" << cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    Cat kitty; kitty.setObjectName("Kitty");
    Cat orange; orange.setObjectName("Orange");
    Cat black; black.setObjectName("Black");

    test(kitty);
    test2(&kitty);

    test(orange);
    test2(&orange);

    test(black);
    test2(&black);

    // qInfo() << &kitty;

    return a.exec();
}
