#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include "smtpp.h"
#include "smtp.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintQR(QPainter &painter, const QSize sz, const QString &data, QColor fg);
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

    void on_Tcin_clicked();

    void on_Tprenom_clicked();

    void on_PDF_clicked();
    //void  MainWindow::browse();

   QString on_tableView_clicked( const QModelIndex &index);

   void on_pushButton_clicked();

   void on_id_textEdited(const QString &arg1);

   void on_id_textChanged(const QString &arg1);

   void on_cin_textEdited(const QString &arg1);

   void on_Mid_textEdited(const QString &arg1);

   void on_Mnom_textEdited(const QString &arg1);

   void on_nom_textEdited(const QString &arg1);

   void on_pushButton_2_clicked();

   void on_tableView_activated(const QModelIndex &index);

   void on_pushButton_3_clicked();

   void on_lineEdit_2_textEdited(const QString &arg1);

   void on_pushButton_4_clicked();


   void sendMail(QString email);
       void mailSent(QString);
       void sendMaile();
       void mailSente(QString);

       void on_sendBtn_clicked();

       void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
