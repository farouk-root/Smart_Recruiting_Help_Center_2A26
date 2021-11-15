#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:


    void on_ajouter_clicked();

    void on_valider_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);



    void on_pushButton_7_clicked();

    void on_supprimer_2_clicked();





    void on_Valider_2_clicked();







    void on_Ccin_clicked();

    void on_Tid_clicked();




    void on_Cid_clicked();

    void on_Cprenom_clicked();

    void on_actualiser_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
