#ifndef OFFRE_H
#define OFFRE_H


#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>

class offre
{
public:
    offre();

    offre(int , int , QString , QString   , QString , int );
    int getnum_offre() ;
    int getnum_fixe () ;
    QString getnom_entreprise();
   // QString getadress();
    QString getadressmail();
    //QDate getdate();
    QString getetat();
    int getsalaire();

    void setnum_offre(int);
    void setnum_fixe(int);
    void setnom_entreprise(QString);
   // void setadress(QString);
    void setadressmail(QString);
    //void setdate (QDate );
    void setetat(QString);
    void setsalaire(int);

    bool ajouter();

    QSqlQueryModel* afficher();

    bool supprimer (int);
    bool modifier(int , int , QString , QString , QString  , int);

    QSqlQueryModel* sortid_up();
    //QSqlQueryModel* sortid_down();

    QSqlQueryModel* sortname();
    //QSqlQueryModel* sortname_down();

    QSqlQueryModel* sortetat();
    //QSqlQueryModel* sortadress_down();

    QSqlQueryModel* rechercheID(int id_entreprise );
    QSqlQueryModel* rechercheName(QString nom );
        QSqlQueryModel* rechercheetat(QString adresse );

        bool affecter (int , int );
        bool points (int , int );


private:
    int num_offre ;
    int num_fixe ;
    QString nom_entreprise  , adressmail ;
    //QDate date ;
    QString etat ;
    int salaire;



};

#endif // OFFRE_H
