/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionabout;
    QWidget *centralwidget;
    QRadioButton *filterradio;
    QRadioButton *monitorradio;
    QRadioButton *portscanradio;
    QRadioButton *advconfradio;
    QRadioButton *inforadio;
    QPushButton *nextbutton;
    QPushButton *exitbutton;
    QCommandLinkButton *startstopbutton;
    QCommandLinkButton *flushbutton;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *File;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(419, 414);
        QIcon icon;
        icon.addFile(QString::fromUtf8("firewall.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionabout = new QAction(MainWindow);
        actionabout->setObjectName(QString::fromUtf8("actionabout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        filterradio = new QRadioButton(centralwidget);
        filterradio->setObjectName(QString::fromUtf8("filterradio"));
        filterradio->setGeometry(QRect(11, 80, 60, 21));
        monitorradio = new QRadioButton(centralwidget);
        monitorradio->setObjectName(QString::fromUtf8("monitorradio"));
        monitorradio->setGeometry(QRect(11, 128, 117, 21));
        portscanradio = new QRadioButton(centralwidget);
        portscanradio->setObjectName(QString::fromUtf8("portscanradio"));
        portscanradio->setGeometry(QRect(11, 176, 85, 21));
        advconfradio = new QRadioButton(centralwidget);
        advconfradio->setObjectName(QString::fromUtf8("advconfradio"));
        advconfradio->setGeometry(QRect(11, 224, 175, 21));
        inforadio = new QRadioButton(centralwidget);
        inforadio->setObjectName(QString::fromUtf8("inforadio"));
        inforadio->setGeometry(QRect(11, 272, 239, 21));
        nextbutton = new QPushButton(centralwidget);
        nextbutton->setObjectName(QString::fromUtf8("nextbutton"));
        nextbutton->setGeometry(QRect(200, 320, 84, 26));
        exitbutton = new QPushButton(centralwidget);
        exitbutton->setObjectName(QString::fromUtf8("exitbutton"));
        exitbutton->setGeometry(QRect(310, 320, 84, 26));
        startstopbutton = new QCommandLinkButton(centralwidget);
        startstopbutton->setObjectName(QString::fromUtf8("startstopbutton"));
        startstopbutton->setGeometry(QRect(10, 0, 191, 41));
        flushbutton = new QCommandLinkButton(centralwidget);
        flushbutton->setObjectName(QString::fromUtf8("flushbutton"));
        flushbutton->setGeometry(QRect(210, 0, 179, 41));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 419, 23));
        File = new QMenu(menuBar);
        File->setObjectName(QString::fromUtf8("File"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(File->menuAction());
        File->addAction(actionabout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FireConfig", 0, QApplication::UnicodeUTF8));
        actionabout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        filterradio->setText(QApplication::translate("MainWindow", "Filters", 0, QApplication::UnicodeUTF8));
        monitorradio->setText(QApplication::translate("MainWindow", "Monitor Status", 0, QApplication::UnicodeUTF8));
        portscanradio->setText(QApplication::translate("MainWindow", "Port Scan", 0, QApplication::UnicodeUTF8));
        advconfradio->setText(QApplication::translate("MainWindow", "Advanced Configuration", 0, QApplication::UnicodeUTF8));
        inforadio->setText(QApplication::translate("MainWindow", "Information on Ports and Services", 0, QApplication::UnicodeUTF8));
        nextbutton->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
        exitbutton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        startstopbutton->setText(QApplication::translate("MainWindow", "Stop Firewall", 0, QApplication::UnicodeUTF8));
        flushbutton->setText(QApplication::translate("MainWindow", "Flush Firewall", 0, QApplication::UnicodeUTF8));
        File->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
