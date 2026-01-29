#include "MeuCarrinho.h"

MeuCarrinho::MeuCarrinho() {
}

void MeuCarrinho::iniciar() {
  motores.iniciar();
  sensorDistancia.iniciar();
  seguidor.iniciar();
  sensorLuz.iniciar();
  farois.iniciar();
  encoders.iniciar();
}