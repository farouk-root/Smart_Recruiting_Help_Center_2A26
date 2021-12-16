#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include "smtpp.h"
#include "smtp.h"
#include "entreprise.h"
#include "offre.h"
#include "demande.h"



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

   void on_Valider_mod_farouk_clicked();

   void on_Trie_botton_clicked();

   void on_Tri_nom_clicked();

   void on_Tri_adresse_clicked();

   void on_rechercheID_textChanged(const QString &arg1);

   void on_rechercheNom_textChanged(const QString &arg1);

   void on_rechercheAdresse_textChanged(const QString &arg1);



   void sendMail(QString email);
       void mailSent(QString);
       void sendMaile();
       void mailSente(QString);

       void on_sendBtn_clicked();

       void on_exitBtn_clicked();

       void on_Module_employe_clicked();

       void on_pushButton_6_clicked();

       void on_Module_entreprise_clicked();

       void on_affichage_clicked(const QModelIndex &index);

       void on_affichage_activated(const QModelIndex &index);

       void on_Farouk_return_clicked();

       void on_Ajouter_farouk_clicked();

       void on_supprimer_farouk_clicked();

       void on_Modifier_farouk_clicked();

       void on_Modifier_farouk_2_clicked();



       void on_Email_farouk_clicked();

       void on_Map_farouk_clicked();

       void on_Module_offre_clicked();

       void on_Ajouter_dhia_clicked();

       void on_Valider_ajout_offre_clicked();

       void on_pushButton_8_clicked();

       void on_supprimer_offrre_clicked();

       void on_Modifier_dhia_clicked();

       void on_Modifier_offre_clicked();

       void on_return_dhia_clicked();

       void on_Actualiser_dhia_clicked();

       void on_Trie_ID_dhia_clicked();

       void on_Tri_nom_dhia_clicked();

       void on_Tri_adresse_dhia_clicked();

       void on_rechercheID_dhia_textChanged(const QString &arg1);

       void on_rechercheNom_dhia_textChanged(const QString &arg1);

       void on_rechercheAdresse_dhia_textChanged(const QString &arg1);

       void on_Affecter_dhia_clicked();

       void on_affectation_clicked();

       void on_valider_points_clicked();

       void on_Points_dhia_clicked();

       void on_nettoyer_clicked();

       void on_ajouter_manef_clicked();
       void on_le_tri_clicked();
       void on_pb_edit_clicked();
       void on_pb_search_clicked();
       void on_pb_del_clicked();


       void on_Module_demande_clicked();

       void on_pb_search_2_clicked();

       void on_pb_edit_2_clicked();

       void on_le_tri_2_clicked();

private:
    Ui::MainWindow *ui;
    Entreprise e;
    offre o ;
    Demande D;
};
#endif // MAINWINDOW_H
