#include<QFile>
#include<monitorstatus.h>
#include<test.h>

monitortest::monitortest(){

    setupUi(this);

    this->setFixedSize(this->width(),this->height());

    this->setGeometry(QRect(50,200,1200,432));

    fetchstatuslabel->setVisible(false);

    createactions();

}//monitortest::monitortest() close


void monitortest::createactions(){

    connect(getstatusbutton,SIGNAL(clicked()),this,SLOT(showstatus()));
    connect(backbutton,SIGNAL(clicked()),this,SLOT(goback()));

}//monitortest::createactions() close




void monitortest::showstatus(){

    fetchstatuslabel->setVisible(true);

    progressbar->setValue(15);

    QFile ipfile("iptables.txt");

    if(ipfile.exists()) QFile::remove("iptables.txt");

    system("iptables -L -v > iptables.txt");

    progressbar->setValue(35);

    ipfile.open(QIODevice::ReadOnly | QIODevice::Text);
    //QTextStream in1(&ipfile);

    QString set1;

    while(!ipfile.atEnd()){
    QString line1 = ipfile.readLine();
    set1.append(line1);
    set1.append("\n");}

    progressbar->setValue(55);

    textEdit->setText(set1);

    QFile file2("ss.txt");

    if(file2.exists()) QFile::remove("ss.txt");

    system("ss > ss.txt");

    progressbar->setValue(75);

    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    //QTextStream in2(&file2);

    QString set2;

    while(!file2.atEnd()){
    QString line2 = file2.readLine();
    set2.append(line2);
    set2.append("\n");}

    textEdit_2->setText(set2);

    progressbar->setValue(100);

    fetchstatuslabel->setText("Complete.");

}//monitortest::showstatus() close

void monitortest::goback(){

    this->setVisible(false);
    test *t=new test;
    t->show();

} //monitortest::goback() close
