/*
  Reading a serial ASCII-encoded string.
 
 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.
 
 Circuit: Common-anode RGB LED wired like so:
 * Red cathode: digital pin 3
 * Green cathode: digital pin 5
 * blue cathode: digital pin 6
 * anode: +5V
 
 created 13 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 */
#include "Configuration.h"

int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor

int read_ptr = 0.0;
int write_ptr = 0.0;

double kp_air = 0.0;
double ki_air = 0.0;
double kd_air = 0.0;
double maxtemp_air= 130.0;

double kp_bed = 0.0;
double ki_bed = 0.0;
double kd_bed = 0.0;


char datas[MAX_BYTE_RECEIVED] = {0};
char command[MAX_BYTE_RECEIVED] = {0};


void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
 

  pinMode(2, INPUT);   // digital sensor is on digital pin 2
  establishContact();  // send a byte to establish contact until receiver responds 
}

int receiveCommand( char delim ) {
    while (Serial.available() > 0  && write_ptr < MAX_BYTE_RECEIVED ) {
      datas[write_ptr] = Serial.read();

      if ( datas[write_ptr] == delim ) {
          read_ptr = write_ptr + 1;
          strncpy(command, datas, read_ptr);
          command[read_ptr-1] = '\0';
          write_ptr = 0;
          return 1;
        } 
        else {
          write_ptr++;
        }
    }
    return 0;
}

void sendCommand(char* action, char* variable, double value ) {
  Serial.print(action); 
  Serial.print(' '); 
  Serial.print(variable); 
  Serial.print(' '); 
  Serial.print(value); 
  Serial.print(END_COMMAND_DELIMITER); 
}
void parseDatas( ) {
  int lenght_action = (strchr(command,' ')-command);
  int lenght_variable = 0;
  char* ptr = NULL;
  if ( strncmp("set",command,lenght_action ) == 0 ) {
      ptr = &(command[lenght_action+1]);
      lenght_variable = strchr( ptr, ' ') - ptr;
      double value = strtod( ptr+lenght_variable, NULL);
      if ( strncmp("ki", ptr, lenght_variable ) == 0 ) {
          ki_air = value;
      }    
      else if ( strncmp("kp", ptr, lenght_variable ) == 0 ) {
          kp_air = value;
      }
      else if ( strncmp("kd", ptr, lenght_variable ) == 0 ) {
          kd_air = value;
      }
      else if ( strncmp("maxtemp", ptr, lenght_variable ) == 0 ) {
          maxtemp_air = value;
      }
     
  }
  else if ( strncmp("get",command,lenght_action ) == 0 ) {
      ptr = &(command[lenght_action+1]);
      lenght_variable = strchr( ptr, '\0') - ptr;
      if ( strncmp("ki", ptr, lenght_variable ) == 0 ) {
          sendCommand("set","ki",ki_air);
      }    
      else if ( strncmp("kp", ptr, lenght_variable ) == 0 ) {
          sendCommand("set","kp",kp_air);

      }
      else if ( strncmp("kd", ptr, lenght_variable ) == 0 ) {
          sendCommand("set","kd",kd_air);
      }
      else if ( strncmp("maxtemp", ptr, lenght_variable ) == 0 ) {
          sendCommand("set","maxtemp",maxtemp_air);
      }

  }

}

void bed_actualise() {

}

void air_actualise() {

}

void loop()
{
    if ( receiveCommand(END_COMMAND_DELIMITER) ) {
      parseDatas();
    }
    bed_actualise();
    air_actualise();
    delay(100);
}

void establishContact() {
    while (Serial.available() <= 0) {
        Serial.print('A');   // send a capital A
        delay(300);
    }
}







