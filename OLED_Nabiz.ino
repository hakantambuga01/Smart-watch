int sayi;
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display;
const int nabizPin = A6;
int buzzer = 4;

int nabiz, nabiz_degeri, i;

const unsigned char PROGMEM elektromanyetix [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F,
  0x80, 0x00, 0x00, 0x00, 0xFE, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0xFE, 0x3F, 0xC0, 0x00, 0x00, 0x01,
  0xFE, 0x3F, 0xC0, 0x00, 0x00, 0x01, 0xF8, 0x7F, 0xE0, 0x00, 0x00, 0x03, 0x00, 0xE0, 0x70, 0x00,
  0x00, 0x1C, 0x03, 0x80, 0x1C, 0x00, 0x01, 0xF8, 0x7F, 0x00, 0x0F, 0xE0, 0x03, 0xF8, 0xFF, 0x00,
  0x07, 0xF0, 0x07, 0xF8, 0xFE, 0x00, 0x07, 0xF0, 0x07, 0xF8, 0xFE, 0x00, 0x07, 0xF0, 0x03, 0xF8,
  0xFC, 0x00, 0x03, 0xF0, 0x01, 0xFC, 0x38, 0x00, 0x00, 0xC0, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x03, 0xE1, 0xFC, 0x0F, 0x80, 0x00, 0x07, 0xF1, 0xFE, 0x1F,
  0xC0, 0x00, 0x07, 0xF8, 0xFE, 0x3F, 0xC0, 0x00, 0x07, 0xF8, 0xFE, 0x3F, 0xC0, 0x00, 0x03, 0xF8,
  0x7C, 0x3F, 0x80, 0x00, 0x00, 0xFC, 0x10, 0x7E, 0x00, 0x00, 0x00, 0x06, 0x00, 0xC0, 0x00, 0x00,
  0x00, 0x03, 0xC7, 0x80, 0x00, 0x00, 0x03, 0xF1, 0xFF, 0x00, 0x00, 0x00, 0x07, 0xF1, 0xFE, 0x00,
  0x00, 0x00, 0x07, 0xF8, 0xFE, 0x00, 0x00, 0x00, 0x07, 0xF0, 0xFE, 0x00, 0x00, 0x00, 0x03, 0xE0,
  0x7C, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x01, 0xC0, 0x30, 0x00, 0x00, 0xC0, 0x03, 0xF0, 0xFC, 0x00, 0x03, 0xF0, 0x07, 0xF0, 0xFE, 0x00,
  0x07, 0xF0, 0x07, 0xF8, 0xFE, 0x00, 0x07, 0xF0, 0x07, 0xF8, 0xFF, 0x00, 0x07, 0xF0, 0x03, 0xF8,
  0x7F, 0x00, 0x0F, 0xE0, 0x00, 0x1C, 0x03, 0x80, 0x1C, 0x00, 0x00, 0x07, 0x00, 0xC0, 0x30, 0x00,
  0x00, 0x01, 0xF8, 0x7F, 0xE0, 0x00, 0x00, 0x01, 0xFC, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0xFE, 0x3F,
  0xC0, 0x00, 0x00, 0x00, 0xFE, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x80, 0x00, 0x00, 0x00,
  0x7C, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.begin();

  Serial.begin(9600);
  // miniature bitmap display
  //  display.clearDisplay();
  //  display.drawBitmap(0, 0, elektromanyetix, 48, 48, WHITE);
  //  display.setTextColor(WHITE);
  //  display.setTextSize(3);
  //  display.setCursor(60, 5);
  //  display.print("ASA");
  //  //  display.setCursor(60,5);
  //  //  display.print("Elektronik,");
  //  //  display.setCursor(60,20);
  //  //  display.print("Bilim ve");
  //  //  display.setCursor(60,35);
  //  //  display.print("Teknoloji");
  //  display.display();
  ////  delay(2000);
  display.clearDisplay();
  digitalWrite(buzzer, LOW);
}


void loop() {
  nabiz = analogRead(nabizPin);
  //    Serial.println(nabiz);
  if ((nabiz > 600) && (nabiz < 950))
  {
    i = 0;
    digitalWrite(buzzer, LOW);
    nabiz_degeri = map(nabiz, 600, 950, 74, 85.);
    display.display();
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(40, 10);
    display.println(nabiz_degeri);
    Serial.flush();
    Serial.print(" :  ");
    Serial.print(nabiz_degeri);
    Serial.println("BPM");
    display.setTextSize(1);
    display.setCursor(80, 17);
    display.println("BPM");
    delay(1000);
  }
  if (nabiz < 600)
  {
    i++;
    delay(10);
    if (i >= 300)
    {
      display.display();
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(10, 10);
      display.println("LOW PULSE");
      Serial.flush();
      Serial.print(" DUSUK NABIZ");
      i = 0;
      digitalWrite(buzzer, HIGH);
      delay(100);

      //      digitalWrite(buzzer, LOW);
    }
  }
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("     E.E.Engineering");
  display.display();

}
