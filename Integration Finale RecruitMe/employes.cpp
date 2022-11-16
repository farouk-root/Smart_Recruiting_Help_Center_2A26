#include "employes.h"
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
#include <list>
employes::employes()
{
    id=0;
    cin=0;
    nom="";
    prenom="";

    ddn="";
    salaire=0;



}
employes::employes(int id,QString nom,QString prenom,int cin,QString ddn,float salaire){

    this->id=id;

    this->nom=nom;
    this->prenom=prenom;
       this->cin=cin;
    this->ddn=ddn;
    this->salaire=salaire;




}
int employes::getid(){ return id; }

QString employes::getnom(){return nom;}
QString employes::getprenom(){return prenom;}
int employes::getcin(){return cin;}


QString employes::getddn(){ return ddn; }
float employes::getsalaire(){return salaire;}


void employes::setid(int id){this->id=id;}
void employes::setnom(QString nom){this->nom=nom;}
void employes::setprenom(QString prenom){this->prenom=prenom;}
void employes::setcin(int cin){this->cin=cin;}
void employes::setddn(QString ddn){this->ddn=ddn;}
void employes::setsalaire(float salaire){this->salaire=salaire;}


bool employes::ajouter()
{
    QSqlQuery query;

          QString id_string = QString::number(id);
          QString salaire_string = QString::number(salaire);
          QString cin_string = QString::number(cin);
          query.prepare("INSERT INTO employes (id, nom, prenom, cin, ddn, salaire) "
                        "VALUES (:id, :nom, :prenom, :cin, :ddn, :salaire)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":cin", cin_string);
          query.bindValue(":ddn", ddn);
          query.bindValue(":salaire", salaire_string);


          return query.exec();

}

 QSqlQueryModel * employes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM EMPLOYES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));


    return model;
}

 bool employes::modifier(int id,QString nom,QString prenom,int cin,QString ddn,float salaire)
 {
     QSqlQuery query;
     QString id_string = QString::number(id);
     QString salaire_string = QString::number(salaire);
     QString cin_string = QString::number(cin);
     query.prepare("UPDATE employes SET id=:id, nom=:nom, prenom=:prenom, cin=:cin, ddn=:ddn, salaire=:salaire WHERE id=:id");

     query.bindValue(":id",id_string);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":cin",cin_string);
     query.bindValue(":ddn",ddn);
     query.bindValue(":salaire",salaire_string);

     return query.exec();
 }

 bool employes::supprime()
 {
     QSqlQuery query;
          query.prepare("delete from employes where id=:id");
          query.bindValue(0, id);
       return query.exec();
 }
 bool employes::controle_saisie(){

        QString cin_string = QString::number(cin);
        if (cin_string.length()==8)
            return true;
        else
            return false;
 }
bool employes::controle_saisie_champ()
 {
    //QString salaire_string=QString::number(salaire);
    QString b;
    b.setNum(salaire);
           QString cin_string = QString::number(cin);
          QString id_string=QString::number(id);
     if((prenom=="")||(nom=="")||(b==""))
         return  false;
     else
         return true;
 }

bool employes::verifnom(QString n)
{
    for(int i=0;i<n.length();i++)
    {
        if((n[i]<'a' && n[i]<'z') && (n[i]<'A' && n[i]<'Z' ) )
            return false;

    }

    return true;



}
QSqlQueryModel * employes::rechercherCin (const QString &aux)

{


    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from employes WHERE(cin='"+aux+"' )");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}




QSqlQueryModel * employes::rechercherid (const QString &aux)

{


    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from employes WHERE(id='"+aux+"' )");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}


QSqlQueryModel * employes::rechercherP (const QString &aux)

{


    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from employes WHERE(prenom='"+aux+"' )");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ddn"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}




QSqlQueryModel *  employes::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from employes order by prenom");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ddn"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}

QSqlQueryModel *  employes::trid()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from employes order by id");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ddn"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}

QSqlQueryModel *  employes::tric()
{
    QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from employes order by cin");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal,  QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ddn"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}




QSqlQueryModel * employes::rechercher1(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employes WHERE (id LIKE '%"+a+"%' OR nom LIKE '%"+a+"%' OR prenom LIKE '%"+a+"%' OR cin LIKE '%"+a+"%' OR ddn LIKE '%"+a+"%' OR salaire LIKE '%"+a+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("ddn"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaire"));

    return model;
}
