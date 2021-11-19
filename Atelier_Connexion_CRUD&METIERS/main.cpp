#include "mainwindow.h"
#include <QApplication>
#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     Connection c;

     /*QGuiApplication app(argc, argv);

     QQmlApplicationEngine engine;
     engine.load(QUrl(QStringLiteral("qrc:/map.qml")));

    */

     QTranslator t ;
    QStringList languages ;
    languages << "Français"<< "English" ;

    QString lang = QInputDialog::getItem(NULL,"Select Language",
                                         "Language", languages);

    if(lang == "English")
    {
        t.load(":/anglais.qm");
    }

    if(lang != "Français")
    {
        a.installTranslator(&t);
    }









    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
