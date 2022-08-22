#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>


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

    model->setRootPath(QDir::currentPath());
    QTreeView *tree = new QTreeView();
    tree->setModel(model);
    tree->hideColumn(1);
    tree->hideColumn(3);
    //setColumnWidth(0, x);
    tree->show();
}


void MainWindow::on_pushButtonStart_clicked()
{
    std::cout<<"Start"<<std::endl;
}

