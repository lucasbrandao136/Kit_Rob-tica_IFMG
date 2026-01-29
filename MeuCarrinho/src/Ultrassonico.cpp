#include "Ultrassonico.h"

Ultrassonico::Ultrassonico() {
}

void Ultrassonico::iniciar() {
  pinMode(pinoTrigger, OUTPUT);
  pinMode(pinoEcho, INPUT);
}

long Ultrassonico::lerDistanciaCm() {
  digitalWrite(pinoTrigger, LOW);
  delayMicroseconds(2);

  digitalWrite(pinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrigger, LOW);

  long duracao = pulseIn(pinoEcho, HIGH);

  // Duração * velocidade do som (0.034 cm/µs) / 2
  long distancia = duracao * 0.034 / 2;

  return distancia;
}

bool Ultrassonico::compararDistancia(String operador, int distancia) {
  long distanciaAtual = lerDistanciaCm();

  if (operador == ">") {
    return distanciaAtual > distancia;
  }
  if (operador == "<") {
    return distanciaAtual < distancia;
  }
  if (operador == ">=") {
    return distanciaAtual >= distancia;
  }
  if (operador == "<=") {
    return distanciaAtual <= distancia;
  }
  if (operador == "==") {
    return distanciaAtual == distancia;
  }
  if (operador == "!=") {
    return distanciaAtual != distancia;
  }

  return false;
}