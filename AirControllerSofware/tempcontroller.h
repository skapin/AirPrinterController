#ifndef TEMPCONTROLLER_H
#define TEMPCONTROLLER_H

#include <QObject>
#include <string>
#include <QVector>
#include <QRegExp>

#include "uart.h"

class TempController : public QObject
{
    Q_OBJECT
public:
    explicit TempController(QObject *parent = 0);
    
    int openDevice( string path );
    Uart* getDevice();
    void closeDevice();

    void addTemp(double temp);

    double getKp() const
    {
        return _kp;
    }
    double getKi() const
    {
        return _ki;
    }
    double getKd() const
    {
        return _kd;
    }
    double getCurrentTemp() const
    {
        return _currentTemp;
    }
    double getMaxTemp() const
    {
        return _maxtemp;
    }
    int getObjTemp() const
    {
        return _objTemp;
    }
    static int MAX_TEMP_LIST;
signals:
    
public slots:
    void setAttribut( string variable, double value ) {
        _device.send( "set "+variable+" "+ QString::number(value).toStdString() ) ;
    }
    void setAttribut( string variable, int value ) {
        _device.send( "set "+variable+" "+ QString::number(value).toStdString() ) ;
    }
    void setKp( double kp )
    {
        setAttribut("kp", _kp);
        _kp = kp;
    }
    void setKi( double ki )
    {
        setAttribut("ki", _ki);
        _ki = ki;
    }
    void setKd( double kd)
    {
        setAttribut("kd", _kd);
        _kd = kd;
    }
    void setCurrentTemp( double temp)
    {
        _currentTemp = temp;
    }
    void setMaxTemp( double temp)
    {
        setAttribut("maxtemp", _maxtemp);
        _maxtemp = temp;
    }
    void setObjTemp( int temp )
    {
        setAttribut("targettemp", _objTemp);
        _objTemp = temp;
    }
private:
    Uart _device;
    double _kp;
    double _ki;
    double _kd;
    double _currentTemp;
    double _maxtemp;
    int _objTemp;
    QVector<double> _tempList;
    
    void parseData( string data );

};

#endif // TEMPCONTROLLER_H
