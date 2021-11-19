#ifndef ENTREPRISES_H
#define ENTREPRISES_H

#include <QString>
#include <QDate>
class Entreprises
{
public:
    Entreprises();
    Entreprises(int , int , QString , QString , QString , QDate , QString  );
    int getID_entreprise() ;
    int getnum_fixe () ;
    QString getnom_entreprise();
    QString getadress();
    QString getadressmail();
    QDate getdate();
    QString getetat();

    void setID_entreprise(int);
    void setnum_fixe(int);
    void setnom_entreprise(QString);
    void setadress(QString);
    void setadressmail(QString);
    void setdate (QDate );
    void setetat(QString);


private:
    int ID_entreprise ;
    int num_fixe ;
    QString nom_entreprise , adress , adressmail ;
    QDate date ;
    QString etat ;



};

#endif // ENTREPRISES_H
