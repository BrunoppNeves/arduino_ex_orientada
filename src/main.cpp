#include <Arduino.h>
#define Ena1 11 //ENABLE 1 E 2
#define IN1 10  // ENTRADA 1
#define IN2 8   // ENTRADA 2
#define abre 2
#define fecha 3
#define grava 4
#define abre_tudo 5
#define fecha_tudo 6
int flag_botao_grava = 0;
int flag_segura_botao = 0;
int flag_tempo_fixo = 0;
int flag_tempo_abre = 0;
int flag_tempo_fecha = 0;
int flag_fecha_tudo = 0;
int flag_abre_tudo = 0;
int flag_oneClickOpenAll = 0;
int flag_oneClickCloseAll = 0;
int cont1 = 0;
int cont2 = 0;
int teste1 = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(Ena1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(abre, INPUT_PULLUP);
  pinMode(fecha, INPUT_PULLUP);
  pinMode(grava, INPUT_PULLUP);
  pinMode(abre_tudo, INPUT_PULLUP);
  pinMode(fecha_tudo, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop()
{
  //VERIFICA SE O BOTÃO DE GRAVAR ESTA APERTADO
  if (digitalRead(grava) == 0)
  {
    digitalWrite(13, HIGH);
    flag_tempo_fixo++;
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    analogWrite(Ena1, 255);
    flag_tempo_abre++;
    Serial.println(flag_tempo_fixo);
  }
  // SE NÃO FOR FEITO NENHUMA GRAVAÇÃO
  else if (flag_tempo_fixo == 0)
  {
    digitalWrite(13, LOW);
  }
  //APOS A GRAVAÇÃO SER FEITA
  else if (flag_tempo_fixo != 0 && digitalRead(grava) == 1)
  {
    digitalWrite(13, LOW);
    //VERIFICA SE O CONTADOR DO BOTÃO É MENOR QUE O CONTADOR DA LEITURA GRAVADA SE FOR ELE PERMITE QUE A CORTINA ABRA
    if (digitalRead(abre) == 0 && flag_tempo_abre < flag_tempo_fixo)
    {
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);
      analogWrite(Ena1, 255);
      flag_tempo_abre++;
      flag_tempo_fecha--;
      Serial.print("abre segurando: ");
      Serial.print(flag_tempo_abre);
      Serial.print("\n");
    }
    //VERIFICA SE O CONTADOR DO BOTÃO É MENOS QUE O DA LEITURA GRAVADA SE FOR ELE PERMITE QUE A CORTINA FECHE
    else if (digitalRead(fecha) == 0 && flag_tempo_fecha < flag_tempo_fixo)
    {
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      analogWrite(Ena1, 255);
      flag_tempo_fecha++;
      flag_tempo_abre--;
      Serial.print("Fecha segurando: ");
      Serial.print(flag_tempo_fecha);
      Serial.print("\n");
    }
    // SE SOLTAR O BOTÃO OU O CONTADOR DO BOTÃO DE ABRIR FOR MAIOR ELE DESLIGA O MOTOR
    else if (digitalRead(abre) == 1 || flag_tempo_abre >= flag_tempo_fixo)
    {
      analogWrite(Ena1, 0);
    }
    // SE SOLTAR O BOTÃO OU O CONTADOR DO BOTÃO DE FECHAR FOR MAIOR ELE DELIGA O MOTOR
    else if (digitalRead(fecha) == 1 || flag_tempo_fecha >= flag_tempo_fixo)
    {
      analogWrite(Ena1, 0);
    }
    // FECHA TUDO
    if (digitalRead(fecha_tudo) == 0 && flag_oneClickCloseAll == 0)
    {
      while (cont1 < flag_tempo_fixo)
      {
        digitalWrite(IN1, 1);
        digitalWrite(IN2, 0);
        analogWrite(Ena1, 255);
        flag_tempo_abre--;
        flag_tempo_fecha++;
        cont1++;
        Serial.println(cont1);
      }
      flag_oneClickCloseAll = 1;
      delay(100);
      Serial.print("fecha tudo: ");
      Serial.print(cont1);
      Serial.print("\n");
    }
    else if (digitalRead(fecha_tudo) == 1 && flag_oneClickCloseAll == 1)
    {
      cont1 = 0;
      flag_oneClickCloseAll = 0;
      delay(100);
    }
  }
  //ABRE TUDO
  if (digitalRead(abre_tudo) == 0 && flag_oneClickOpenAll == 0)
  {
    while (cont2 < flag_tempo_fixo)
    {
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      analogWrite(Ena1, 255);
      flag_tempo_abre++;
      flag_tempo_fecha--;
      cont2++;
      Serial.println(cont2);
    }
    flag_oneClickOpenAll = 1;
    delay(100);
    Serial.print("abre tudo:");
    Serial.print(cont2);
    Serial.print("\n");
  }
  else if (digitalRead(fecha_tudo) == 1 && flag_oneClickOpenAll == 1)
  {
    cont2 = 0;
    flag_oneClickOpenAll = 0;
    delay(100);
  }
}
