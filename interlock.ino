#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); //Declare pins 6 and 7 as RX/TX

int pressureSensor = 0; //Declare pin A0 to pressure sensor
int relayTrigger = 8; //Declare pin 8 to control particle gun relay

int pressureThreshold = 389; //floor(3.8/10 * 1024) for voltage reading to 10 bit
int pressure = 0;
int warningLED = 13;

void setup() {
  pinMode(pressureSensor, INPUT);
  digitalWrite(relayTrigger, LOW);
  digitalWrite(warningLED, LOW);
  
  mySerial.begin(9600);
  while(!mySerial){
    ;
  }
}

void loop() {
  pressure = analogRead(pressureSensor);

  if(pressure >= pressureThreshold){
    stopProcess();
    }
    warning();
    }
  }
  delay(10);
}

void stopProcess(){
  if(mySerial.available()){
    mySerial.println(3);
  }
  digitalWrite(relayTrigger, HIGH);
}

void warning(){
  digitalWrite(warningLED, HIGH);
}
