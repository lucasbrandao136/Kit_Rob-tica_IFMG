# 🤖 Biblioteca MeuCarrinho

A **MeuCarrinho** é uma biblioteca customizada para Arduino, desenvolvida especificamente para facilitar a programação de robôs seguidores de linha e desviadores de obstáculos. Ela foi projetada para ser utilizada com a **PCB Shield** personalizada e conectores **JST XH**, abstraindo a complexidade do hardware e permitindo que o foco seja a lógica de controle e automação.



---

## 🚀 Funcionalidades

A biblioteca é modular e integrada, oferecendo controle simplificado para:

| Módulo | Descrição |
| :--- | :--- |
| **⚙️ Motores** | Controle de direção e velocidade (PWM) via Ponte H L298N. |
| **👁️ Seguidor de Linha** | Gestão de 3 sensores TCRT5000 com funções de calibração e posição. |
| **🦇 Ultrassônico** | Medição de distância em cm e lógica de comparação para obstáculos. |
| **☀️ Sensor de Luz** | Leitura de luminosidade (LDR) para automação de faróis. |
| **💡 Faróis** | Efeitos visuais como pisca-alerta, pulsos e sinalização de viatura. |
| **🎨 Sensor de Cor** | Identificação de padrões RGB (Vermelho, Verde, Azul, etc) via I2C padrão. |
| **🏎️ Encoders** | Medição precisa de passos e distância percorrida por roda. |

---

## 🛠️ Instalação

1.  Faça o download deste repositório como ZIP.
2.  Extraia a pasta e mova a subpasta `MeuCarrinho` para o diretório de bibliotecas do seu Arduino (geralmente em `Documentos/Arduino/libraries`).
3.  Certifique-se de que a estrutura seja `libraries/MeuCarrinho/src/...`.
4.  Reinicie a sua IDE do Arduino.
5.  No seu código, inclua a biblioteca: `#include <MeuCarrinho.h>`.

---
