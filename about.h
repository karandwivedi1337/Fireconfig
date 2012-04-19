#ifndef ABOUT_H
#define ABOUT_H


#include<ui_about.h>
#include<QMainWindow>

class abouttest:public QMainWindow, Ui::aboutwindow
{

    Q_OBJECT

public:
    abouttest();

};


#endif // ABOUT_H
