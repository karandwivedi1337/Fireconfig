#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include <QtWebKit/QtWebKit>
#include<QtWebKit>

QT_BEGIN_NAMESPACE

class Ui_informationwindow
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;
    QWebView *view;
    QPushButton *backbutton;
    QLabel *statuslabel;

    void setupUi(QMainWindow *informationwindow)
    {
        if (informationwindow->objectName().isEmpty())
            informationwindow->setObjectName(QString::fromUtf8("informationwindow"));
        informationwindow->resize(700, 500);
        centralwidget = new QWidget(informationwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        informationwindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(informationwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        informationwindow->setStatusBar(statusbar);

        view = new QWebView(centralwidget);
        view->setObjectName(QString::fromUtf8("webview"));
        view->setGeometry(QRect(0, 0, 700, 450));

        backbutton = new QPushButton(centralwidget);
        backbutton->setObjectName(QString::fromUtf8("backbutton"));
        backbutton->setGeometry(QRect(612, 452, 84, 26));

        statuslabel = new QLabel(centralwidget);
        statuslabel->setObjectName(QString::fromUtf8("statuslabel"));
        statuslabel->setGeometry(QRect(10, 460, 281, 16));

        retranslateUi(informationwindow);

        QMetaObject::connectSlotsByName(informationwindow);
    } // setupUi



    void retranslateUi(QMainWindow *informationwindow)
    {
        informationwindow->setWindowTitle(QApplication::translate("informationwindow", "Information", 0, QApplication::UnicodeUTF8));
        backbutton->setText(QApplication::translate("informationwindow", "<Back", 0, QApplication::UnicodeUTF8));
        statuslabel->setText(QApplication::translate("informationwindow", "Loading page... please wait", 0, QApplication::UnicodeUTF8));

    } // retranslateUi

};

    namespace Ui{
        class informationwindow: public Ui_informationwindow {};
    } // namespace Ui

    QT_END_NAMESPACE



#endif // UI_INFORMATION_H
