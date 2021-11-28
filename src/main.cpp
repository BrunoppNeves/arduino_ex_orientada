#include <Arduino.h>
#define but 10
int flag_but = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(but, INPUT_PULLUP);
}

void loop()
{
  // Transforma em um botão clicavel
  if (digitalRead(but) == 0 && flag_but == 1)
  {
    flag_but = 0;
    flag_dia = !flag_dia;
    delay(100);
  }
  else if (digitalRead(but) == 1 && flag_but == 0)
  {
    flag_but = 1;
    delay(100);
  }