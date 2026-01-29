#ifndef FAROIS_H
#define FAROIS_H

#include <Arduino.h>

class Farois {
public:
  Farois();

  void iniciar();

  void ligar(String qual);
  void apagar(String qual);

  void pulso(String qual, int duracao_ms);
  void piscar(String qual, int vezes, int duracao_piscada_ms);
  void piscaAlerta(int vezes, int duracao_piscada_ms);
  void alternar(int vezes, int duracao_passo_ms);

private:
  const int pinoEsquerda = 12;
  const int pinoDireita = 13;
};

#endif