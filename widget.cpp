#include "widget.h"
#include "ui_widget.h"
#include "employes.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QMenu>
#include<QAction>
#include<QFileDialog>


Widget::Widget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout ;

    mOptionMenu = new QMenu("options",this);
    mAllumerAction = new QAction("Allumer",this);
    mEteindreAction = new QAction("ETeindre",this);
    mCaturerAction = new QAction ("Capturer",this);

    mOptionMenu->addActions({mAllumerAction , mEteindreAction , mCaturerAction});

    ui->option_pushButton->setMenu(mOptionMenu);
    mCamera->setViewfinder(mCameraViewfinder);


    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);

    ui->scrollArea->setLayout(mLayout);

    connect(mAllumerAction, &QAction::triggered,[&](){   mCamera->start();});

    connect(mEteindreAction,&QAction::triggered,[&]()
    {
        mCamera->stop();
    });

    connect(mCaturerAction,&QAction::triggered,[&]()
    {
     auto filename  = QFileDialog::getSaveFileName(this,"capturer", "/" , "Image (*jpg;* jpeg)");
        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings ;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
       mCamera->setCaptureMode(QCamera::CaptureStillImage);
       mCamera->start();
       mCamera->searchAndLock();
       mCameraImageCapture->capture(filename);
       mCamera->unlock();

    });


}

Widget::~Widget()
{
    delete ui;
}

