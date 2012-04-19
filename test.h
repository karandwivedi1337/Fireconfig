#ifndef TEST_H
#define TEST_H
#include<ui_test.h>
#include<QMainWindow>

class test:public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
public:
    test();
    void createactions();
    void checkstatus();
private slots:
    void startstopslot();
    void shownext();
    void flushslot();
    void showhelp();
};

#endif // TEST_H
