#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileSystemModel>
#include <QTreeView>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<std::vector<QString>> words;

private slots:
    void on_pushButtonQuit_clicked();
    void on_pushButtonLoad_clicked();
    void on_pushButtonStart_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *game;
};
#endif // MAINWINDOW_H
