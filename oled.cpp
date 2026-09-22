#include <Wire.h> //biblioteca I2C
#include <Adafruit_GFX.h>  //biblioteca gráfica
#include <Adafruit_SSD1306.h>  //biblioteca do OLED4

// -------- Configuração do OLED --------
#define LARGURA_OLED 128
#define ALTURA_OLED 64

// -------- Criação do display OLED --------
Adafruit_SSD1306 telaOLED(
  LARGURA_OLED,
  ALTURA_OLED,
  &Wire,  //Comunicação com I2C
  -1      //Sem pino de reset dedicado
);

void setup() {
  // Inicia monitor serial
  Serial.begin(9600);

  //Iniciar display OLED
  if (!telaOLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erro ao iniciar o OLED");
    for(;;);
  }

  //Definindo o tamanho do texto
  telaOLED.setTextSize(2);

  //Definindo a cor do texto
  telaOLED.setTextColor(WHITE);

  //Limpa a tela
  telaOLED.clearDisplay();

  //Definindo a posição do texto
  telaOLED.setCursor(0, 10);

  //Mensagem
  telaOLED.println("Raphael Campos Squilaro");

  //Envia para o display
  telaOLED.display();
}

void loop() {
  //não precisa inserir nada no momento 
}
