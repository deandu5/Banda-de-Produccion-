#include <Servo.h>
int speakerPin = 11; // Será la salida del tono
     int numTones = 10;
     int tones[ ] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440,466, 494};

Servo servo1; // Declaramos el Servo No.1 
Servo servo2; // Declaramos el Servo No.2
Servo servo3; // Declaramos el Servo No.3 
 int trigger = 2; // Aqui declararemos la salida para el Ultrasónico       
 int echo = 3; // Aqui declararemos la entrada de lectura para el Ultrasónico        
 float tiempo_de_espera,distancia;

  

void setup() {
  
  Serial.begin (9600);  // Se inicia la comunicación serial 
  pinMode (trigger, OUTPUT); // Pin de salida del ultrasónico
  pinMode (echo, INPUT); // Pin de salida del ultrasónico

   
  
   servo1.attach(8); 
   servo1.write(10); // Unidad de grados a la que estará inicialmente el servomotor 1 
    servo2.attach(9);
   servo2.write(100); // Unidad de grados a la que estará el inicialmente servomotor 2
    servo3.attach(10);
   servo3.write(135); // Unidad de grados a la que estará inicialmente el servomotor 3
   pinMode(13,OUTPUT); // Este pin sera la salida del tono programado para el zumbador 
}

void loop() {

digitalWrite (trigger,LOW);
delayMicroseconds(2);  //Enviamos un pulso de 2us
digitalWrite (trigger, HIGH);
delayMicroseconds (10); //Enviamos un pulso de 10us   
digitalWrite (trigger, LOW); 



tiempo_de_espera = pulseIn (echo,HIGH); 
 
distancia = (tiempo_de_espera/2)/29.15; 
Serial.print (distancia); //Enviamos serialmente el valor de la distancia
Serial.println ("cm");  //Imprimera la distancia a la que se encuentra el recipiente
delay (100);




digitalWrite(13,LOW);
 if(distancia<=10){   
  servo1.write(130); // servo pasar
delay(1000);
 servo1.write(10); // servo pasar
delay(520);
  digitalWrite(13,HIGH);
  servo2.write(180); // servo llenado
  delay(2000);
  servo2.write(100); // servo llenado 
  digitalWrite(13,LOW); 
  servo3.write(15); // servo pasar
  delay(3000);
  servo3.write(135); // servo pasar 
  delay(1000);
  
 { 
  digitalWrite(13,HIGH);
   for (int i = 0; i < numTones; i++)
                 {
                     tone(speakerPin, tones[i]);
                     delay(500);
                 }
             noTone(speakerPin);
             delay(4000);
}
  
 } 
}
