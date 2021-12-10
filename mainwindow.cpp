#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "demande.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPushButton>
#include <QDebug>
#include"arduino.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
     ui->tableView->setModel(D.afficher());
     int ret=A.connect_arduino();
              switch(ret){
              case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
                  break;
              case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
                  break;
              case(-1):qDebug()<< "arduino is not availble";
              }
              QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString etablissement=ui->l_etablissement->text();
    QString mail=ui->le_mail->text();
    QString date_de_naissance=ui->la_date
            ->text();
    QString nom_entreprise=ui->entreprise->text();
  Demande D(id,nom,prenom,etablissement,mail,date_de_naissance,nom_entreprise);
  bool test=D.ajouter();
  QMessageBox msgBox;
  if(test){
      msgBox.setText("Bien, ajout avec succes.");
  ui->tableView->setModel(D.afficher());
  }
  else
      msgBox.setText("Erreur au niveau de l'ajout!");
      msgBox.exec();
}

void MainWindow::on_pb_del_clicked()
{
    Demande D1; D1.setid(ui->le_id_supp->text().toInt());
    bool test=D1.supprimer(D1.getid());
    QMessageBox msgBox;
    if(test) {
        msgBox.setText("Suppression avec succes.");
    ui->tableView->setModel(D.afficher());
}

    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();




}



void MainWindow::on_pb_edit_clicked()
{ QString s=ui->le_id->text();

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString etablissement=ui->l_etablissement->text();
    QString mail=ui->le_mail->text();
    QString date_de_naissance=ui->la_date->text();
    QString nom_entreprise=ui->entreprise->text();
  Demande D(id,nom,prenom,etablissement,mail,date_de_naissance,nom_entreprise);
    bool test=D.modifier();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier"),
                        QObject::tr("modifier avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

            ui->tableView->setModel(D.afficher());


        }
        else
        {QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Modifier non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}



void MainWindow::on_pb_search_clicked()
{

        QString no =ui->le_search->text();
        ui->tableView->setModel(D.rechercher(ui->le_search->text()));


}

void MainWindow::on_le_tri_clicked()
{
    ui->tableView->setModel(D.sortid_up());



}

void MainWindow::on_pushButton_4_clicked()
{

}







void MainWindow::update_label()  { //label arduino
 QString code="";

    A.data=A.read_from_arduino();
    QString DataAsString = QString(A.data);
    code=code+DataAsString;
 MainWindow W;
    int ret;
    qDebug()<< code;
    ui->le_id->setText(code);

        if(A.data=="1")
        {
            W.show();
            A.write_to_arduino("1");
            QMessageBox::information(nullptr, QObject::tr("ID trouvable."),
                                    QObject::tr("Demande affecte.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
        else {

             A.write_to_arduino("0");



             QMessageBox::critical(nullptr, QObject::tr("ID introuvable."),
                         QObject::tr("Demande non affecte.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


         }
    }


