/**
 * Hardware : Arduino Mega 2560
 * Since : May 2013
 * Author : Florian Boudinet
 * fboudinet@enseirb-matmeca.fr
 *S
 **/

#include "Configuration.h"

int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
 

  pinMode(2, INPUT);   // digital sensor is on digital pin 2
  establishContact();  // send a byte to establish contact until receiver responds 
}

char* getDatasReceived() {
    char datas[MAX_BYTE_RECEIVED] = {0};
    int cptr = 0;
    while (Serial.available() > 0 && cptr < MAX_BYTE_RECEIVED) {
        datas[cptr] = Serial.read();
        cptr++;
        Serial.print('A');
    }
    return datas;
}
void parseDatas( char *datas ) {

}

void bed_actualise() {

}

void air_actualise() {

}

void loop()
{
    char * datas = getDatasReceived();
    parseDatas( datas );
    bed_actualise();
    air_actualise();
}

void establishContact() {
    while (Serial.available() <= 0) {
        Serial.print('A');   // send a capital A
        delay(300);
    }
}
