#include "Farois.h"

Farois::Farois() {}

void Farois::iniciar() {
  pinMode(pinoEsquerda, OUTPUT);
  pinMode(pinoDireita, OUTPUT);
  apagar("ambos"); 
}

void Farois::ligar(String qual) {
  if (qual == "esquerda" || qual == "ambos") {
    digitalWrite(pinoEsquerda, HIGH);
  }
  if (qual == "direita" || qual == "ambos") {
    digitalWrite(pinoDireita, HIGH);
  }
}

void Farois::apagar(String qual) {
  if (qual == "esquerda" || qual == "ambos") {
    digitalWrite(pinoEsquerda, LOW);
  }
  if (qual == "direita" || qual == "ambos") {
    digitalWrite(pinoDireita, LOW);
  }
}

void Farois::pulso(String qual, int duracao_ms) {
  ligar(qual);
  delay(duracao_ms);
  apagar(qual);
}

void Farois::piscar(String qual, int vezes, int duracao_piscada_ms) {
  for (int i = 0; i < vezes; i++) {
    ligar(qual);
    delay(duracao_piscada_ms / 2);
    apagar(qual);
    delay(duracao_piscada_ms / 2);
  }
}

void Farois::piscaAlerta(int vezes, int duracao_piscada_ms) {
  piscar("ambos", vezes, duracao_piscada_ms);
}

void Farois::alternar(int vezes, int duracao_passo_ms) {
  for (int i = 0; i < vezes; i++) {
    ligar("esquerda");
    apagar("direita");
    delay(duracao_passo_ms);
    apagar("esquerda");
    ligar("direita");
    delay(duracao_passo_ms);
  }
  apagar("ambos"); 
}