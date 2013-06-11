#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tempcontroller.h"
#include "graphtemp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void changeMaxTemp(double value );
private slots:
    void on_connectButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    TempController* _tempController;
    void setVisibleComponents( bool activate );
};

#endif // MAINWINDOW_H
