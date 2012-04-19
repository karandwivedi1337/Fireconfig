#ifndef PORTSCAN_H
#define PORTSCAN_H

#include<QMainWindow>
#include<ui_portscan.h>

class portscantest: public QMainWindow,Ui::portscanwindow{

   Q_OBJECT

public:
    portscantest();
    void createactions();

private slots:
    void goback();
    void seefilters();
    void scan();
};


#endif // PORTSCAN_H
