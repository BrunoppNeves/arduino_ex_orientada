#include <Arduino.h>
#define ventilador 13
#define luz 12
#define hora 11
#define but 10
int flag_but = 1;
int flag_dia =1;

void setup() {
  Serial.begin(9600);
  pinMode(ventilador, OUTPUT);
  pinMode(luz, OUTPUT);
  pinMode(hora, OUTPUT);
  pinMode(but, INPUT_PULLUP);

}

void loop() {
  // Transforma em um botão clicavel
  if(digitalRead(but) == 0 && flag_but ==1 ){
    flag_but = 0;
    flag_dia = !flag_dia;
    delay(100);
  }
  else if(digitalRead(but) == 1 && flag_but ==0){
    flag_but = 1;
    delay(100);
  }
  // define se é dia ou noite (led aceso dia) / (led apagado noite)
  if(flag_dia == 1){
    digitalWrite(hora,1);
    
  }
  else{
    digitalWrite(hora,0);
  }
  
  digitalWrite(ventilador, 1);
  digitalWrite(luz,1);
  
  }