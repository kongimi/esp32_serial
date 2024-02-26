/*
 * เราสามารถเปลี่ยนขาของ serial port เป็นขาไหนก็ได้
 */

#include <HardwareSerial.h>

HardwareSerial SerialRS232_1(1);
HardwareSerial SerialRS232_2(2);

#define RXD 18
#define TXD 19
#define RXD1 25
#define TXD1 26
#define RXD2 16
#define TXD2 17

int incomingByte = 0; // for incoming serial data
String string_read;
int i;

void setup() {
  Serial.begin(9600, SERIAL_8N1, RXD, TXD);
  SerialRS232_1.begin(9600, SERIAL_8N1, RXD1, TXD1);
  SerialRS232_2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  i = 0;
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available())
  {
    incomingByte = Serial.read();
    Serial.print("*** Serial data: ");
    Serial.print(incomingByte);
    Serial.print("\n");
  }
  if(SerialRS232_1.available())
  {
    incomingByte = SerialRS232_1.read();
    SerialRS232_1.print("*** SerialRS232_1 data: ");
    SerialRS232_1.print(incomingByte);
    SerialRS232_1.print("\n");
  }
  if(SerialRS232_2.available())
  {
    incomingByte = SerialRS232_2.read();
    SerialRS232_2.print("*** SerialRS232_2 data: ");
    SerialRS232_2.print(incomingByte);
    SerialRS232_2.print("\n");
  }
  i++;
  SerialRS232_2.print("*** Sent Value: ");
  SerialRS232_2.print(i);
  SerialRS232_2.print("\n");
  delay(1000);
}
