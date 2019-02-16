
#include<Servo.h>
#include<SoftwareSerial.h>

int ServoD = 7;
int ServoI = 4;

Servo der;
Servo izq;

void setup() {
  // put your setup code here, to run once:

  der.attach(ServoD);
  izq.attach(ServoI);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  der.write(0);         //Hacia adelante
  izq.write(180);
  

    
}
