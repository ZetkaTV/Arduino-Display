#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  analogWrite(9, 30);

}

void loop() {
  if (Serial.available() > 0) {
    // Read the CPU and memory usage from the serial port
    int cpuUsage = Serial.parseInt();
    int memUsage = Serial.parseInt();

    // Clear the LCD screen
    lcd.clear();

    // Display CPU Usage and Memory Usage on LCD
    lcd.setCursor(0, 0);
    lcd.print("CPU Usage: ");
    lcd.print(cpuUsage);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("RAM Usage: ");
    lcd.print(memUsage);
    lcd.print("%");

    delay(1000);
  }
}
