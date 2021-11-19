#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Entreprise
{
public:
    Entreprise();
    //Entreprise(int , int , QString , QString , QString , QDate  , QString );
    Entreprise(int , int , QString , QString , QString  , QString );
    int getID_entreprise() ;
    int getnum_fixe () ;
    QString getnom_entreprise();
    QString getadress();
    QString getadressmail();
    //QDate getdate();
    QString getetat();

    void setID_entreprise(int);
    void setnum_fixe(int);
    void setnom_entreprise(QString);
    void setadress(QString);
    void setadressmail(QString);
    //void setdate (QDate );
    void setetat(QString);

    bool ajouter();

    QSqlQueryModel* afficher();

    bool supprimer (int);
    bool modifier(int , int , QString , QString , QString  , QString);

    QSqlQueryModel* sortid_up();
    QSqlQueryModel* sortid_down();

    QSqlQueryModel* sortname();
    //QSqlQueryModel* sortname_down();

    QSqlQueryModel* sortadress();
    //QSqlQueryModel* sortadress_down();

    QSqlQueryModel* rechercheID(int id_entreprise );
    QSqlQueryModel* rechercheName(QString nom );
        QSqlQueryModel* rechercheAdresse(QString adresse );



private:
    int ID_entreprise ;
    int num_fixe ;
    QString nom_entreprise , adress , adressmail ;
    //QDate date ;
    QString etat ;



};

#endif // Entreprise_H

