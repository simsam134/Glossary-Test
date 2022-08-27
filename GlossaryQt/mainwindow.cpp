#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QFileDialog>
#include<QMessageBox>
#include <QDir>

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
    std::cout<<"load"<<std::endl;
    QString FileName = QFileDialog::getOpenFileName(this, "Open glossary csv-file", QDir::homePath());
    QMessageBox::information(this, "..", FileName);

    /*
    model->setRootPath(QDir::currentPath());
    QTreeView *tree = new QTreeView();
    tree->setModel(model);
    tree->hideColumn(1);
    tree->hideColumn(3);
    tree->resizeColumnToContents(1);
    //setColumnWidth(0, x);
    tree->show();
    */
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

