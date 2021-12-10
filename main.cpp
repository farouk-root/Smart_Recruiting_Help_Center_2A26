#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
#include <QApplication>
#include <QDebug>
#include <QDialog>
#include <QLineEdit>

#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection c;

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


    a.setStyle("fusion") ;
    //qApp->setStyleSheet("QLineEdit { background-color: yellow }");






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
