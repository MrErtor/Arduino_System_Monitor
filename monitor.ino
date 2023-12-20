// Library for working with text display
#include <LiquidCrystal.h>
#include <Wire.h>

// Set the name of the display pins
constexpr uint8_t PIN_RS = 6;
constexpr uint8_t PIN_EN = 7;
constexpr uint8_t PIN_DB4 = 8;
constexpr uint8_t PIN_DB5 = 9;
constexpr uint8_t PIN_DB6 = 10;
constexpr uint8_t PIN_DB7 = 11;

LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_DB4, PIN_DB5, PIN_DB6, PIN_DB7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("System Monitor");
  lcd.setCursor(0, 1);
  lcd.print("by ErtorWorld");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Reading information about the computer's processor and memory load from the serial port
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    // Data parsing
    int pos = data.indexOf(',');
    if (pos != -1) {
      String cpuUsageStr = data.substring(0, pos);
      String ramUsedStr = data.substring(pos + 1);

      float cpuUsage = cpuUsageStr.toFloat();
      float ramUsedMB = ramUsedStr.toFloat();

      // Displaying information on the LCD display
      lcd.setCursor(0, 0);
      lcd.print("CPU: ");
      lcd.print(cpuUsage, 1);  // Output one decimal place
      lcd.print("%");

      lcd.setCursor(0, 1);
      lcd.print("RAM: ");
      lcd.print(ramUsedMB, 2);  // Limit output to two decimal places
      lcd.print(" MB   ");
    }
  }

  delay(1000);  // Pause 1 second
}