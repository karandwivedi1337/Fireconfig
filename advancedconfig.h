#ifndef ADVANCEDCONFIG_H
#define ADVANCEDCONFIG_H

#include<ui_advancedconfig.h>
#include<QMainWindow>

class advconfigtest:public QMainWindow, Ui::advancedconfigwindow
{

    Q_OBJECT

public:
    advconfigtest();
    void createactions();

private slots:
    void goback();
    void seestatus();
    void apply();
    void save();
    void execute();
    void deleterule();
    void showfilters();
    void createchain();
    void deletechain();
};

#endif // ADVANCEDCONFIG_H
