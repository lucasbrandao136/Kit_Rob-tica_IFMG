#ifndef SENSORDECOR_H
#define SENSORDECOR_H

#include <Arduino.h>
#include <Wire.h> 
#include "Adafruit_TCS34725.h"

class SensorDeCor {
public:
  SensorDeCor();

  // Inicia o sensor no barramento padrão (A4/A5)
  bool iniciar();

  // Funções de leitura
  String qualCor();
  void lerValoresRGB(int &r, int &g, int &b);

private:
  Adafruit_TCS34725 tcs; // Objeto do sensor usando barramento Wire padrão

  // Função interna de processamento
  void getNormalizedRGB(int &r, int &g, int &b);
};

#endif