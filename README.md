# Display OLED com Arduino

Projeto desenvolvido em **Arduino/C++** para controlar um display **OLED SSD1306 de 128x64 pixels** utilizando comunicação **I2C**.

O programa inicializa o display e exibe a mensagem **"Raphael Campos Squilaro"** na tela.

## 📋 Sobre o projeto

Este projeto demonstra como:

- Inicializar um display OLED SSD1306;
- Utilizar comunicação I2C;
- Configurar o tamanho e a cor do texto;
- Definir a posição do texto no display;
- Exibir uma mensagem no OLED;
- Utilizar o Monitor Serial para informar possíveis erros na inicialização.

## 🛠️ Componentes

Para executar o projeto, são necessários:

- Arduino compatível;
- Display OLED SSD1306 128x64;
- Cabos jumper;
- Protoboard, opcional;
- Cabo USB para programação do Arduino.

## 📚 Bibliotecas utilizadas

O projeto utiliza três bibliotecas:

### Wire

Biblioteca responsável pela comunicação **I2C** entre o Arduino e o display OLED.

```cpp
#include <Wire.h>
```

### Adafruit GFX

Biblioteca gráfica utilizada como base para desenhar textos e elementos gráficos no display.

```cpp
#include <Adafruit_GFX.h>
```

### Adafruit SSD1306

Biblioteca responsável pelo controle do display OLED baseado no controlador SSD1306.

```cpp
#include <Adafruit_SSD1306.h>
```

## 🔌 Comunicação I2C

O display é configurado para utilizar comunicação I2C através da biblioteca `Wire`.

No código, o display é criado da seguinte forma:

```cpp
Adafruit_SSD1306 telaOLED(
  LARGURA_OLED,
  ALTURA_OLED,
  &Wire,
  -1
);
```

O endereço I2C utilizado neste projeto é:

```text
0x3C
```

Esse é um endereço bastante comum em displays OLED SSD1306, mas pode variar dependendo do módulo utilizado.

## 🖥️ Configuração do display

O display possui resolução de:

```cpp
#define LARGURA_OLED 128
#define ALTURA_OLED 64
```

Portanto, sua resolução é:

**128 × 64 pixels**

O código também informa que o módulo não possui um pino de reset dedicado:

```cpp
-1
```

## ⚙️ Funcionamento

Durante a execução, o programa realiza as seguintes etapas:

1. Inicializa a comunicação serial em `9600 baud`;
2. Inicializa o display OLED;
3. Verifica se o display foi inicializado corretamente;
4. Configura o tamanho do texto;
5. Define a cor do texto;
6. Limpa o conteúdo anterior da tela;
7. Define a posição inicial do texto;
8. Escreve a mensagem no buffer do display;
9. Envia o conteúdo para o OLED.

## 💻 Código

```cpp
#include <Wire.h>              // Biblioteca I2C
#include <Adafruit_GFX.h>     // Biblioteca gráfica
#include <Adafruit_SSD1306.h> // Biblioteca do OLED

// -------- Configuração do OLED --------
#define LARGURA_OLED 128
#define ALTURA_OLED 64

// -------- Criação do display OLED --------
Adafruit_SSD1306 telaOLED(
  LARGURA_OLED,
  ALTURA_OLED,
  &Wire,  // Comunicação com I2C
  -1      // Sem pino de reset dedicado
);

void setup() {

  // Inicia monitor serial
  Serial.begin(9600);

  // Inicia display OLED
  if (!telaOLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erro ao iniciar o OLED");

    for (;;) {
      // Para a execução caso o OLED não seja inicializado
    }
  }

  // Define o tamanho do texto
  telaOLED.setTextSize(2);

  // Define a cor do texto
  telaOLED.setTextColor(WHITE);

  // Limpa a tela
  telaOLED.clearDisplay();

  // Define a posição do texto
  telaOLED.setCursor(0, 10);

  // Mensagem
  telaOLED.println("Raphael Campos Squilaro");

  // Envia o conteúdo para o display
  telaOLED.display();
}

void loop() {
  // Não é necessário executar nenhuma operação continuamente
}
```

## ▶️ Como executar

### 1. Instale a Arduino IDE

Instale a **Arduino IDE** e conecte o Arduino ao computador através do cabo USB.

### 2. Instale as bibliotecas

No gerenciador de bibliotecas da Arduino IDE, procure e instale:

- `Adafruit GFX Library`
- `Adafruit SSD1306`

A biblioteca `Wire` normalmente já acompanha a instalação da Arduino IDE.

### 3. Conecte o display

Conecte o OLED ao Arduino utilizando os pinos correspondentes à comunicação I2C da sua placa.

A ligação básica possui:

| OLED | Arduino |
|---|---|
| VCC | Alimentação compatível |
| GND | GND |
| SDA | SDA |
| SCL | SCL |

> Os pinos específicos de SDA e SCL variam de acordo com o modelo da placa Arduino.

### 4. Carregue o código

Abra o código na Arduino IDE, selecione:

- A placa correta;
- A porta serial correta.

Depois clique em **Upload**.

## 🖼️ Resultado esperado

Após a inicialização, o display deverá apresentar a mensagem:

```text
Raphael Campos
Squilaro
```

A quebra visual pode ocorrer porque o texto possui mais caracteres do que cabem em uma única linha com tamanho de fonte `2`.

## 📡 Monitor Serial

O programa utiliza:

```cpp
Serial.begin(9600);
```

Caso o display não consiga ser inicializado, será exibida a mensagem:

```text
Erro ao iniciar o OLED
```

Depois disso, o programa permanece parado devido ao:

```cpp
for (;;) {
}
```

## 🧠 Principais conceitos

Este projeto trabalha alguns conceitos importantes de Arduino:

- **I2C** — comunicação entre dispositivos;
- **OLED** — display de matriz de pixels;
- **SSD1306** — controlador utilizado pelo display;
- **Bibliotecas** — reutilização de funcionalidades;
- **`setup()`** — executado uma vez na inicialização;
- **`loop()`** — executado continuamente;
- **Monitor Serial** — comunicação entre Arduino e computador;
- **Buffer do display** — conteúdo preparado antes de ser enviado ao OLED.

## 🚀 Possíveis melhorias

O projeto pode ser expandido para:

- Exibir sensores no OLED;
- Criar menus;
- Mostrar temperatura e umidade;
- Criar animações;
- Exibir gráficos;
- Utilizar botões para interação;
- Adicionar relógio digital;
- Exibir diferentes telas;
- Criar interfaces para projetos IoT.

## 📄 Licença

Este projeto é destinado a fins educacionais e de aprendizado com Arduino, comunicação I2C e displays OLED.
