#include "Encoders.h"

volatile long int contadorEsquerda;
volatile long int contadorDireita;

void ISR_EncoderEsquerdo() {
  contadorEsquerda++;
}

void ISR_EncoderDireito() {
  contadorDireita++;
}


Encoders::Encoders() {

}

void Encoders::iniciar() {
  pinMode(pinoEncoderE, INPUT_PULLUP);
  pinMode(pinoEncoderD, INPUT_PULLUP);

  zerarPassos("ambos");

  attachInterrupt(digitalPinToInterrupt(pinoEncoderE), ISR_EncoderEsquerdo, RISING);
  attachInterrupt(digitalPinToInterrupt(pinoEncoderD), ISR_EncoderDireito, RISING);
}

long int Encoders::lerPassosEsquerda() {
  return contadorEsquerda;
}

long int Encoders::lerPassosDireita() {
  return contadorDireita;
}

void Encoders::zerarPassos(String qual) {
  if (qual == "esquerda" || qual == "ambos") {
    contadorEsquerda = 0;
  }
  if (qual == "direita" || qual == "ambos") {
    contadorDireita = 0;
  }
}