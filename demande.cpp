#include "demande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Demande::Demande()
{
id=0; nom=" "; prenom=" "; nom_entreprise=" "; mail=" "; date_naissance=" " ; etablissement=" ";
}
Demande::Demande(int id,QString nom,QString prenom,QString nom_entreprise,QString mail,QString date_naissance ,QString etablissement)
{this->id=id; this->nom=nom; this->prenom=prenom; this->nom_entreprise=nom_entreprise; this->etablissement=etablissement; this->mail=mail; this->date_naissance=date_naissance; }
int Demande::getid(){return id;}
QString Demande::getnom(){return nom;}
QString Demande::getprenom(){return prenom;}
QString Demande::getnom_entreprise(){return nom_entreprise;}
QString Demande::getetablissement(){return etablissement;}
QString Demande::getmail(){return mail;}
QString Demande::getdate_naissance(){return date_naissance;}
void Demande::setid(int id){this->id=id;}
void Demande::setnom(QString nom){this->nom=nom;}
void Demande::setprenom(QString prenom){this->prenom=prenom;}
void Demande::setnom_entreprise(QString nom_entreprise){this->nom_entreprise=nom_entreprise;}
void Demande::setetablissement(QString etablissement){this->etablissement=etablissement;}
void Demande::setmail(QString mail){this->mail=mail;}
void Demande::setdate_naissance(QString date_naissance){this->date_naissance=date_naissance;}
bool Demande::ajouter()
{
   QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO DEMANDES (COLUMN1 , NOM, PRENOM, NOM_ENTREPRISE, ADRESSE_MAIL, DATE_DE_NAISSANCE) "
                        "VALUES (:0, :1, :2, :3, :4 , :5)");
          query.bindValue(0, id_string);
          query.bindValue(1,nom);
          query.bindValue(2,prenom);
          query.bindValue(3,nom_entreprise);
          query.bindValue(4,mail);
          query.bindValue(5,date_naissance);


          return query.exec();



          query.prepare("INSERT INTO ENTREPRISE (ID_ENTREPRISE)""VALUES(:6)");
          query.bindValue(6,etablissement);

          return query.exec();
}

bool Demande::supprimer(int id)
{
    QSqlQuery query;

           query.prepare("Delete from DEMANDES where COLUMN1=:0" );

           query.bindValue(":0", id);

           return query.exec();


}

QSqlQueryModel* Demande::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM DEMANDES ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etablissement"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mail"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de naissance"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID de l'entreprise"));





    return model;
}

bool Demande::modifier()
{
    QString ids =  QString::number(id);




       QSqlQuery query;
       query.prepare("UPDATE  DEMANDES SET  COLUMN1=:id, NOM=:nom, PRENOM=:prenom, NOM_ENTREPRISE=:nom_entreprise, ADRESSE_MAIL=:mail, DATE_DE_NAISSANCE=:date_naissance,ID_ENTREPRISE = :etablissement WHERE COLUMN1=:id");
        query.bindValue(":id", ids);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":nom_entreprise", nom_entreprise);
        query.bindValue(":mail", mail);
        query.bindValue(":date_naissance", date_naissance);
        query.bindValue(":etablissement",etablissement);



        return  query.exec();
}
QSqlQueryModel *Demande::sortid_up()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from DEMANDES ORDER BY COLUMN1 ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etablissement"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID de l'entreprise "));
    return model;

}
QSqlQueryModel * Demande::rechercher (const QString &aux)

{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from DEMANDES where ((COLUMN1) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etablissement"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID de l'entreprise"));


    return model;
}

QSqlQueryModel * Demande::sortdate_naissance_up()
{
   QSqlQueryModel * model = new QSqlQueryModel();
   model->setQuery("select * from DEMANDES ORDER BY DATE_DE_NAISSANCE ASC ");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("Etablissement"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("Mail"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date de naissance"));
   model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID de l'entreprise "));
   return model;




}

