#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"


#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QTextStream>
#include <QComboBox>
#include <QTabWidget>
#include"QDate"
#include <QDebug>
#include <list>


#include <QTextBrowser>
#include<QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    employes e;
    ui->tableView->setModel(e.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_valider_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
       int id = ui->id->text().toInt();
       QString nom = ui->nom->text();
       QString prenom = ui->prenom->text();
       int cin = ui->cin->text().toInt();
       QString ddn = ui->ddn->text();
      float salaire = ui->salaire->text().toInt(); //toFloat
       employes e(id,nom,prenom,cin,ddn,salaire) ;
bool controle=e.controle_saisie();
bool control=e.controle_saisie_champ(e);

bool controln=e.verifnom(nom);
bool controlp=e.verifnom(prenom);

  bool test;
if( (controle==false) ||(control==false) || (controlp==false) || (controln==false) ) {
    QMessageBox::information(nullptr, QObject::tr(""),
                             QObject::tr("Cin doit etre 8 chiffres \n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }

else{
test=e.ajouter();
if(test)
{

        QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                                 QObject::tr("employe ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableView->setModel(e.afficher());

    }
    else {



        QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
ui->id->setText("");
ui->nom->setText("");
ui->prenom->setText("");
ui->cin->setText("");

ui->salaire->setText("");
}









void MainWindow::on_pushButton_5_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT id from employes");
             query->exec();
             model->setQuery(*query);
             ui->comboBox->setModel(model);

}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

    QString id=arg1;
     QSqlQueryModel *model= new QSqlQueryModel();
         QSqlQuery   *query= new QSqlQuery();
         query->prepare("SELECT * from employes where id='"+id+"'");
         if(query->exec())
         {
             while (query->next())
             {
                 QString date_string_on_db =query->value(4).toString();
                                 QDate Date = QDate::fromString(date_string_on_db,"dd/MM/yyyy");
                 ui->Mid->setText(query->value(0).toString());
                 ui->Mnom->setText(query->value(1).toString());
                 ui->Mprenom->setText(query->value(2).toString());
                 ui->Mcin->setText(query->value(3).toString());
                  ui->Mddn->setDate(Date);
                   ui->Msalaire->setText(query->value(5).toString());

             }
         }
         model->setQuery(*query);
}



void MainWindow::on_pushButton_7_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT id from employes");
             query->exec();
             model->setQuery(*query);
             ui->comboBox_2->setModel(model);
}

void MainWindow::on_supprimer_2_clicked()
{
    employes e;
            e.setid(ui->comboBox_2->currentText().toInt());

            bool test;
            test=e.supprime();
            if(test)
            { ui->tableView->setModel(e.afficher());
                QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                           QObject::tr("sup successful.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
            }
                           else
                               QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                           QObject::tr("sup failed.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_Valider_2_clicked()
{
    employes e;
            e.setid(ui->Mid->text().toInt());
            e.setnom(ui->Mnom->text());
            e.setprenom(ui->Mprenom->text());
            e.setcin(ui->Mcin->text().toInt());
            e.setddn(ui->Mddn->text());
            e.setsalaire(ui->Msalaire->text().toFloat());
            bool test=e.modifier(e.getid(),e.getnom(),e.getprenom(),e.getcin(),e.getddn(),e.getsalaire());
            bool controle=e.controle_saisie();
            bool control=e.controle_saisie_champ(e);

            bool controln=e.verifnom(e.getnom());
            bool controlp=e.verifnom(e.getprenom());
            if((controle==false)||(control==false) || (controln==false) || ( controlp==false))
            { QMessageBox::information(nullptr, QObject::tr("cin doit etre 8 chiffres"),
                                      QObject::tr("ou un champs manquant.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel); }
            else {
          if(test)
           {  ui->tableView->setModel(e.afficher());
              QMessageBox::information(nullptr, QObject::tr("modifier avec succes"),
                                         QObject::tr("update successful.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

                     }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("modifier errer"),
                                         QObject::tr("update failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

}
}




void MainWindow::on_Ccin_clicked()
{
    employes e;
    QString A=ui->lineEdit->text();
    ui->tableView->setModel(e.rechercherCin(A));

    if(A=="")
            ui->tableView->setModel(e.afficher());
}




void MainWindow::on_Tid_clicked()
{
    //QString y;
    employes e;
    //y="";

  ui->tableView->setModel(e.tri());
}

void MainWindow::on_Cid_clicked()
{
    employes e;
    QString A=ui->lineEdit->text();
    ui->tableView->setModel(e.rechercherid(A));
}



void MainWindow::on_Cprenom_clicked()
{
    employes e;
    QString A=ui->lineEdit->text();
    ui->tableView->setModel(e.rechercherP(A));

}

void MainWindow::on_actualiser_clicked()
{
    employes e;
    ui->tableView->setModel(e.afficher());
}


void MainWindow::on_Tcin_clicked()
{
    //QString y;
    employes e;
    //y="";

  ui->tableView->setModel(e.tric());
}




void MainWindow::on_Tprenom_clicked()
{

        //QString y;
        employes e;
        //y="";

      ui->tableView->setModel(e.trid());

}
