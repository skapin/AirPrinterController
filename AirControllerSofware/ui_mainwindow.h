/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jun 5 17:05:25 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "graphtemp.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    GraphTemp *graphTemp;
    QLabel *currentTemp;
    QPushButton *connectButton;
    QLineEdit *pathToDevice;
    QWidget *layoutWidget;
    QGridLayout *gridPID;
    QLabel *label_kp;
    QDoubleSpinBox *kp;
    QLabel *labek_ki;
    QDoubleSpinBox *ki;
    QLabel *label_kd;
    QDoubleSpinBox *kd;
    QWidget *layoutWidget1;
    QGridLayout *gridSettemp;
    QLabel *label_settem;
    QSpinBox *settemp;
    QSlider *temp_slider;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *maxtemp_label;
    QDoubleSpinBox *maxtemp;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1068, 697);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphTemp = new GraphTemp(centralWidget);
        graphTemp->setObjectName(QString::fromUtf8("graphTemp"));
        graphTemp->setGeometry(QRect(10, 30, 911, 611));
        currentTemp = new QLabel(centralWidget);
        currentTemp->setObjectName(QString::fromUtf8("currentTemp"));
        currentTemp->setGeometry(QRect(960, 40, 71, 31));
        currentTemp->setStyleSheet(QString::fromUtf8("font: 75 italic 24pt \"Ubuntu\";"));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(0, 0, 91, 24));
        pathToDevice = new QLineEdit(centralWidget);
        pathToDevice->setObjectName(QString::fromUtf8("pathToDevice"));
        pathToDevice->setGeometry(QRect(100, 0, 151, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(940, 90, 87, 79));
        gridPID = new QGridLayout(layoutWidget);
        gridPID->setSpacing(6);
        gridPID->setContentsMargins(11, 11, 11, 11);
        gridPID->setObjectName(QString::fromUtf8("gridPID"));
        gridPID->setContentsMargins(0, 0, 0, 0);
        label_kp = new QLabel(layoutWidget);
        label_kp->setObjectName(QString::fromUtf8("label_kp"));

        gridPID->addWidget(label_kp, 0, 0, 1, 1);

        kp = new QDoubleSpinBox(layoutWidget);
        kp->setObjectName(QString::fromUtf8("kp"));
        kp->setEnabled(false);

        gridPID->addWidget(kp, 0, 1, 1, 1);

        labek_ki = new QLabel(layoutWidget);
        labek_ki->setObjectName(QString::fromUtf8("labek_ki"));

        gridPID->addWidget(labek_ki, 1, 0, 1, 1);

        ki = new QDoubleSpinBox(layoutWidget);
        ki->setObjectName(QString::fromUtf8("ki"));
        ki->setEnabled(false);

        gridPID->addWidget(ki, 1, 1, 1, 1);

        label_kd = new QLabel(layoutWidget);
        label_kd->setObjectName(QString::fromUtf8("label_kd"));

        gridPID->addWidget(label_kd, 2, 0, 1, 1);

        kd = new QDoubleSpinBox(layoutWidget);
        kd->setObjectName(QString::fromUtf8("kd"));
        kd->setEnabled(false);

        gridPID->addWidget(kd, 2, 1, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(860, 0, 114, 25));
        gridSettemp = new QGridLayout(layoutWidget1);
        gridSettemp->setSpacing(6);
        gridSettemp->setContentsMargins(11, 11, 11, 11);
        gridSettemp->setObjectName(QString::fromUtf8("gridSettemp"));
        gridSettemp->setContentsMargins(0, 0, 0, 0);
        label_settem = new QLabel(layoutWidget1);
        label_settem->setObjectName(QString::fromUtf8("label_settem"));

        gridSettemp->addWidget(label_settem, 0, 0, 1, 1);

        settemp = new QSpinBox(layoutWidget1);
        settemp->setObjectName(QString::fromUtf8("settemp"));
        settemp->setEnabled(false);

        gridSettemp->addWidget(settemp, 0, 1, 1, 1);

        temp_slider = new QSlider(centralWidget);
        temp_slider->setObjectName(QString::fromUtf8("temp_slider"));
        temp_slider->setEnabled(false);
        temp_slider->setGeometry(QRect(920, 30, 23, 611));
        temp_slider->setOrientation(Qt::Vertical);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(680, 0, 133, 25));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        maxtemp_label = new QLabel(layoutWidget2);
        maxtemp_label->setObjectName(QString::fromUtf8("maxtemp_label"));

        gridLayout->addWidget(maxtemp_label, 0, 0, 1, 1);

        maxtemp = new QDoubleSpinBox(layoutWidget2);
        maxtemp->setObjectName(QString::fromUtf8("maxtemp"));
        maxtemp->setEnabled(false);

        gridLayout->addWidget(maxtemp, 0, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(940, 180, 91, 24));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        graphTemp->raise();
        currentTemp->raise();
        connectButton->raise();
        pathToDevice->raise();
        temp_slider->raise();
        pushButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1068, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        currentTemp->setText(QApplication::translate("MainWindow", "\302\260C", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        pathToDevice->setText(QApplication::translate("MainWindow", "/dev/ttyUSB0", 0, QApplication::UnicodeUTF8));
        label_kp->setText(QApplication::translate("MainWindow", "Kp : ", 0, QApplication::UnicodeUTF8));
        labek_ki->setText(QApplication::translate("MainWindow", "Ki : ", 0, QApplication::UnicodeUTF8));
        label_kd->setText(QApplication::translate("MainWindow", "Kd : ", 0, QApplication::UnicodeUTF8));
        label_settem->setText(QApplication::translate("MainWindow", "Set temp :", 0, QApplication::UnicodeUTF8));
        maxtemp_label->setText(QApplication::translate("MainWindow", "Max Temp :  ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Find PID", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
