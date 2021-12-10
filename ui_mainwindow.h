/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *l_etablissement;
    QLineEdit *le_mail;
    QLineEdit *entreprise;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QTableView *tableView;
    QPushButton *pb_edit;
    QDateEdit *la_date;
    QPushButton *pb_search;
    QLineEdit *le_search;
    QPushButton *le_tri;
    QWidget *tab_3;
    QLabel *label_8;
    QPushButton *pb_del;
    QLineEdit *le_id_supp;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1118, 627);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 1071, 501));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 1031, 471));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 71, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 80, 56, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 56, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 160, 91, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 200, 56, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 240, 111, 16));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(120, 40, 113, 22));
        le_nom = new QLineEdit(groupBox);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(120, 80, 113, 22));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(120, 120, 113, 22));
        l_etablissement = new QLineEdit(groupBox);
        l_etablissement->setObjectName(QStringLiteral("l_etablissement"));
        l_etablissement->setGeometry(QRect(120, 160, 113, 22));
        le_mail = new QLineEdit(groupBox);
        le_mail->setObjectName(QStringLiteral("le_mail"));
        le_mail->setGeometry(QRect(120, 200, 113, 22));
        entreprise = new QLineEdit(groupBox);
        entreprise->setObjectName(QStringLiteral("entreprise"));
        entreprise->setGeometry(QRect(120, 290, 113, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 290, 121, 20));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 330, 141, 51));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 400, 93, 28));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 400, 93, 28));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 221, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 100, 221, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 140, 231, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 260, 231, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(groupBox);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(10, 220, 231, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(10, 180, 231, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(290, 80, 721, 311));
        pb_edit = new QPushButton(groupBox);
        pb_edit->setObjectName(QStringLiteral("pb_edit"));
        pb_edit->setGeometry(QRect(900, 410, 93, 28));
        la_date = new QDateEdit(groupBox);
        la_date->setObjectName(QStringLiteral("la_date"));
        la_date->setGeometry(QRect(120, 240, 110, 22));
        pb_search = new QPushButton(groupBox);
        pb_search->setObjectName(QStringLiteral("pb_search"));
        pb_search->setGeometry(QRect(650, 20, 93, 28));
        le_search = new QLineEdit(groupBox);
        le_search->setObjectName(QStringLiteral("le_search"));
        le_search->setGeometry(QRect(760, 20, 113, 22));
        le_tri = new QPushButton(groupBox);
        le_tri->setObjectName(QStringLiteral("le_tri"));
        le_tri->setGeometry(QRect(290, 40, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 80, 56, 16));
        pb_del = new QPushButton(tab_3);
        pb_del->setObjectName(QStringLiteral("pb_del"));
        pb_del->setGeometry(QRect(140, 210, 131, 41));
        le_id_supp = new QLineEdit(tab_3);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(140, 150, 113, 22));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1118, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Identifiant:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Prenom:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Etablissement:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Mail:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Date de naissance:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ID de l'entreprise:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Nettoyer", Q_NULLPTR));
        pb_edit->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pb_search->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        le_tri->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        pb_del->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
