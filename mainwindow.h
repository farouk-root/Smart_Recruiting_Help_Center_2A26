#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "offre.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Valider_clicked();
void on_pushButton_clicked();
void on_pushButton_2_clicked();
void on_pushButton_3_clicked();
void on_Modifier_clicked();

void on_Actualiser_clicked();

void on_Trie_botton_clicked();

void on_Tri_nom_clicked();

void on_Tri_adresse_clicked();

void on_rechercheID_textChanged(const QString &arg1);

void on_rechercheNom_textChanged(const QString &arg1);

void on_rechercheAdresse_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    offre o ;


};

#endif // MAINWINDOW_H
