#include "offre.h"


#include <QSqlQuery>
#include <QDebug>
#include <QObject>
offre::offre()
{
    num_offre = 0 ;
    num_fixe = 0 ;
    nom_entreprise = "";
   // adress = "";
    adressmail = "";
    etat = "";
    salaire = 0 ;
}

//Entreprise::Entreprise(int id , int num , QString nom , QString adress , QString adressmail , QDate date , QString etat  )
offre::offre(int num_offre , int num_fixe , QString nom_entreprise , QString adressmail  , QString etat , int salaire  )
{
 this ->num_offre = num_offre ;
    this ->num_fixe = num_fixe ;
    this ->nom_entreprise = nom_entreprise ;
    this ->adressmail = adressmail ;
    this ->etat = etat ;
    this->salaire = salaire;
}

int offre::getnum_offre() {return num_offre ;}
int offre::getnum_fixe () {return  num_fixe ;}
QString offre::getnom_entreprise() {return  nom_entreprise ;}
//QString offre::getadress() {return  adress ;}
QString offre::getadressmail(){return  adressmail ;}
//QDate offre::getdate(){return date;}
QString offre::getetat(){return etat ;}

void offre::setnum_offre(int id ){this->num_offre = id ; }
void offre::setnum_fixe(int num ){this ->num_fixe = num ;}
void offre::setnom_entreprise(QString nom ){this ->nom_entreprise = nom ;}
//void offre::setadress(QString adress ) {this ->adress = adress ;}
void offre::setadressmail(QString adressmail){this ->adressmail = adressmail ;}
//void offre::setdate (QDate date ){this ->date = date ; }
void offre::setetat(QString etat) {this ->etat = etat ;}


bool offre ::ajouter()
{

    QSqlQuery query;
    QString id_string = QString::number(num_offre);
    QString num_string = QString::number(num_fixe);
     QString salaire_string = QString::number(salaire);

          query.prepare("INSERT INTO  OFFRES(NUM_OFFRE,NUM_FIX,NOM_ENTREPRISE,ADRESSE_MAIL,ETAT_OFFRE,SALAIRE_ETUDIANT) " "VALUES (:NUM_OFFRE,:NUM_FIX,:NOM_ENTREPRISE,:ADRESSE_MAIL,:ETAT_OFFRE,:SALAIRE_ETUDIANT)");
          query.bindValue(":NUM_OFFRE", id_string );
          query.bindValue(":NUM_FIX", num_string );
          query.bindValue(":NOM_ENTREPRISE", nom_entreprise);
          query.bindValue(":ADRESSE_MAIL",  adressmail);
          query.bindValue(":ETAT_OFFRE",  etat);
          query.bindValue(":SALAIRE_ETUDIANT",  salaire_string);
          //query.exec();

    return  query.exec() ;
}

QSqlQueryModel* offre::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();


    model->setQuery("SELECT* FROM OFFRES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_FIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adressmail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));




    return model ;
}

bool offre::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from OFFRES where NUM_OFFRE=:id");
    query.bindValue(":id",res);
    return query.exec();
}

bool offre::modifier(int id , int NUMERO_FIX , QString NOM_ENTREPRISE , QString ADRESSE_MAIL , QString ETAT_OFFRE  , int SALAIRE_ETUDIANT)
{

    QSqlQuery query;

    QString res=QString::number(id);
    QString res1=QString::number(NUMERO_FIX);
    QString res2=QString::number(SALAIRE_ETUDIANT);
    //QString res2=QString::number(num_tel);

    query.prepare("UPDATE OFFRES SET  NUM_FIX=:NUM_FIX, NOM_ENTREPRISE=:NOM_ENTREPRISE, ADRESSE_MAIL=:ADRESSE_MAIL, ETAT_OFFRE=:ETAT_OFFRE , SALAIRE_ETUDIANT =:SALAIRE_ETUDIANT where NUM_OFFRE=:NUM_OFFRE ");
    query.bindValue(":NUM_OFFRE",res);
    query.bindValue(":NUM_FIX",res1);
    query.bindValue(":NOM_ENTREPRISE",NOM_ENTREPRISE);
    query.bindValue(":ADRESSE_MAIL",ADRESSE_MAIL);
    query.bindValue(":ETAT_OFFRE",ETAT_OFFRE);

    query.bindValue(":SALAIRE_ETUDIANT",res2);

            return    query.exec();
}


QSqlQueryModel* offre::sortid_up()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from OFFRES ORDER BY NUM_OFFRE ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_FIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adressmail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
        return model;
}

/*QSqlQueryModel* Entreprise::sortid_down()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ENTREPRISES ORDER BY ID_ENTREPRISE DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
        return model;
}*/

QSqlQueryModel* offre::sortname()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from OFFRES ORDER BY NOM_ENTREPRISE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_FIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adressmail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
        return model;
}

QSqlQueryModel* offre::sortetat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from OFFRES ORDER BY ETAT_OFFRE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_FIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adressmail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
        return model;
}

QSqlQueryModel* offre::rechercheID(int id_entreprise )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString id=QString::number(id_entreprise);
    model->setQuery("select * from deces where NUM_OFFRE like '"+id+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_FIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adressmail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
        return model;

}

QSqlQueryModel* offre::rechercheName(QString nom )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from deces where NOM_ENTREPRISE like '"+nom+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_FIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adressmail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
        return model;
}

QSqlQueryModel* offre::rechercheetat(QString adresse )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from deces where ETAT_OFFRE like '"+adresse+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_OFFRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_FIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adressmail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Salaire"));
        return model;
}

