#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entreprise.h"
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
    ui->affichage->setModel(e.afficher());

   /* ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Valider_clicked()
{
    int id = ui->le_id->text().toInt();
    int num = ui->le_num->text().toInt();
    QString nom_entreprise = ui->le_nom->text();
    QString adress = ui->le_adress->text();
    QString adressmail = ui->le_adressmail->text();
    //QDate date = ui->dateEdit->date();
   // Entreprise e (id , num , nom_entreprise , adress , adressmail , date , "contrat");
    Entreprise e (id , num , nom_entreprise , adress , adressmail  , "contrat");


    bool test = e.ajouter();

    if(test)
    {
        ui->affichage->setModel(e.afficher());
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
    bool test=e.supprimer(id);

    if(test)
    {
         ui->affichage->setModel(e.afficher());
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
    QString nom_entreprise = ui->le_nom_2->text();
    QString adress = ui->le_adress_2->text();
    QString adressmail = ui->le_adressmail_2->text();
     test =  e.modifier (id , num , nom_entreprise , adress , adressmail  , "contrat");

          if (test)
          {
                  ui->affichage->setModel(e.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
          ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_Trie_botton_clicked()
{
    ui->affichage->setModel(e.sortid_down());
}

void MainWindow::on_Tri_nom_clicked()
{
    ui->affichage->setModel(e.sortname());
}

void MainWindow::on_Tri_adresse_clicked()
{
    ui->affichage->setModel(e.sortadress());
}

void MainWindow::on_rechercheID_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
                   QSqlQuery   *query= new QSqlQuery();
           if(ui->rechercheID->text()==arg1)
                   {
               query->prepare("SELECT * FROM ENTREPRISES WHERE ID_ENTREPRISE LIKE'"+arg1+"%'");//
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
               query->prepare("SELECT * FROM ENTREPRISES WHERE NOM_ENTREPRISE LIKE'"+arg1+"%'");//
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
               query->prepare("SELECT * FROM ENTREPRISES WHERE COLUMN3 LIKE'"+arg1+"%'");//
       query->exec();
           model->setQuery(*query);
       ui->affichage->setModel(model);
}
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::sendMaile()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSente(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_sendBtn_clicked()
{
    sendMaile();
}

/*void MainWindow::on_sendBtn_clicked()
{
    sendMaile();
}*/

void MainWindow::on_exitBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
}
