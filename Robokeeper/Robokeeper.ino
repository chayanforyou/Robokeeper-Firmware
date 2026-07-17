#include "BluetoothSerial.h"
#include <ESP32Servo.h>

// Check if Bluetooth is properly configured in the ESP32 core
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run menuconfig to enable it
#endif

BluetoothSerial SerialBT;
Servo myServo;

// Configuration
const int SERVO_PIN = 13;       // ESP32 GPIO pin connected to the Servo signal wire

void setup() {
  Serial.begin(115200);

  // Initialize Bluetooth with the device name
  SerialBT.begin("Robokeeper-ESP32");
  Serial.println("Bluetooth started. Ready to pair with your phone.");

  // Attach the servo pin
  myServo.attach(SERVO_PIN);

  // Move servo to default starting position (center)
  myServo.write(90);
}

void loop() {
  // If data is available from Bluetooth
  if (SerialBT.available() > 0) {
    char buffer[16]; // Buffer to store incoming digits

    // Read bytes until newline, bounding it to prevent overflow
    int len = SerialBT.readBytesUntil('\n', buffer, sizeof(buffer) - 1);
    buffer[len] = '\0'; // Null-terminate the string

    if (len > 0) {
      int targetAngle = atoi(buffer); // Convert string to integer

      int moveAngle = 90;
      if (targetAngle < 80) {
        moveAngle = 0;
      } else if (targetAngle > 100) {
        moveAngle = 180;
      }

      Serial.print("Moving servo to: ");
      Serial.println(moveAngle);

      // Control the servo
      myServo.write(moveAngle);
    }
  }
}
