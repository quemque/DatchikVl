#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
//sudo chmod a+rw /dev/ttyUSB0
LiquidCrystal_PCF8574 lcd(0x27);  // I2C address 0x27 or 0x3F

DHT dht(2, DHT11);  // DHT11 on Pin 2

void setup() {
  dht.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity: "); Serial.print(h); Serial.println("%");
  Serial.print("Temp: "); Serial.print(t); Serial.println("°C");

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);

  delay(2000);
}