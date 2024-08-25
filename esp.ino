#include <ESP32Servo.h>

static const int servoPin = 14; // Set the servo pin to GPIO 14
Servo servo1;

void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin);
  Serial.println("Enter an angle between -90 and 90:");
}

void loop() {
  // Check if data is available on the serial
  if (Serial.available()) {
    // Read the input value
    int inputAngle = Serial.parseInt();

    // Ensure the angle is within -90 to 90 degrees
    if (inputAngle >= -90 && inputAngle <= 90) {
      // Map the -90 to +90 range to the servo's 0 to 180 range
      int servoAngle = map(inputAngle, -90, 90, 0, 180);

      // Move the servo to the specified angle
      servo1.write(servoAngle);
      Serial.print(inputAngle);
      Serial.print(" (mapped to ");
      Serial.print(servoAngle);
      Serial.println(" degrees on the servo)");
    } else {
      // Print an error message if the input is out of range
      Serial.println("Please enter a valid angle between -90 and 90.");
    }

    // Clear the serial buffer
    while (Serial.available()) {
      Serial.read();  // Discard any remaining input
    }
  }
}
