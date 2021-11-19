#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entreprise.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit->text().toUInt();
    int num = ui->lineEdit_2->text().toUInt();
    QString nom = ui->lineEdit_3->text();
    QString adress = ui->lineEdit_4->text();
    QString adressmail = ui->lineEdit_5->text();

    Entreprises e()
}
