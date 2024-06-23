#include "ui.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    Repo repo("melodii.txt");
    Validator validator;
    Service service(repo, validator);
    AppGUI w(service);
    w.show();
    return app.exec();
}
