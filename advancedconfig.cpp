#include<QProcess>
#include<test.h>
#include<advancedconfig.h>
#include<monitorstatus.h>
#include<filter.h>

advconfigtest::advconfigtest(){

    setupUi(this);

    this->setFixedSize(this->width(),this->height());

    this->setGeometry(QRect(350,150,640,530));

    createactions();

} //advconfigtest::advconfigtest() close


void advconfigtest::createactions(){

    connect(backbutton,SIGNAL(clicked()),this,SLOT(goback()));
    connect(statusbutton,SIGNAL(clicked()),this,SLOT(seestatus()));
    connect(filtersbutton,SIGNAL(clicked()),this,SLOT(showfilters()));
    connect(applybutton,SIGNAL(clicked()),this,SLOT(apply()));
    connect(savebutton,SIGNAL(clicked()),this,SLOT(save()));
    connect(executebutton,SIGNAL(clicked()),this,SLOT(execute()));
    connect(deleterulebutton,SIGNAL(clicked()),this,SLOT(deleterule()));
    connect(createchainbutton,SIGNAL(clicked()),this,SLOT(createchain()));
    connect(deletechainbutton,SIGNAL(clicked()),this,SLOT(deletechain()));
}

void advconfigtest::goback(){
    this->setVisible(false);
    test *t=new test;
    t->show();

}//advconfig::goback() close


void advconfigtest::showfilters(){

        this->setVisible(false);
     filtertest *f=new filtertest;
     f->show();

}


void advconfigtest::seestatus(){

    this->setVisible(false);
    monitortest *mt=new monitortest;
    mt->show();
}

void advconfigtest::apply(){

    outputtextedit->setText("");

    QString rule="iptables -P ";

    if(inputradio->isChecked()) rule+="INPUT ";
    else if(outputradio->isChecked()) rule+="OUTPUT ";
    else if(forwardradio->isChecked()) rule+="FORWARD ";
    else{  outputtextedit->setText("Select a rule type!"); return; }


    if(acceptradio->isChecked())
        rule+="ACCEPT";

    else if(dropradio->isChecked())
        rule+="DROP";
    else { outputtextedit->setText("Select a default policy!"); return;}

    char comm[128];

    strcpy(comm,rule.toAscii());

    int out=system(comm);

    if(out==0) outputtextedit->setText("Default Policy applied successfully!");

    else outputtextedit->setText("Error: Unable to apply default policy");

}

void advconfigtest::save(){


    QProcess p;
    p.start("iptables-save");

    p.waitForFinished();

    QString out=p.readAllStandardOutput();

    outputtextedit->setText(out);

}


void advconfigtest::execute(){

    outputtextedit->setText("");

    QString comm=commandlineedit->text();

    if(comm.trimmed().isEmpty()){

        outputtextedit->setText("Enter a custom command to execute");
        return;
    }

    else{

    char command[128];
    strcpy(command,comm.toAscii());

    QProcess p;
    p.start(command);

    p.waitForFinished();

    QString out=p.readAllStandardOutput();

    outputtextedit->setText(out);

    }//else close

}//advconfigtest::save() close


void advconfigtest::deleterule(){


    outputtextedit->setText("");

    QString rule="iptables -D ";

    if(inputradio->isChecked()) rule+="INPUT ";
    else if(outputradio->isChecked()) rule+="OUTPUT ";
    else if(forwardradio->isChecked()) rule+="FORWARD ";
    else{  outputtextedit->setText("Select a rule type to delete a rule from!"); return; }

    QString num=deleterulelineedit->text();

    if(num.trimmed().isEmpty()){
        outputtextedit->setText("Enter a rule number to delete");
        return;
    }

    else{

        rule+=deleterulelineedit->text();

        char comm[128];

        strcpy(comm,rule.toAscii());

        int out=system(comm);

        if(out==0) outputtextedit->setText("Rule deleted successfully!");

        else outputtextedit->setText("Error: Unable to delete rule "+num);


    }

}//advconfigtest::deleterule() close



void advconfigtest::createchain(){

outputtextedit->setText("");

QString str=createchainlineedit->text();

if(str.trimmed().isEmpty()){

    outputtextedit->setText("Enter a chain name!");
    return;
}

else{

    QString rule="iptables -N ";

    rule+=createchainlineedit->text();

    char comm[128];

    strcpy(comm,rule.toAscii());

    int out=system(comm);

    QString chainname=createchainlineedit->text();

    if(out==0) outputtextedit->setText("Chain "+ chainname+ " created successfully!");

    else outputtextedit->setText("Error: Unable to create chain named "+chainname);

}

}//advconfigtest::createchain() close


void advconfigtest::deletechain(){

    outputtextedit->setText("");

    QString str=deletechainlineedit->text();

    if(str.trimmed().isEmpty()){

        outputtextedit->setText("Enter a chain name!");
        return;
    }

    else{

        QString rule="iptables -X ";

        rule+=deletechainlineedit->text();

        char comm[128];

        strcpy(comm,rule.toAscii());

        int out=system(comm);

        QString chainname=deletechainlineedit->text();

        if(out==0) outputtextedit->setText("Chain "+ chainname+ " deleted successfully!");

        else outputtextedit->setText("Error: Unable to delete chain named "+chainname);

    }

}//advconfigtest::deletechain() close
