#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Keyboard.h> // Requires Arduino Leonardo, Micro, or Due

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

const int thumbPin = 2;
const int indexPin = 3;

void setup() {
  Wire.begin();
  Keyboard.begin();
  
  mpu.initialize();
  
  pinMode(thumbPin, INPUT_PULLUP);
  pinMode(indexPin, INPUT_PULLUP);
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  int tiltX = map(ax, -17000, 17000, -90, 90);

  if (digitalRead(indexPin) == LOW) {
    Keyboard.write('A'); 
    delay(300); 
  }
  
  if (digitalRead(thumbPin) == LOW) {
    Keyboard.write(' ');
    delay(300);
  }
  
  if (tiltX > 50) {
    Keyboard.write(KEY_RIGHT_ARROW);
    delay(200);
  } else if (tiltX < -50) {
    Keyboard.write(KEY_LEFT_ARROW);
    delay(200);
  }
  
  delay(10);
}
