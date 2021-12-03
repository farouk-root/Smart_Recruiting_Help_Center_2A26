#ifndef DEMANDE_H
#define DEMANDE_H


#include <QString>
#include <QSqlQueryModel>


class Demande
{
public:
    Demande();
    Demande(int,QString,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getnom_entreprise();
    QString getetablissement();
    QString getmail();
    QString getdate_naissance();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setnom_entreprise(QString);
    void setetablissement(QString);
    void setmail(QString);
    void setdate_naissance(QString);
    bool ajouter();

     QSqlQueryModel* afficher();
     QSqlQueryModel *sortid_up();
     QSqlQueryModel *rechercher (const QString &aux);
     QSqlQueryModel *sortdate_naissance_up();

bool supprimer(int);
bool modifier ();
bool tri();

private:
    int id;
   QString nom, prenom;
   QString nom_entreprise;
   QString etablissement;
   QString mail;
   QString date_naissance;
};


#endif // DEMANDE_H
