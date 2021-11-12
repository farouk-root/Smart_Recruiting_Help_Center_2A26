#ifndef EMPLOYES_H
#define EMPLOYES_H

#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
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





      bool ajouter();

      QSqlQueryModel * afficher();
      bool modifier(int,QString,QString,int,QString,float);
      bool supprime(int);
      bool controle_saisie();
      bool controle_saisie_champ(employes e);
      bool verifnom(QString n);

private :
   int id;
   QString nom ;
   QString prenom;

   QString ddn;
   float salaire;
   int cin;


};

#endif // EMPLOYES_H
