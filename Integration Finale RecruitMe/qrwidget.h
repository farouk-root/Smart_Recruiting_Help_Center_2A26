#ifndef QRWIDGET_H
#define QRWIDGET_H

#include <QWidget>

class QRWidget : public QWidget{
    Q_OBJECT
private:
    QString data;
public:
    explicit QRWidget(QWidget *parent = 0);
    void setQRData(QString data);
    QSize* sz = new QSize(220,220);
    QColor* fg = new QColor(0,0,0);
protected:
    void paintEvent(QPaintEvent *);
};

#endif // QRWIDGET_H
