#include<QApplication>
#include<QWidget>
#include<QString>
#include"test.h"

int main(int argc, char* argv[]){

    QApplication app(argc,argv);

    app.setApplicationName("FireConfig");

    test *t=new test;
    t->show();

    return app.exec();
}
