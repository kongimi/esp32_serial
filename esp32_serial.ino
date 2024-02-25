
/*
 * this code use with esp32 node32lite lamloei
 * setting by board = Node32s and upload speed = 921600
 * you can upload immidiatly without pressing the 2 button
 * serial can use only pin 16 qne 17, other can't
 * 
 */
#define RXD2 16
#define TXD2 17

int incomingByte = 0; // for incoming serial data
String string_read;
int i;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  i = 0;
}

// the loop function runs over and over again forever
void loop() {  
  if(Serial2.available())
  {
    incomingByte = Serial2.read();
    Serial2.print("*** Serial2 data: ");
    Serial2.print(incomingByte);
    Serial2.print("\n");
    
//    string_read = Serial.readString();
//    Serial.print("*** Receive String: ");
//    Serial.print(string_read);
//    Serial.print("\n");
  }
  i++;
  Serial2.print("*** Sent Value: ");
  Serial2.print(i);
  Serial2.print("\n");
  delay(1000);
  
}
