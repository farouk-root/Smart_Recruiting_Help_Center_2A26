#ifndef EMPLOYES_H
#define EMPLOYES_H

#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
class employes
{

public:
    employes();
    employes(int id,QString nom,QString prenom,int cin,QString ddn,float salaire);
     int getid();
     void setid(int);

     QString getnom();
     void setnom(QString);

     QString getprenom();
     void setprenom(QString);

     int getcin();
     void setcin(int);

    QString getddn();
    void setddn(QString);

   float getsalaire();
   void setsalaire(float);


QSqlQueryModel * rechercher1(QString a);


      bool ajouter();

      QSqlQueryModel * afficher();
      bool modifier(int,QString,QString,int,QString,float);
      bool supprime();
      bool controle_saisie();
      bool controle_saisie_champ();
      bool verifnom(QString n);
      QSqlQueryModel * rechercher (const QString &aux);
      QSqlQueryModel * rechercherP (const QString &aux);
      QSqlQueryModel * rechercherid (const QString &aux);
      QSqlQueryModel * rechercherCin (const QString &aux);
      QSqlQueryModel * tri();
      QSqlQueryModel * tric();
       QSqlQueryModel * trid();

private :
   int id;
   QString nom ;
   QString prenom;

   QString ddn;
   int salaire; //kent float
   int cin;
};


/*namespace ui {


class email : public QDialog
   {
       Q_OBJECT

   public:
       explicit email(QWidget *parent = nullptr);
       ~email();
   private slots:
       void sendMail();
       void mailSent(QString);
   private:
       Ui::email *ui;
};
}*/


#endif // EMPLOYES_H
