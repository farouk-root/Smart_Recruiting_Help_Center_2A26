#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entreprise.h"
#include "smtpp.h"
#include "smtp.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Valider_clicked();

    void on_pushButton_clicked();

    void on_tab_entreprise_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Modifier_clicked();

    void on_comboBox_trie_currentTextChanged(const QString &arg1);

    void on_Trie_botton_clicked();

    void on_Tri_nom_clicked();

    void on_Tri_adresse_clicked();

    void on_rechercheID_textChanged(const QString &arg1);

    void on_rechercheNom_textChanged(const QString &arg1);

    void on_rechercheAdresse_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();




        void sendMail(QString email);
        void mailSent(QString);
        void sendMaile();
        void mailSente(QString);

        void on_sendBtn_clicked();

        void on_exitBtn_clicked();

        void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Entreprise e;
};

#endif // MAINWINDOW_H
