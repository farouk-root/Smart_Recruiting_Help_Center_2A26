#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "offre.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_num->setValidator( new QIntValidator(0, 99999999, this));
    ui->affichage->setModel(o.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Valider_clicked()
{
    int id = ui->le_id->text().toInt();
    int num = ui->le_num->text().toInt();
    int salaire = ui->le_salaire->text().toInt();
    QString nom_entreprise = ui->le_nom->text();
    QString adress = ui->le_adress->text();
    QString etat = ui->le_adressmail->text();
    //QDate date = ui->dateEdit->date();
   // Entreprise e (id , num , nom_entreprise , adress , adressmail , date , "contrat");
    offre o (id , num , nom_entreprise , adress , etat  , salaire);

    bool test = o.ajouter();

    if(test)
    {
        ui->affichage->setModel(o.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Ajout effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout non effectuée"),
                    QObject::tr("Ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->le_supprimer->text().toInt();
    bool test=o.supprimer(id);

    if(test)
    {
         ui->affichage->setModel(o.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression non effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_Modifier_clicked()
{
    bool    test;
    int id = ui->le_id_2->text().toInt();
    int num = ui->le_num_2->text().toInt();
    int salaire = ui->le_salaire_m->text().toInt();
    QString nom_entreprise = ui->le_nom_2->text();
    QString etat = ui->le_adress_2->text();
    QString adressmail = ui->le_adressmail_2->text();
     test =  o.modifier (id , num , nom_entreprise , adressmail , etat  , salaire);

          if (test)
          {
                  ui->affichage->setModel(o.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
          ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Actualiser_clicked()
{
    ui->affichage->setModel(o.afficher());
}

void MainWindow::on_Trie_botton_clicked()
{
    ui->affichage->setModel(o.sortid_up());
}

void MainWindow::on_Tri_nom_clicked()
{
    ui->affichage->setModel(o.sortname());
}

void MainWindow::on_Tri_adresse_clicked()
{
    ui->affichage->setModel(o.sortetat());
}

void MainWindow::on_rechercheID_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                   QSqlQuery   *query= new QSqlQuery();
           if(ui->rechercheID->text()==arg1)
                   {
               query->prepare("SELECT * FROM OFFRES WHERE NUM_OFFRE LIKE'"+arg1+"%'");//
       query->exec();
           model->setQuery(*query);
       ui->affichage->setModel(model);
}
}

void MainWindow::on_rechercheNom_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                   QSqlQuery   *query= new QSqlQuery();
           if(ui->rechercheNom->text()==arg1)
                   {
               query->prepare("SELECT * FROM OFFRES WHERE NOM_ENTREPRISE LIKE'"+arg1+"%'");//
       query->exec();
           model->setQuery(*query);
       ui->affichage->setModel(model);
}
}

void MainWindow::on_rechercheAdresse_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                   QSqlQuery   *query= new QSqlQuery();
           if(ui->rechercheAdresse->text()==arg1)
                   {
               query->prepare("SELECT * FROM OFFRES WHERE ETAT_OFFRE LIKE'"+arg1+"%'");//
       query->exec();
           model->setQuery(*query);
       ui->affichage->setModel(model);
}
}
