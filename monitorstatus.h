#ifndef MONITORSTATUS_H
#define MONITORSTATUS_H

#include<ui_monitorstatus.h>
#include<QMainWindow>
#include<QStandardItemModel>

class monitortest:public QMainWindow, Ui::monitorwindow
{

    Q_OBJECT

public:
    monitortest();
    void createactions();

private:
    QStandardItemModel *model;


private slots:
    void showstatus();
    void goback();
};

#endif // MONITORSTATUS_H
