#include "dialog.h"
#include "ui_dialog.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include<QPushButton>
#include <QFile>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    corr(4, false),
    words(0),
    ui(new Ui::Dialog),
    Count(0)
{
    ui->setupUi(this);
//    words={"HardWord", "EasyWord", "MediumWord"};
    LoadQuestions();
    buttons = {ui->alt1, ui->alt2, ui->alt3, ui->alt4};
    setQuestion();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::LoadQuestions(){
    std::string fname = "ord.csv";
    std::fstream file(fname, std::ios::in);
    std::string line,word, answer;
    QString Qword;
    std::stringstream str;

    if(QFile::exists("ord.csv")){
        std::cout<<"Exists!!\n"<<std::endl;
    }
    if ( file.is_open() ){
        while(getline(file, line)){
            std::vector<QString> v;
            str<<line;
            str>>word;
            Qword=QString::fromStdString(word);

            v.push_back(Qword);
            getline(str, answer);
            Qword=QString::fromStdString(answer);
            v.push_back(Qword);
            words.push_back(v);

        }
    }else{
        std::cout<<"no file open?"<<std::endl;
    }


}
void Dialog::setQuestion(){
    ui->NextQuestionButton->setVisible(false);
    int correct = rand() % 4;
    std::fill(corr.begin(), corr.end(), false);
    for (int i = 0 ; i<4 ; i++){
        buttons[i]->setStyleSheet("background-color: rgb(85, 170, 255)");
    }
//    buttons[correct]->setText(words[Count]);
    corr[correct] = true;
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

