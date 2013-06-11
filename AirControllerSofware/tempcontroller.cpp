#include "tempcontroller.h"

int TempController::MAX_TEMP_LIST=60*60*24;

TempController::TempController(QObject *parent) :
    QObject(parent)
{
}


int TempController::openDevice(string path) {
    _device.setPortName( path );
    return ( _device.openDevice() );
}

Uart* TempController::getDevice() {
    return &_device;
}

void TempController::closeDevice() {
    _device.closeDevice();
}

void TempController::parseData(string data) {
    QRegExp reg("(\\c*)\\s*(\\S*)\\s*(\\d*)");

    QString d( data.c_str() ) ;
    string action, variable;

    int pos = 0;
    while ( (pos=reg.indexIn( d , pos )) != -1 ) {
        pos += reg.matchedLength();

        action = reg.cap(1).toStdString();

        if ( action.compare("set") == 0) {
            variable = reg.cap(2).toStdString();
            if ( variable.compare("kp") == 0) {
                _kp = reg.cap(3).toDouble();
            }
            else if ( variable.compare("ki") == 0) {
                _ki = reg.cap(3).toDouble();
            }
            else if ( variable.compare("kd") == 0) {
                _kd = reg.cap(3).toDouble();
            }
            else if ( variable.compare("maxtemp") == 0) {
                _kp = reg.cap(3).toInt();
            }
            else if ( variable.compare("temp") == 0) {
                addTemp( (double)(reg.cap(3).toInt()) );
            }
            else if ( variable.compare("targettemp") == 0) {
                //addTemp( (double)(reg.cap(3).toInt()) );
            }


        }
        else if ( action.compare("get") == 0 ) {
            variable = reg.cap(2).toStdString();
            string value_to_send;
            if ( variable.compare("kp") == 0) {
                value_to_send = QString::number(_kp).toStdString();
            }
            else if ( variable.compare("ki") == 0) {
                value_to_send = QString::number(_ki).toStdString();
            }
            else if ( variable.compare("kd") == 0) {
                value_to_send = QString::number(_kd).toStdString();
            }
            else if ( variable.compare("maxtemp") == 0) {
                value_to_send = QString::number(_maxtemp).toStdString();
            }
            /*else if ( variable.compare("temp") == 0) {
                value_to_send = QString::number(_currentTemp).toStdString();
            }*/
            _device.send("set "+variable+" "+value_to_send) ;

        }
        else if ( action.compare("off") == 0) {
            this->closeDevice();
            //emit ??????????
        }
    }
}

void TempController::addTemp(double temp) {
    if ( _tempList.size() > TempController::MAX_TEMP_LIST ) {
        _tempList.remove(0,(int)TempController::MAX_TEMP_LIST/100 );
    }
    _tempList.append( temp );
}
