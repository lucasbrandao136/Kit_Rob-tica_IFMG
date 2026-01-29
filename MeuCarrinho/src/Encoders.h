#ifndef ENCODERS_H
#define ENCODERS_H

#include <Arduino.h>

class Encoders {
public:
  Encoders();

  void iniciar();

  long int lerPassosEsquerda();
  long int lerPassosDireita();
  void zerarPassos(String qual = "ambos");

private:
  const int pinoEncoderE = 2; // Encoder Esquerdo no pino D2 (Interrupt 0)
  const int pinoEncoderD = 3; // Encoder Direito no pino D3 (Interrupt 1)
};

#endif