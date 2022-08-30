#ifndef DIALOG_H
#define DIALOG_H

#include "qlabel.h"
#include <QDialog>
#include<QMainWindow>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
//    std::vector<QString> words;

    std::vector<QPushButton *> buttons;
    std::vector<std::vector<QString>> *pwords;
    std::vector<bool> corr;
    int NbrQ;
    int NbrCorr;
    void setQuestion();
    void DispAnswer();

private slots:
    void on_alt1_clicked();
    void on_alt2_clicked();
    void on_alt3_clicked();
    void on_alt4_clicked();

    void on_NextQuestionButton_clicked();

private:
    Ui::Dialog *ui;
    int Count;
    void NextQuestion();
    void updateCount(const bool c);


};

#endif // DIALOG_H
