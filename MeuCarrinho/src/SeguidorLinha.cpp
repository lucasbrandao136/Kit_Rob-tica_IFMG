#include "SeguidorLinha.h"

SeguidorLinha::SeguidorLinha() {
  limiarE = 500;
  limiarM = 500;
  limiarD = 500;
}

void SeguidorLinha::iniciar() {
  pinMode(pinoEsquerda, INPUT);
  pinMode(pinoMeio, INPUT);
  pinMode(pinoDireita, INPUT);
}

void SeguidorLinha::definirLimiar(int limiar) {
  limiarE = limiar;
  limiarM = limiar;
  limiarD = limiar;
}
void SeguidorLinha::calibrar(int duracao_ms) {
  int minValores[] = {1023, 1023, 1023};
  int maxValores[] = {0, 0, 0};

  unsigned long tempoInicio = millis();

  while (millis() - tempoInicio < duracao_ms) {
    int valE = lerValorEsquerda();
    int valM = lerValorMeio();
    int valD = lerValorDireita();

    if (valE < minValores[0]) minValores[0] = valE;
    if (valM < minValores[1]) minValores[1] = valM;
    if (valD < minValores[2]) minValores[2] = valD;

    if (valE > maxValores[0]) maxValores[0] = valE;
    if (valM > maxValores[1]) maxValores[1] = valM;
    if (valD > maxValores[2]) maxValores[2] = valD;
  }

  limiarE = (minValores[0] + maxValores[0]) / 2;
  limiarM = (minValores[1] + maxValores[1]) / 2;
  limiarD = (minValores[2] + maxValores[2]) / 2;
}


int SeguidorLinha::lerValorEsquerda() { return analogRead(pinoEsquerda); }
int SeguidorLinha::lerValorMeio()    { return analogRead(pinoMeio); }
int SeguidorLinha::lerValorDireita()  { return analogRead(pinoDireita); }

// linha é PRETA (valor baixo) e o fundo é BRANCO (valor alto)
bool SeguidorLinha::naLinhaEsquerda() { return lerValorEsquerda() < limiarE; }
bool SeguidorLinha::naLinhaMeio()    { return lerValorMeio() < limiarM; }
bool SeguidorLinha::naLinhaDireita()  { return lerValorDireita() < limiarD; }

int SeguidorLinha::lerEstadoEsquerda() { return naLinhaEsquerda() ? 1 : 0; }
int SeguidorLinha::lerEstadoMeio()    { return naLinhaMeio() ? 1 : 0; }
int SeguidorLinha::lerEstadoDireita()  { return naLinhaDireita() ? 1 : 0; }

bool SeguidorLinha::todosSensoresEstao(String cor) {
  bool e = naLinhaEsquerda();
  bool m = naLinhaMeio();
  bool d = naLinhaDireita();

  if (cor == "preto") {
    return e && m && d;
  }
  if (cor == "branco") {
    return !e && !m && !d;
  }
  return false; 
}

int SeguidorLinha::lerPosicao() {
  bool e = naLinhaEsquerda();
  bool m = naLinhaMeio();
  bool d = naLinhaDireita();

  if (!e && !m && !d) return 0; 

  if (!e && m && !d) return 0;   // Centralizado
  
  if ( e && m && !d) return -1;  // Pouco à esquerda
  if ( e && !m && !d) return -2;  // Totalmente à esquerda

  if (!e && m &&  d) return 1;   // Pouco à direita
  if (!e && !m &&  d) return 2;   // Totalmente à direita

  // Casos extras (ex: todos na linha, ou só as pontas) podem ser tratados aqui
  // Por simplicidade, se todos estiverem na linha, consideramos como centralizado
  if (e && m && d) return 0;

  return 99; 
}