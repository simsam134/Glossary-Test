#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QFileDialog>
#include<QMessageBox>
#include <QDir>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonQuit_clicked()
{
    std::cout<<"Quit"<<std::endl;
    qApp->quit();
}


void MainWindow::on_pushButtonLoad_clicked()
{
    std::vector<QString> v;

    std::cout<<"load"<<std::endl;
    QString FileName = QFileDialog::getOpenFileName(this, "Open glossary csv-file", QDir::homePath());
    QMessageBox::information(this, "Loaded file", FileName);
    QFile file(FileName);
    if(!file.open(QFile::ReadOnly | QFile::Truncate)){
        QMessageBox::warning(this, "Error", "file not open");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList strList = line.split(QLatin1Char(','));
        v.push_back(strList[0]); // Real word
        strList.removeAt(0);
        v.push_back(strList.join(",")); // Correct answer
        words.push_back(v);
        v.clear();
    }
}


void MainWindow::on_pushButtonStart_clicked()
{
    std::cout<<"Start"<<std::endl;
//    Dialog game;
//    game.setModal(true);
//    game.exec();
    hide();
    game = new Dialog(this);
    game->show();
    std::cout<<"testar"<<std::endl;

}

