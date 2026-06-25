#include <Servo.h>

Servo servo;
int currentAngle = 90;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo.write(currentAngle);
  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    int newAngle = input.toInt();
    
    if (newAngle >= 0 && newAngle <= 180) {
      if (newAngle != currentAngle) {
        if (newAngle > currentAngle) {
          for (int angle = currentAngle; angle <= newAngle; angle++) {
            servo.write(angle);
            delay(10);
          }
        } else {
          for (int angle = currentAngle; angle >= newAngle; angle--) {
            servo.write(angle);
            delay(10);
          }
        }
        currentAngle = newAngle;
      } else {
        Serial.println("Уже в этом положении");
      }
    } else {
      Serial.println("Ошибка");
    }
  }
}