/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonQuit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(220, 90, 331, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell Extra Bold")});
        font.setPointSize(24);
        pushButtonStart->setFont(font);
        pushButtonStart->setAutoDefault(false);
        pushButtonStart->setFlat(false);
        pushButtonLoad = new QPushButton(centralwidget);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(220, 220, 331, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell Extra Bold")});
        font1.setPointSize(24);
        font1.setBold(false);
        pushButtonLoad->setFont(font1);
        pushButtonQuit = new QPushButton(centralwidget);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(220, 340, 331, 111));
        pushButtonQuit->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButtonStart->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start Exercise", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonLoad->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Glossary need to be in a csv-file with one glossary per line. Leftmost word is the glossary and every cell to the rigtht are translations.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonLoad->setText(QCoreApplication::translate("MainWindow", "Load Glossary", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonQuit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
