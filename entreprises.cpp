#include "entreprises.h"

Entreprises::Entreprises()
{
    ID_entreprise = 0 ;
    num_fixe = 0 ;
    nom_entreprise = "";
    adress = "";
    adressmail = "";
    etat = "";
}

Entreprises::Entreprises(int id , int num , QString nom , QString adress , QString adressmail , QDate date , QString etat )
{
 this ->ID_entreprise = id ;
    this ->num_fixe = num ;
    this ->nom_entreprise = nom ;
    this ->adress = adress ;
    this ->adressmail = adressmail ;
    this ->date = date ;
    this ->etat = etat ;
}

int Entreprises::getID_entreprise() {return ID_entreprise ;}
int Entreprises::getnum_fixe () {return  num_fixe ;}
QString Entreprises::getnom_entreprise() {return  nom_entreprise ;}
QString Entreprises::getadress() {return  adress ;}
QString Entreprises::getadressmail(){return  adressmail ;}
QDate Entreprises::getdate(){return date;}
QString Entreprises::getetat(){return etat ;}

void Entreprises::setID_entreprise(int id ){this->ID_entreprise = id ; }
void Entreprises::setnum_fixe(int num ){this ->num_fixe = num ;}
void Entreprises::setnom_entreprise(QString nom ){this ->nom_entreprise = nom ;}
void Entreprises::setadress(QString adress ) {this ->adress = adress ;}
void Entreprises::setadressmail(QString adressmail){this ->adressmail = adressmail ;}
void Entreprises::setdate (QDate date ){this ->date = date ; }
void Entreprises::setetat(QString etat) {this ->etat = etat ;}
