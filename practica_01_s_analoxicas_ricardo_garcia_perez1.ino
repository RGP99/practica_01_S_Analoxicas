/*
Este código se comunica con el usuario a través del Monitor Serie para saber qué LED 
quiere encender y durante cuánto tiempo. Esto lo hace principalmente con la estructura if/else 
y switch. También hemos configurado las salidas 13, 12 y 8 como digitales, 
y las 11, 10 y 9 como analógicas; utilizamos funciones como Serial.println 
para interactuar con el usuario.

Tutor: Víctor M. Álvarez Pérez
Alumno: Ricardo García Pérez
Data: 25/11/2025

*/



String cor ="";

float tempo = -9600;
int pin = -99;

void setup (){
  Serial.begin (9600);
  
  pinMode (13,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (8,OUTPUT);  
  
  for (int i=13; i>=8; i--) {
  pinMode (i, OUTPUT);
}
}

void loop () {
  
Serial.println("dime a cor do LED que queres encender"); //Estas dos funciones lo que hacen es comunicarse con el usuario mediante el monitor serial

while (Serial.available() == 0) {}

cor = Serial.readString ();
   
Serial.println ("dime cantos segundos debe estar ON ou OFF");
  
  while (Serial.available() == 0) {}
  
  tempo = 1000 * Serial.parseFloat ();


  
  if (cor == "verde"){pin = 13;}
  else if (cor == "amarelo"){pin =12;}
  else if (cor == "naranxa"){pin = 11;}
  else if (cor == "azul") {pin = 10;}
  else if (cor == "vermello") {pin = 9;}
  else if (cor == "branco") {pin = 8;}

  /* Usaremos la funcion switch
  como si fuera un "if/else" para ver si se comporta y ver como seria escribir con el*/
    
    switch (pin) { 
    case 13:
    digitalWrite (13,HIGH);
    delay (tempo);
    digitalWrite (13,LOW);
    delay (tempo);
    break;
  
    case 12:
    digitalWrite (12,HIGH);
    delay (tempo);
    digitalWrite (12,LOW);
    delay (tempo);
    break;
    
    case 11:
    for (int i = 0; i < 256; i++) {
      analogWrite (11, i);
      delay (tempo/256);
    }
    for (int i = 255; i >= 0; i--){
      analogWrite (11, i);
      delay (tempo/256);
    }
break;
    
   case 10:
    for (int i = 0; i < 256; i++) {
      analogWrite (10,i);
      delay (tempo/256);
    }
    for (int i = 255; i >= 0; i--){
      analogWrite (10,i);
      delay (tempo/256);
    }
break;
      case 9:
    for (int i = 0; i < 256; i++) {
      analogWrite (9,i);
      delay (tempo/256);
    }
    for (int i = 255; i >= 0; i--){
      analogWrite (9,i);
      delay (tempo/256);
    }
break;
      
    case 8:
    digitalWrite (8,HIGH);
    delay (tempo);
    digitalWrite (8,LOW);
    delay (tempo);
    break; 
 default:
   Serial.println ( "A cor que me indicaches non existe"); //Aquí se incluye este último else por si el usuario se equivocó al usar una tilde o al escribir mal la palabra
      Serial.println("escoller outra cor");
  break;
    }
}
        
        
        
        

