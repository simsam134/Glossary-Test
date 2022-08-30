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
#include<string>

//class MainWindow;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    corr(4, false),
    NbrCorr(0),
    ui(new Ui::Dialog),
    Count(0)
{
    MainWindow* par = qobject_cast<MainWindow*>(this->parent());
    pwords = &par->words;
    NbrQ = pwords->size();
    ui->setupUi(this);
    buttons = {ui->alt1, ui->alt2, ui->alt3, ui->alt4};
    setQuestion();
    QString tmp = "1/";
    tmp=tmp + QString::number(NbrQ);
    ui->NbrQT->setText(tmp);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setQuestion(){
    ui->NextQuestionButton->setVisible(false);
    ui->gz->setVisible(false);

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

void Dialog::updateCount(bool const c){
    if (c){
        ui->NbrCorr->setText(QString::number(++NbrCorr));
        ui->gz->setText("Correct! Congratulations!");
        ui->gz->setStyleSheet("color: green");
        ui->gz->setVisible(true);
    }else{
        ui->gz->setText("Wrong Answer!");
        ui->gz->setStyleSheet("color: red");
        ui->gz->setVisible(true);
    }
    QString tmp;
    QString slash = "/";
    tmp = QString::number(Count) +slash+ QString::number(NbrQ);
    ui->NbrQT->setText(tmp);


}
void Dialog::on_alt1_clicked()
{
    if(corr[0]){updateCount(true);}
    else{updateCount(false);}
    DispAnswer();
}

void Dialog::on_alt2_clicked()
{
    if(corr[1]){updateCount(true);}
    else{updateCount(false);}
    DispAnswer();
}



void Dialog::on_alt3_clicked()
{
    if(corr[2]){updateCount(true);}
    else{updateCount(false);}
    DispAnswer();
}


void Dialog::on_alt4_clicked()
{
    if(corr[3]){updateCount(true);}
    else{updateCount(false);}
    DispAnswer();
}



void Dialog::on_NextQuestionButton_clicked()
{
    setQuestion();
}

