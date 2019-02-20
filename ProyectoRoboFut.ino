
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
  
    switch(COMANDO)
      {
        case 'w': case'W':
        der.write(0);         //Hacia adelante
        izq.write(180); 
        break;
    
        case 's': case'S':
        der.write(180);      //Hacia atras
        izq.write(0);
        break;
    
        case 'a': case'A':
        der.write(0);       //Giro a la izquierda
        izq.write(80);
        break;
    
        case 'd': case'D':
        der.write(100);     //Giro a la derecha
        izq.write(180);
        break;
    
        default:
        der.write(90);      //Parar
        izq.write(90);
      }
}
