#include "SensorDeLuz.h"

SensorDeLuz::SensorDeLuz() {
}

void SensorDeLuz::iniciar() {
  pinMode(pinoLDR, INPUT);
}

void SensorDeLuz::definirLimiar(int porcentagem) {
  if (porcentagem < 0) porcentagem = 0;
  if (porcentagem > 100) porcentagem = 100;
  
  limiarLuz = porcentagem;
}

int SensorDeLuz::lerValorBruto() {
  return analogRead(pinoLDR);
}

int SensorDeLuz::lerLuminosidade() {
  int valorBruto = lerValorBruto();
  
  int porcentagem = map(valorBruto, 0, 1023, 100, 0);
  
  return porcentagem;
}

bool SensorDeLuz::estaClaro() {
  return lerLuminosidade() > limiarLuz;
}

bool SensorDeLuz::estaEscuro() {
  return lerLuminosidade() <= limiarLuz;
}