#include "entreprise.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Entreprise::Entreprise()
{
    ID_entreprise = 0 ;
    num_fixe = 0 ;
    nom_entreprise = "";
    adress = "";
    adressmail = "";
    etat = "";
}

//Entreprise::Entreprise(int id , int num , QString nom , QString adress , QString adressmail , QDate date , QString etat  )
Entreprise::Entreprise(int id , int num , QString nom , QString adress , QString adressmail  , QString etat  )
{
 this ->ID_entreprise = id ;
    this ->num_fixe = num ;
    this ->nom_entreprise = nom ;
    this ->adress = adress ;
    this ->adressmail = adressmail ;
   // this ->date = date ;
    this ->etat = etat ;
}

int Entreprise::getID_entreprise() {return ID_entreprise ;}
int Entreprise::getnum_fixe () {return  num_fixe ;}
QString Entreprise::getnom_entreprise() {return  nom_entreprise ;}
QString Entreprise::getadress() {return  adress ;}
QString Entreprise::getadressmail(){return  adressmail ;}
//QDate Entreprise::getdate(){return date;}
QString Entreprise::getetat(){return etat ;}

void Entreprise::setID_entreprise(int id ){this->ID_entreprise = id ; }
void Entreprise::setnum_fixe(int num ){this ->num_fixe = num ;}
void Entreprise::setnom_entreprise(QString nom ){this ->nom_entreprise = nom ;}
void Entreprise::setadress(QString adress ) {this ->adress = adress ;}
void Entreprise::setadressmail(QString adressmail){this ->adressmail = adressmail ;}
//void Entreprise::setdate (QDate date ){this ->date = date ; }
void Entreprise::setetat(QString etat) {this ->etat = etat ;}


bool Entreprise ::ajouter()
{

    QSqlQuery query;
    QString id_string = QString::number(ID_entreprise);
    QString num_string = QString::number(num_fixe);

          query.prepare("INSERT INTO  ENTREPRISES(ID_ENTREPRISE,NUMERO_FIX,NOM_ENTREPRISE,COLUMN3,COLUMN4,ETAT) " "VALUES (:ID_ENTREPRISE,:NUMERO_FIX,:NOM_ENTREPRISE,:COLUMN3,:COLUMN4,:ETAT)");
          query.bindValue(":ID_ENTREPRISE", id_string );
          query.bindValue(":NUMERO_FIX", num_string );
          query.bindValue(":NOM_ENTREPRISE", nom_entreprise);
          query.bindValue(":COLUMN3",  adress);
          query.bindValue(":COLUMN4",  adressmail);
          query.bindValue(":ETAT",  etat);
          //query.exec();

    return  query.exec() ;
}

QSqlQueryModel* Entreprise::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();


    model->setQuery("SELECT* FROM ENTREPRISES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));




    return model ;
}

bool Entreprise::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from ENTREPRISES where ID_ENTREPRISE=:id");
    query.bindValue(":id",res);
    return query.exec();
}

bool Entreprise::modifier(int id , int NUMERO_FIX , QString NOM_ENTREPRISE , QString COLUMN3 , QString COLUMN4  , QString ETAT)
{

    QSqlQuery query;

    QString res=QString::number(id);
    QString res1=QString::number(NUMERO_FIX);
    //QString res2=QString::number(num_tel);

    query.prepare("UPDATE ENTREPRISES SET  NUMERO_FIX=:NUMERO_FIX, NOM_ENTREPRISE=:NOM_ENTREPRISE, COLUMN3=:COLUMN3, COLUMN4=:COLUMN4 , ETAT =:ETAT where ID_ENTREPRISE=:ID_ENTREPRISE ");
    query.bindValue(":ID_ENTREPRISE",res);
    query.bindValue(":NUMERO_FIX",res1);
    query.bindValue(":NOM_ENTREPRISE",NOM_ENTREPRISE);
    query.bindValue(":COLUMN3",COLUMN3);
    query.bindValue(":COLUMN4",COLUMN4);

    query.bindValue(":ETAT",ETAT);

            return    query.exec();
}


QSqlQueryModel* Entreprise::sortid_up()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ENTREPRISES ORDER BY ID_ENTREPRISE ASC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
        return model;
}

QSqlQueryModel* Entreprise::sortid_down()
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
}

QSqlQueryModel* Entreprise::sortname()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ENTREPRISES ORDER BY NOM_ENTREPRISE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
        return model;
}

QSqlQueryModel* Entreprise::sortadress()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ENTREPRISES ORDER BY COLUMN3");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
        return model;
}

QSqlQueryModel* Entreprise::rechercheID(int id_entreprise )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString id=QString::number(id_entreprise);
    model->setQuery("select * from deces where ID_ENTREPRISE like '"+id+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
        return model;

}

QSqlQueryModel* Entreprise::rechercheName(QString nom )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from deces where NOM_ENTREPRISE like '"+nom+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
        return model;
}

QSqlQueryModel* Entreprise::rechercheAdresse(QString adresse )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from deces where COLUMN3 like '"+adresse+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_entreprise"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero fixe "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom entreprise "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adressmail"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
        return model;
}
