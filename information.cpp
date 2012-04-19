#include<QtWebKit>
#include<QtWebKit/QtWebKit>
#include<information.h>
#include<test.h>


informationtest::informationtest(){

    setupUi(this);

    this->setFixedSize(this->width(),this->height());

    this->setGeometry(QRect(325,150,700,450));

    //view->load(QUrl("http://www.mxtoolbox.com/SuperTool.aspx"));
    view->load(QUrl("http://www.dnsstuff.com"));
    view->show();

    // if(view->loadFinished(true)) statuslabel->setText("Page loaded successfully.");

    connect(backbutton,SIGNAL(clicked()),this,SLOT(goback()));

}//informationtest:: informationtest() close



void informationtest::goback(){
    this->setVisible(false);
    test *t=new test;
    t->show();

}//informationtest::goback() close
