#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
Adafruit_MPU6050 mpu2;

// This program assumes the MPU6050 is connected to the Wire2 I2C
// pins on the Teensy (SCL to pin 24 and SDA to pin 25).

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    delay(10);

  Serial.println("Adafruit MPU6050 test!");

  if (!mpu.begin(0x68, &Wire2, 1L))
  {
    Serial.println("Failed to find MPU6050 chip");
    while (1)
    {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  if (!mpu2.begin(0x69, &Wire2, 2L))
  {
    Serial.println("Failed to find second MPU6050 chip");
    while (1)
    {
      delay(10);
    }
  }
  Serial.println("Second MPU6050 Found!");

  // setupt motion detection
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true); // Keep it latched.  Will turn off when reinitialized.
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);
  mpu2.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu2.setMotionDetectionThreshold(1);
  mpu2.setMotionDetectionDuration(20);
  mpu2.setInterruptPinLatch(true); // Keep it latched.  Will turn off when reinitialized.
  mpu2.setInterruptPinPolarity(true);
  mpu2.setMotionInterrupt(true);

  Serial.println("");
  delay(1000);
}

void loop()
{
  // put your main code here, to run repeatedly:

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("AccelX1:");
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print("AccelY1:");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print("AccelZ1:");
  Serial.print(a.acceleration.z);
  Serial.print(", ");
  Serial.print("GyroX1:");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print("GyroY1:");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print("GyroZ1:");
  Serial.print(g.gyro.z);
  Serial.println("");
  Serial.println("");
  Serial.println("");

  mpu2.getEvent(&a, &g, &temp);
  Serial.print("AccelX2:");
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print("AccelY2:");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print("AccelZ2:");
  Serial.print(a.acceleration.z);
  Serial.print(", ");
  Serial.print("GyroX2:");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print("GyroY2:");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print("GyroZ2:");
  Serial.print(g.gyro.z);
  Serial.println("");

  delay(1000);
}