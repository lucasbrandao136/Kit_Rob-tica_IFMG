#ifndef MOTORES_H
#define MOTORES_H

#include <Arduino.h>

class Motores {
public:
  Motores();

  void iniciar();

  void frente(int velocidade);
  void tras(int velocidade);
  void virarDireita(int velocidade);
  void virarEsquerda(int velocidade);
  void parar();

  void frente(int velocidade, int tempo);
  void tras(int velocidade, int tempo);
  void virarDireita(int velocidade, int tempo);
  void virarEsquerda(int velocidade, int tempo);

  void mover(int velocidadeEsquerda, int velocidadeDireita);

private:
  // Pinos do Motor Direito
  const int pinoENA = 6;  // Pino de Velocidade (PWM) - D6
  const int pinoIN1 = 7;  // Pino de Direção 1 - D7
  const int pinoIN2 = 8;  // Pino de Direção 2 - D8

  // Pinos do Motor Esquerdo
  const int pinoENB = 11; // Pino de Velocidade (PWM) - D11
  const int pinoIN3 = 10; // Pino de Direção 3 - D10
  const int pinoIN4 = 9;  // Pino de Direção 4 - D9
};

#endif