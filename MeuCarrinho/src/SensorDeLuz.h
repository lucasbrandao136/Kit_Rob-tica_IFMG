#ifndef SENSOR_DE_LUZ_H
#define SENSOR_DE_LUZ_H

#include <Arduino.h>

class SensorDeLuz {
public:
  SensorDeLuz();


  void iniciar();
  void definirLimiar(int porcentagem); 

  int lerValorBruto();    
  int lerLuminosidade();        
  bool estaClaro();           
  bool estaEscuro();           

private:
  const int pinoLDR = A0;      // Pino de leitura do sensor
  int limiarLuz = 50;          // Limiar padrão em porcentagem (50%)
};

#endif