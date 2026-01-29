#ifndef SEGUIDORLINHA_H
#define SEGUIDORLINHA_H

#include <Arduino.h>

class SeguidorLinha {
public:
  SeguidorLinha();

  void iniciar();
  void calibrar(int duracao_ms = 5000);
  void definirLimiar(int limiar); 

  int lerValorEsquerda();
  int lerValorMeio();
  int lerValorDireita();

  int lerEstadoEsquerda();
  int lerEstadoMeio();
  int lerEstadoDireita();

  bool naLinhaEsquerda();
  bool naLinhaMeio();
  bool naLinhaDireita();

  bool todosSensoresEstao(String cor);
  
  int lerPosicao();

private:
  // Pinos dos sensores
  const int pinoEsquerda = A1;
  const int pinoMeio = A2;
  const int pinoDireita = A3;

  // Limiar (threshold) de cada sensor, calculado na calibração
  int limiarE, limiarM, limiarD;
};

#endif