#include <Arduino.h>
#define Ena1 11
#define IN1 10
#define IN2 8
#define abre 2
#define fecha 3
#define botaoAbreTudo 7
int flag_botaoAbreTudo = 1;
#define botaoFechaTudo 8
int flag_botaoFechaTudo = 1;
void setup()
{
  Serial.begin(9600);
  pinMode(botaoAbreTudo, INPUT_PULLUP);
  pinMode(botaoFechaTudo, INPUT_PULLUP);
  pinMode(Ena1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(abre, INPUT_PULLUP);
  pinMode(fecha, INPUT_PULLUP);
}

void loop()
{
  //BOTÃO ABRE E FECHA CORTINA(SEGURANDO)
  if (digitalRead(abre) == 0)
  {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    analogWrite(Ena1, 120);
  }
  else if (digitalRead(fecha) == 0)
  {
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    analogWrite(Ena1, 120);
  }
  else
  {
    analogWrite(Ena1, 0);
  }
  // BOTÃO ABRE A CORTINA POR INTEIRO
  if (digitalRead(botaoAbreTudo) == 0 && flag_botaoAbreTudo == 1)
  {
    flag_botaoAbreTudo = 0;
    delay(100);
  }
  else if (digitalRead(botaoAbreTudo) == 1 && flag_botaoAbreTudo == 0)
  {
    flag_botaoAbreTudo = 1;
    delay(100);
  }
  // BOTÃO FECHA A CORTINA POR INTEIRO
  if (digitalRead(botaoFechaTudo) == 0 && flag_botaoFechaTudo == 1)
  {
    flag_botaoAbreTudo = 0;
    delay(100);
  }
  else if (digitalRead(botaoFechaTudo) == 1 && flag_botaoFechaTudo == 0)
  {
    flag_botaoFechaTudo = 1;
    delay(100);
  }
