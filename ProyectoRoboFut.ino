
/*
HEMERSON LEANDRO ÁLVAREZ RODRÍGUEZ
JUAN JOSÉ BERMÚDEZ LOPERA
UNIVERSIDAD DEL QUINDÍO
PROGRAMA: INGENIERÍA ELECTRÓNICA
ESPACIO ACADEMICO: PROGRAMACIÓN I
PROYECTO FINAL: ProyectoRobotFut
*/

#include<Servo.h>
#include<SoftwareSerial.h>
#define TXBT 3  //se define el pin 3 para como el tx de la placa de arduino nano
#define RXBT 2  //se define el pin 3 para como el rx de la placa de arduino nano

SoftwareSerial BT(RXBT,TXBT); //se definen pines del bluetooth 

int ServoD = 7;   //se define el pin 7 para el servo derecho
int ServoI = 4;   //se define el pin 4 para el servo izquierdo
char COMANDO;     //se define la variable para la comunicacion teclado-bluetooh-arduino
int velocidad = 90;   //se define la velocidad con un valor inicial de 90
int vel;    //se define la variable para aumento y disminución de la velocidad
int totd, toti;   //se defin las variables para la velocidad

Servo der;    //se define el nombre de el servo derecho
Servo izq;    //se define el nombre del servo izquierdo


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
  
  
    switch(COMANDO)
      {

        case'+':    //aumento de velocidad
          vel+=3;
          totd=velocidad-vel;
          toti=velocidad+vel;
          der.write(totd);
          izq.write(toti);
          if (totd<0){ totd=0;}
          if (toti>180){ toti=180;}
        break;

        case '-':   //disminucion de velocidad
          vel-=3;
          totd=velocidad-vel;
          toti=velocidad+vel;
          der.write(totd);
          izq.write(toti);
          if (totd>180){totd=180;}
          if (totd<0){totd=0;}
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
}
