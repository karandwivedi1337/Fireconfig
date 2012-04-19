#include<QtNetwork>
#include<QTcpSocket>
#include<QHostAddress>
#include<iostream>
#include<portscan.h>
#include<test.h>
#include<filter.h>

portscantest::portscantest(){

    setupUi(this);
    this->setGeometry(QRect(350,175,637,426));
    createactions();

}

void portscantest::createactions(){

    connect(backbutton,SIGNAL(clicked()),this,SLOT(goback()));
    connect(filtersbutton,SIGNAL(clicked()),this,SLOT(seefilters()));
    connect(scanbutton,SIGNAL(clicked()),this,SLOT(scan()));
}

void portscantest::goback(){

    //this->setVisible(false);
    this->hide();

    test *t=new test;
    t->show();

}

void portscantest::seefilters(){

this->setVisible(false);
    filtertest *ft=new filtertest;
    ft->show();

}


void portscantest::scan(){

    outputtextedit->setText("");
progressBar->setValue(0);

QTcpSocket sock;
QString out="Port Scan Results on "+ hostnamelineedit->text()+"\n";

uint delay=1;

if(hostnamelineedit->text().trimmed().isEmpty()){
    outputtextedit->setText("Enter a host name or IP address to scan");
    return;
}

if(startportlineedit->text().trimmed().isEmpty()){
    outputtextedit->setText("Enter a starting port number");
    return;
}

if(endportlineedit->text().trimmed().isEmpty()){
    outputtextedit->setText("Enter an ending port number");
    return;
}

QString hostname=hostnamelineedit->text();

uint startport=startportlineedit->text().toUInt();

uint endport=endportlineedit->text().toUInt();

if(endport-startport<0){
    outputtextedit->setText("Endport should be greater than start port");
    return;
}


scanbutton->setEnabled(false);

statuslabel->setText("Port scan in progress...");

sleep(1);

if(delaylineedit->text().trimmed().isEmpty()==false){
delay=delaylineedit->text().trimmed().toInt();
}

int div=100/(endport-startport+1);
int open=0;

for(int i=startport;i<=endport;i++){

uint port=i;

int curval=progressBar->value();

progressBar->setValue(curval+div);

sock.connectToHost(hostname,port);

bool conn=sock.waitForConnected(2500);

if(conn){
out+="Port ";
out.append(QString("%1").arg(i));
out+=" is open\n";
open++;
}

sock.close();

sleep(delay);

}//for close


out.append(QString("%1").arg(open));
out+=" ports open\n";

progressBar->setValue(100);

outputtextedit->setText(out);

statuslabel->setText("Scan complete");

scanbutton->setEnabled(true);
}//portscantest::scan() close
