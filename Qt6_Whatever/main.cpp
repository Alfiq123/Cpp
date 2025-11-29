#include <iostream>
#include <string>

#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

void doCpp() {
    std::string name;
    std::cout << "Enter whatever you like: ";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << "\n";
}

void doQt() {
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Enter whatever you like: ";
    qout.flush();

    QString name = qin.readLine();
    qout << "Hello " << name << "\n";
    qout.flush();
}

void doMixed() {
    QTextStream qin(stdin);
    qInfo() << "Please enter your name: ";
    QString name = qin.readLine();
    qInfo() << "Hello" << name;
}

int main(int argc, char *argv[]) {
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

    // doCpp();
    // doQt();
    doMixed();

    return a.exec();
}
