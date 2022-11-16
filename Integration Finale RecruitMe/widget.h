#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>


namespace Ui { class Widget; }


class QCamera ;
class QCameraViewfinder ;
class QCameraImageCapture ;
class QVBoxLayout ;
class QMenu ;
class QAction ;





class Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QCamera *mCamera ;
    QCameraViewfinder *mCameraViewfinder ;
    QCameraImageCapture *mCameraImageCapture ;
    QVBoxLayout  *mLayout ;
    QMenu *mOptionMenu ;
    QAction *mAllumerAction ;
    QAction *mEteindreAction ;
    QAction *mCaturerAction ;





};
#endif // WIDGET_H
