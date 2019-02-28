
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
#define RXBT 2  //se define el pin 2 para como el rx de la placa de arduino nano

SoftwareSerial BT(RXBT,TXBT); //se definen pines del bluetooth 

int ServoD = 7;   //se define el pin 7 para el servo derecho
int ServoI = 4;   //se define el pin 4 para el servo izquierdo
char COMANDO;     //se define la variable para la comunicacion teclado-bluetooh-arduino
int velocidad = 90;   //se define la velocidad con un valor inicial de 90
int vel;    //se define la variable para aumento y disminución de la velocidad
int totd, toti;   //se defin las variables para la velocidad
int i; //incremento de la celebracion 2

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

        //CONTROL SERVO IZQUIERDO CON SLIDER
        case 'A': izq.write(0); break; //0
        case 'B': izq.write(9); break; //1
        case 'C': izq.write(18); break; //2
        case 'D': izq.write(27); break; //3
        case 'E': izq.write(36); break; //4
        case 'F': izq.write(45); break; //5
        case 'G': izq.write(54); break; //6
        case 'H': izq.write(63); break; //7
        case 'I': izq.write(72); break; //8
        case 'J': izq.write(81); break; //9
        case 'K': izq.write(90); break; //10
        case 'L': izq.write(99); break; //11
        case 'M': izq.write(108); break; //12
        case 'N': izq.write(117); break; //13
        case 'O': izq.write(126); break; //14
        case 'P': izq.write(135); break; //15
        case 'Q': izq.write(144); break; //16
        case 'R': izq.write(153); break; //17
        case 'S': izq.write(162); break; //18
        case 'T': izq.write(171); break; //19
        case 'U': izq.write(180); break; //20


        //CONTROL SERVO DERECHO CON SLIDER
        case 'a': der.write(180); break; //0
        case 'b': der.write(171); break; //1
        case 'c': der.write(162); break; //2
        case 'd': der.write(153); break; //3
        case 'e': der.write(144); break; //4
        case 'f': der.write(135); break; //5
        case 'g': der.write(126); break; //6
        case 'h': der.write(117); break; //7
        case 'i': der.write(108); break; //8
        case 'j': der.write(99); break; //9
        case 'k': der.write(90); break; //10
        case 'l': der.write(81); break; //11
        case 'm': der.write(72); break; //12
        case 'n': der.write(63); break; //13
        case 'o': der.write(54); break; //14
        case 'p': der.write(45); break; //15
        case 'q': der.write(36); break; //16
        case 'r': der.write(27); break; //17
        case 's': der.write(18); break; //18
        case 't': der.write(9); break; //19
        case 'u': der.write(0); break; //20
        

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

          //CELEBRACION 1
        case '1':   
        der.write(0); izq.write(180); delay(500);
        der.write(160); izq.write(20); delay(500);
        der.write(40); izq.write(140); delay(500);
        der.write(120); izq.write(60); delay(500);
        der.write(80); izq.write(100); delay(500);
        der.write(180); izq.write(180); delay(1000);
        der.write(0); izq.write(0); delay(1000);
        break;

         //CELEBRACION 2
        case'2':
        for (velocidad=90, vel=9, i=0; i<10; i++)
        {
          der.write(velocidad-vel); izq.write(velocidad-vel); delay(500); vel+=9;
        }
        break;

         //CELEBRACION 3
        case'3':
        der.write(0); izq.write(70); delay(200);
        der.write(110); izq.write(180); delay(200);
        break;

        //ZIG ZAG
        case'z':
        der.write(0); izq.write(0); delay(200);
        der.write(45); izq.write(135); delay(1000);
        der.write(180); izq.write(180); delay(200);
        der.write(45); izq.write(135); delay(1000);
        break;

        /*
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
        */
    
        default:
          der.write(90);      //Parar
          izq.write(90);
          
      }
  }
}
