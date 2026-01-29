#include "Motores.h"

Motores::Motores() {
}

void Motores::iniciar() {
  pinMode(pinoENA, OUTPUT);
  pinMode(pinoIN1, OUTPUT);
  pinMode(pinoIN2, OUTPUT);
  pinMode(pinoENB, OUTPUT);
  pinMode(pinoIN3, OUTPUT);
  pinMode(pinoIN4, OUTPUT);

  parar();
}


void Motores::frente(int velocidade) {
  // Motor Direito 
  digitalWrite(pinoIN1, HIGH);
  digitalWrite(pinoIN2, LOW);
  analogWrite(pinoENA, velocidade);

  // Motor Esquerdo 
  digitalWrite(pinoIN3, HIGH);
  digitalWrite(pinoIN4, LOW);
  analogWrite(pinoENB, velocidade);
}

void Motores::tras(int velocidade) {
  // Motor Direito 
  digitalWrite(pinoIN1, LOW);
  digitalWrite(pinoIN2, HIGH);
  analogWrite(pinoENA, velocidade);

  // Motor Esquerdo 
  digitalWrite(pinoIN3, LOW);
  digitalWrite(pinoIN4, HIGH);
  analogWrite(pinoENB, velocidade);
}

void Motores::parar() {
  // Desliga a energia dos dois motores
  analogWrite(pinoENA, 0);
  analogWrite(pinoENB, 0);
  digitalWrite(pinoIN1, LOW);
  digitalWrite(pinoIN2, LOW);
  digitalWrite(pinoIN3, LOW);
  digitalWrite(pinoIN4, LOW);
}

void Motores::virarDireita(int velocidade) {
  // Motor Direito 
  digitalWrite(pinoIN1, LOW);
  digitalWrite(pinoIN2, HIGH);
  analogWrite(pinoENA, velocidade);

  // Motor Esquerdo 
  digitalWrite(pinoIN3, HIGH);
  digitalWrite(pinoIN4, LOW);
  analogWrite(pinoENB, velocidade);
}

void Motores::virarEsquerda(int velocidade) {
  // Motor Direito 
  digitalWrite(pinoIN1, HIGH);
  digitalWrite(pinoIN2, LOW);
  analogWrite(pinoENA, velocidade);

  // Motor Esquerdo 
  digitalWrite(pinoIN3, LOW);
  digitalWrite(pinoIN4, HIGH);
  analogWrite(pinoENB, velocidade);
}



void Motores::frente(int velocidade, int tempo) {
  frente(velocidade);
  delay(tempo);
  parar();
}

void Motores::tras(int velocidade, int tempo) {
  tras(velocidade);
  delay(tempo);
  parar();
}

void Motores::virarDireita(int velocidade, int tempo) {
  virarDireita(velocidade);
  delay(tempo);
  parar();
}

void Motores::virarEsquerda(int velocidade, int tempo) {
  virarEsquerda(velocidade);
  delay(tempo);
  parar();
}

void Motores::mover(int velocidadeEsquerda, int velocidadeDireita) {
  
  //  Esquerdo 
  if (velocidadeEsquerda > 0)  {
  } else if (velocidadeEsquerda < 0) {
    digitalWrite(pinoIN3, LOW);
    digitalWrite(pinoIN4, HIGH);
    analogWrite(pinoENB, -velocidadeEsquerda);
  } else {
    // parar
    digitalWrite(pinoIN3, LOW);
    digitalWrite(pinoIN4, LOW);
    analogWrite(pinoENB, 0);
  }

  //  Direito 
  if (velocidadeDireita > 0) {

    digitalWrite(pinoIN1, HIGH);
    digitalWrite(pinoIN2, LOW);
    analogWrite(pinoENA, velocidadeDireita);
  } else if (velocidadeDireita < 0) {

    digitalWrite(pinoIN1, LOW);
    digitalWrite(pinoIN2, HIGH);
    analogWrite(pinoENA, -velocidadeDireita);
  } else {
    // parar
    digitalWrite(pinoIN1, LOW);
    digitalWrite(pinoIN2, LOW);
    analogWrite(pinoENA, 0);
  }
}

