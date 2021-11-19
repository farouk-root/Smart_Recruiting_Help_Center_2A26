#ifndef SMTPP_H
#define SMTPP_H

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QtNetwork>
#include <QSslSocket>



class Smtpp : public QObject
{
    Q_OBJECT


public:
    Smtpp( const QString &user, const QString &pass,
          const QString &host, quint16 port = 587
            , int timeout = 30000 );
    ~Smtpp();

    void sendMaile( const QString &from, const QString &to,
                   const QString &subject, const QString &body );

signals:
    void status( const QString &);

private slots:
    void stateChanged(QAbstractSocket::SocketState socketState);//type de variable
    void errorReceived(QAbstractSocket::SocketError socketError);
    void disconnected();
    void connected();
    void readyRead();

private:
    int timeout;
    QString message;
    QTextStream *t;
    QSslSocket *socket;
    QString from;
    QString rcpt;
    QString response;
    QString user;
    QString pass;
    QString host;
    quint16 port;
    enum states{Tls, HandShake ,Auth,User,Pass,Rcpt,Mail,Data,Init,Body,Quit,Close};
    int state;

};

#endif // SMTP_H
