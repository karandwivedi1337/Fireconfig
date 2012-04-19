#include<filter.h>
#include<test.h>
#include<monitorstatus.h>
#include<advancedconfig.h>

filtertest::filtertest(){

    setupUi(this);

    this->setFixedSize(this->width(),this->height());

    this->setGeometry(QRect(350,175,640,480));

    createactions();

}

void filtertest::createactions(){

    connect(applybutton,SIGNAL(clicked()),this,SLOT(applyrule()));
    connect(backbutton,SIGNAL(clicked()),this,SLOT(goback()));
    connect(statusbutton,SIGNAL(clicked()),this,SLOT(seestatus()));
    connect(advancedbutton,SIGNAL(clicked()),this,SLOT(goadvanced()));
}//filtertest::createactions close


void filtertest::goback(){

 this->setVisible(false);

 test *t=new test;
 t->show();

}//filtertest::goback() close

void filtertest::seestatus(){
this->setVisible(false);

        monitortest *mt=new monitortest;
        mt->show();

}//filtertest::seestatus() close


void filtertest::goadvanced(){

    this->setVisible(false);
    advconfigtest *adv=new advconfigtest;
    adv->show();

}


void filtertest::applyrule(){

    //string appends will always have trailing spaces as required

    //icmp support can be added to protocols

    //logging support can be added

    //throws errors if necessary options are not selected or are incompatible

    outputlineedit->setText("");

    QString rule="iptables -A ";

    if(inputradio->isChecked()) rule+="INPUT ";
    else if(outputradio->isChecked()) rule+="OUTPUT ";
    else if(forwardradio->isChecked()) rule+="FORWARD ";
    else{  outputlineedit->setText("Select a rule type!"); return; }

    if(tcpradio->isChecked()) rule+="-p tcp ";
    else if(udpradio->isChecked()) rule+="-p udp ";

    QString sourceip=sourceiplineedit->text();
    QString destip=destiplineedit->text();

    if(sourceip.trimmed().isEmpty()==false){

        rule+="-s "+sourceip.trimmed();
        rule+=" ";

    }//source ip is not null

    if(destip.trimmed().isEmpty()==false){

       rule+="-d "+destip.trimmed();
       rule+=" ";

    }//dest ip is not null


    QString sourceport=sourceportlineedit->text();
    QString destport=destportlineedit->text();

    if(sourceport.trimmed().isEmpty()==false){

        rule+="--sport "+sourceport.trimmed();
        rule+=" ";

    }//source ip is not null

    if(destport.trimmed().isEmpty()==false){

       rule+="--dport "+destport.trimmed();
       rule+=" ";

    }//dest ip is not null

    if(acceptradio->isChecked()){
        rule+="-j ACCEPT";
    }

    else if(dropradio->isChecked()){
        rule+="-j DROP";
    }

    else{
        outputlineedit->setText("Select to allow or block the traffic");
        return;
    }

    char comm[128];

    strcpy(comm,rule.toAscii());

    int out=system(comm);

    if(out==0) outputlineedit->setText("Rule applied successfully!");

    else outputlineedit->setText("Error: Unable to apply rule");

    //apply regex to source and dest ip fields

}//filtertest::applyrule() close
