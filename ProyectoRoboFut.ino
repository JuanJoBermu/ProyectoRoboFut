#include<Servo.h>
#include<SoftwareSerial.h>
#define TXBT 3
#define RXBT 2

SoftwareSerial BT(RXBT,TXBT);

int ServoD = 7;
int ServoI = 4;
char COMANDO;
int velocidad = 90;
int vel;
int totd, toti;

Servo der;
Servo izq;


void setup() {
  
  Serial.begin(9600);
  BT.begin(9600);
  der.attach(ServoD);
  izq.attach(ServoI);

}

void loop() {
  
  //der---> adelante (0)
  //izq---> adelante (180)
  
  if(BT.available()>0)
  {
    COMANDO = BT.read();
  }
  
  if(Serial.available()>0)
  {
    COMANDO = Serial.read();
    Serial.println(COMANDO);
  }
  
    switch(COMANDO)
      {

        case'+':
          vel+=3;
          totd=velocidad-vel;
          toti=velocidad+vel;
          der.write(totd);
          izq.write(toti);
          if (totd<0){ totd=0;}
          if (toti>180){ toti=180;}
        break;
        
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
