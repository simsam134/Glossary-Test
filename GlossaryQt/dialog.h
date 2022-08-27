#ifndef DIALOG_H
#define DIALOG_H

#include "qlabel.h"
#include <QDialog>



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
    std::vector<bool> corr;
    std::vector<std::vector<QString>> words;
    void setQuestion();
    void DispAnswer();
    void LoadQuestions();

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

};

#endif // DIALOG_H
