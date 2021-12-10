#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <demande.h>
#include"arduino.h"

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
    void on_pushButton_clicked();

    void on_pb_del_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pb_edit_clicked();

    void on_tab_demande_activated(const QModelIndex &index);

    void on_del_clicked();

    void on_pushButton_4_clicked();

    void on_pb_search_clicked();

    void on_le_tri_clicked();
 void   update_label();

private:
    Ui::MainWindow *ui;
    Demande D;
    Arduino A;
};

#endif // MAINWINDOW_H
