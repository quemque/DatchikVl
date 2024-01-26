#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int show;
DHT dht(2, DHT11);  // сообщаем на каком порту будет датчик

void setup() {
	dht.begin();            // запускаем датчик DHT11
	Serial.begin(9600);     // подключаем монитор порта
	lcd.begin(16, 2);       // у нас экран 16 столбцов на 2 строки
	lcd.setBacklight(255);  //установить яркость подсветки на максимум
	lcd.clear();            // очистить экран и установить курсор в позицию 0, 0
}

void loop() {
	float h = dht.readHumidity();     // считываем влажность
	float t = dht.readTemperature();  // считываем температуру

	Serial.println(h);
	Serial.println(t);
	lcd.setCursor(0, 0);     // переводим курсор в нужную позицию
	lcd.print("Humidity:");  // печатаем нужную строку
	lcd.setCursor(10, 0);
	lcd.print(h);

	lcd.setCursor(0, 1);        // переводим курсор на вторую строку
	lcd.print("Temperature:");  // печатаем нужную строку
	lcd.setCursor(13, 1);
	lcd.print(t);

	delay(2000);  // задержка для стабилизации значений и предотвращения частого обновления экрана
}