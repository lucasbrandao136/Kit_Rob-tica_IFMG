#include "SensorDeCor.h"

SensorDeCor::SensorDeCor() {}

bool SensorDeCor::iniciar() {
  // Inicia o barramento I2C padrão do Arduino
  Wire.begin(); 
  
  // Tenta encontrar o sensor no endereço 0x29
  return tcs.begin();
}

void SensorDeCor::getNormalizedRGB(int &r, int &g, int &b) {
  uint16_t r_raw, g_raw, b_raw, c_raw;
  
  tcs.setInterrupt(false);      // Liga o LED/Sensor
  delay(60);                    // Tempo para integração da luz
  tcs.getRawData(&r_raw, &g_raw, &b_raw, &c_raw);
  tcs.setInterrupt(true);       // Desliga o LED (opcional)
  
  if (c_raw == 0) { r=0; g=0; b=0; return; }
  
  // Normalização para escala 0-255
  float fator = 255.0 / c_raw;
  r = r_raw * fator;
  g = g_raw * fator;
  b = b_raw * fator;
}

void SensorDeCor::lerValoresRGB(int &r, int &g, int &b) {
  getNormalizedRGB(r, g, b);
}

String SensorDeCor::qualCor() {
  int r, g, b;
  lerValoresRGB(r, g, b);
  
  // Lógica de decisão baseada nos valores normalizados
  if (r < 40 && g < 40 && b < 40) return "Preto";
  if (r > 200 && g > 200 && b > 200) return "Branco";
  
  if (r > g && r > b) {
    if (g > 80) return "Amarelo";
    return "Vermelho";
  } 
  else if (g > r && g > b) return "Verde";
  else if (b > r && b > g) return "Azul";
  
  return "Desconhecido";
}