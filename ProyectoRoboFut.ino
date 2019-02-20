
#include<Servo.h>
#include<SoftwareSerial.h>

int ServoD = 7;
int ServoI = 4;
char COMANDO;

Servo der;
Servo izq;


void setup() {
  
  Serial.begin(9600);
  der.attach(ServoD);
  izq.attach(ServoI);

}

void loop() {
  
  //der---> adelante (0)
  //izq---> adelante (180)

  if(Serial.available()>0)
  {
    COMANDO = Serial.read();

  }

  
  der.write(0);         //Hacia adelante
  izq.write(180);       
  delay(3000);
  
  der.write(180);      //Hacia atras
  izq.write(0);
  delay(3000);

  der.write(100);     //Giro a la derecha
  izq.write(180);
  delay(3000);

  der.write(0);      //Giro a la izquierda
  izq.write(80);
  delay(3000);

  der.write(90);      //Parar
  izq.write(90);
  delay(3000);
  

}
