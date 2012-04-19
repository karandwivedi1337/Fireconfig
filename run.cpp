#include<iostream>
#include<QtWebKit/QtWebKit>
#include<QProcess>
#include<QString>
#include<QFile>
#include<QList>
#include<QTextStream>
#include<QMenuBar>
#include<QMenu>
#include<QMessageBox>

#include<test.h>
#include<filter.h>
#include<monitorstatus.h>
#include<portscan.h>
#include<information.h>
#include<advancedconfig.h>
#include<about.h>

test::test(){

    setupUi(this);

    this->setFixedSize(this->width(),this->height());

    createactions();

    checkstatus();

} //test::test() close

void test::createactions(){



    connect(startstopbutton,SIGNAL(clicked()),this,SLOT(startstopslot()));
    connect(flushbutton,SIGNAL(clicked()),this,SLOT(flushslot()));

    connect(exitbutton,SIGNAL(clicked()),this,SLOT(close()));
    connect(nextbutton,SIGNAL(clicked()),this,SLOT(shownext()));
    connect(actionabout,SIGNAL(triggered()),this,SLOT(showhelp()));

} //test::createactions() close


void test::showhelp(){


abouttest *at=new abouttest;
at->show();

}

void test::flushslot(){

     QProcess p;

    switch( QMessageBox::information( this, "Flush Firewall?",
                                          "This will erase all previously configured firewall rules. Continue?",
                                          "OK", "Cancel",
                                          0, 1 ) ) {
        case 0:

        p.start("iptables -F");
        p.waitForFinished();
            break;

         case 1:
           return;
        }


}//test::flushslot() close

void test::shownext(){

    if(monitorradio->isChecked()==true){
    monitortest *mt=new monitortest;
    this->setVisible(false);
    mt->show();

 }
  else if(inforadio->isChecked()==true){

        this->setVisible(false);
        informationtest *it=new informationtest;
        it->show();

    }

    else if(filterradio->isChecked()==true){

        this->setVisible(false);
        filtertest *ft=new filtertest;
        ft->show();

    }

    else if(advconfradio->isChecked()==true){
        this->setVisible(false);
        advconfigtest *adv=new advconfigtest;
        adv->show();
    }

    else if(portscanradio->isChecked()==true){
        this->setVisible(false);
        portscantest *pt=new portscantest;
        pt->show();

    }

}//test::shownext() close

void test::startstopslot(){

    QProcess p;
    QString s=startstopbutton->text();
    int started=0;
    //std::cout<<"Compare output from slot="<<s.compare("FIREWALL DISABLED");

    if(s.compare("FIREWALL DISABLED")==0)
        started=0;
        //p.start("service iptables start");

    else started=1;

    QString msg="";

    if(started==1) msg+="Disable Firewall?";
    else msg+="Enable Firewall?";

    switch(QMessageBox::information( this,"Confirm Action",
                                          msg,
                                          "OK", "Cancel",
                                           0, 1 ) ) {

              case 0:
        if(started==0){
           p.start("service iptables start");
             p.waitForFinished();
        }
        else {
            p.start("service iptables stop");
              p.waitForFinished();}

}

        //p.start("service iptables stop");

    p.waitForFinished();

    checkstatus();

} //test::startstopslot() close



void test::checkstatus(){

    QProcess p;
    p.start("systemctl is-active iptables.service");
    p.waitForFinished();

    QString out=p.readAllStandardOutput();

    filterradio->setChecked(false);
    monitorradio->setChecked(false);
    portscanradio->setChecked(false);
    advconfradio->setChecked(false);
    inforadio->setChecked(false);

    if(out.compare("inactive\n")==0){

     startstopbutton->setText("FIREWALL DISABLED");
     flushbutton->setEnabled(false);

     filterradio->setEnabled(false);
     monitorradio->setEnabled(false);
     portscanradio->setEnabled(false);
     advconfradio->setEnabled(false);
     inforadio->setEnabled(false);

    }//if close

    else if(out.compare("active\n")==0){
        startstopbutton->setText("Firewall enabled");

        flushbutton->setEnabled(true);
        filterradio->setEnabled(true);
        monitorradio->setEnabled(true);
        portscanradio->setEnabled(true);
        advconfradio->setEnabled(true);
        inforadio->setEnabled(true);

    }//else close

}//test::checkstatus() close
