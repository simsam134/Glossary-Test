#include "dialog.h"
#include "mainwindow.h"
#include "ui_dialog.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include<QPushButton>
#include <QFile>
#include <ctime>

//class MainWindow;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    corr(4, false),
    ui(new Ui::Dialog),
    Count(0)
{
    MainWindow* par = qobject_cast<MainWindow*>(this->parent());
    pwords = &par->words;
    NbrQ = pwords->size();
    ui->setupUi(this);
    buttons = {ui->alt1, ui->alt2, ui->alt3, ui->alt4};
    setQuestion();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setQuestion(){
    ui->NextQuestionButton->setVisible(false);
    int correct = rand() % 4;
    ui->word->setText((*pwords)[Count][0]);
    srand((unsigned) time(0));
    for (int i = 0 ; i<4 ; i++){
        buttons[i]->setStyleSheet("background-color: rgb(85, 170, 255)");
        if(i==correct){
            corr[i]=true;
            buttons[correct]->setText((*pwords)[Count][1] );
        }else{
            corr[i]=false;

            int rndNbr =rand() % (NbrQ);
            buttons[i]->setText((*pwords)[rndNbr][1]);
        }
    }
    ++Count;
}

void Dialog::DispAnswer(){
    for (int i{0}; i<4; i++){
        if(corr[i]){
            buttons[i]->setStyleSheet("background-color: green");
        }else{
            buttons[i]->setStyleSheet("background-color: red");
        }
        ui->NextQuestionButton->setVisible(true);
    }
}

void Dialog::on_alt1_clicked()
{
    DispAnswer();
}

void Dialog::on_alt2_clicked()
{
    DispAnswer();
}



void Dialog::on_alt3_clicked()
{
    DispAnswer();
}


void Dialog::on_alt4_clicked()
{
    DispAnswer();
}



void Dialog::on_NextQuestionButton_clicked()
{
    setQuestion();
}

