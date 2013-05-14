#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _tempController = new TempController( this );
    ui->graphTemp->setTempController( _tempController );

    connect( this->ui->kp, SIGNAL(valueChanged(double)), _tempController, SLOT(setKp(double)) );
    connect( this->ui->ki, SIGNAL(valueChanged(double)), _tempController, SLOT(setKi(double)) );
    connect( this->ui->kd, SIGNAL(valueChanged(double)), _tempController, SLOT(setKd(double)) );

    connect( this->ui->temp_slider, SIGNAL(sliderMoved(int)), _tempController, SLOT(setObjTemp(int)) );
    connect( this->ui->temp_slider, SIGNAL(sliderMoved(int)), ui->settemp, SLOT(setValue(int)) );
    connect( this->ui->settemp, SIGNAL(valueChanged(int)), ui->temp_slider, SLOT(setValue(int)) );
    connect( this->ui->settemp, SIGNAL(valueChanged(int)), _tempController, SLOT(setObjTemp(int)) );


    connect( this->ui->maxtemp, SIGNAL(valueChanged(double)), this, SLOT(changeMaxTemp(double)) );

    setVisibleComponents( false );
}

void MainWindow::changeMaxTemp(double value ) {
    ui->temp_slider->setMaximum( ui->maxtemp->value() + 50 );
    _tempController->setMaxTemp( value );
    //ui->graphTemp->setAxisScale();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    if ( _tempController->getDevice()->isDeviceOpen() ) {
        _tempController->closeDevice();
        ui->connectButton->setText("Connect");
        ui->statusBar->showMessage("The device is disconnected.");
        setVisibleComponents( false );
    }
    else {
        ui->statusBar->showMessage("Trying a connection to the device...");
        if ( _tempController->openDevice( ui->pathToDevice->text().toStdString() ) )
        {
            //_tempController.updateInformation();
            ui->connectButton->setText("Disconnect");
            ui->statusBar->showMessage("Device connected.");
            setVisibleComponents( true );
        }
        else
            ui->statusBar->showMessage("Can't connect to the device...");
    }

}

void MainWindow::setVisibleComponents( bool activate) {
    ui->kp->setEnabled( activate );
    ui->ki->setEnabled( activate );
    ui->kd->setEnabled( activate );
    ui->settemp->setEnabled( activate );
    ui->maxtemp->setEnabled( activate );
    ui->temp_slider->setEnabled( activate );
    ui->currentTemp->setVisible( activate );
}

