#ifndef TEST_WIDGET_H
#define TEST_WIDGET_H

#include <QMainWindow>

class test_widget : public QMainWindow
{
    Q_OBJECT

public:
    bool colorFlag;
    test_widget(QWidget *parent = nullptr);
    ~test_widget();
    void toggleColor(void);

};

#endif // TEST_WIDGET_H
