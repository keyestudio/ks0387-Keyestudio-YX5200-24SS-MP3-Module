#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600); // Set the serial port baud rate
  Serial.begin(9600);
}

void loop() {
  // Play the first track
  mySerial.write(0x7E); // Start symbol
  mySerial.write(0xFF); // Version Number
  mySerial.write(0x06); // Data length
  mySerial.write(0x03); // Command: Play specified track
  mySerial.write((uint8_t)0x00); // Retain
  mySerial.write((uint8_t)0x00);
  mySerial.write(0x01); // Track Number
  mySerial.write(0xFE); // Check digit
  mySerial.write(0xF7); // End marker
  mySerial.write(0xEF); // End marker
  
  delay(3000); // Play for 3 seconds

  // Pause playback
  mySerial.write(0x7E);
  mySerial.write(0xFF);
  mySerial.write(0x06);
  mySerial.write(0x0E); // Command: Pause
  mySerial.write((uint8_t)0x00); // Feedback
  mySerial.write((uint8_t)0x00); //Parameters
  mySerial.write((uint8_t)0x00);
  mySerial.write(0xFE);
  mySerial.write(0xED);
  mySerial.write(0xEF);

  delay(2000); // Pause for 2 seconds
  
  // Play the next track
  mySerial.write(0x7E);
  mySerial.write(0xFF);
  mySerial.write(0x06);
  mySerial.write(0x01); // Command: Next track
  mySerial.write((uint8_t)0x00); // Feedback
  mySerial.write((uint8_t)0x00);
  mySerial.write((uint8_t)0x00);
  mySerial.write(0xFE);
  mySerial.write(0xFA);
  
  mySerial.write(0xEF);
  delay(3000); // Play for 3 seconds
}