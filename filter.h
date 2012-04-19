#ifndef FILTER_H
#define FILTER_H

#include<ui_filter.h>
#include<QMainWindow>

class filtertest:public QMainWindow, Ui::filterwindow
{

    Q_OBJECT

public:
    filtertest();
    void createactions();

private slots:
    void goback();
    void seestatus();
    void goadvanced();
    void applyrule();
};

#endif // FILTER_H
