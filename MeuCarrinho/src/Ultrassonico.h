#ifndef ULTRASSONICO_H
#define ULTRASSONICO_H

#include <Arduino.h>

class Ultrassonico {
public:
  Ultrassonico();

  void iniciar();

  long lerDistanciaCm();

  bool compararDistancia(String operador, int distancia);

private:

  const int pinoTrigger = 4; 
  const int pinoEcho = 5;    
};

#endif