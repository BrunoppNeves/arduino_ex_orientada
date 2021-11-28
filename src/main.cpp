#include <Arduino.h>
#define botaoAbreTudo 10
int flag_botaoAbreTudo = 1;
#define botaoFechaTudo 11
int flag_botaoFechaTudo = 1;
void setup()
{
  Serial.begin(9600);
  pinMode(botaoAbreTudo, INPUT_PULLUP);
  pinMode(botaoFechaTudo, INPUT_PULLUP);
}

void loop()
{
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