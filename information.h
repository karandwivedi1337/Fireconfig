#ifndef INFORMATION_H
#define INFORMATION_H

#include<ui_information.h>
#include<QMainWindow>

class informationtest:public QMainWindow, Ui::informationwindow
{

    Q_OBJECT

public:
    informationtest();

private slots:
    void goback();

};

#endif // INFORMATION_H
