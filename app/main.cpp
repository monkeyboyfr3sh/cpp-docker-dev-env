#include "test_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test_widget w;
    w.show();
    return a.exec();
}
