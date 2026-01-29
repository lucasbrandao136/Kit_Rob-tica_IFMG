#ifndef MEUCARRINHO_H
#define MEUCARRINHO_H

#include "Motores.h"
#include "Ultrassonico.h"
#include "SeguidorLinha.h"
#include "SensorDeLuz.h" 
#include "SensorDeCor.h" 
#include "Farois.h"
#include "Encoders.h"

class MeuCarrinho {
public:
  Motores motores;
  Ultrassonico sensorDistancia;
  SeguidorLinha seguidor;
  SensorDeLuz sensorLuz;
  Farois farois;
  SensorDeCor sensorCor;
  Encoders encoders;

  MeuCarrinho();

  void iniciar();
};

#endif