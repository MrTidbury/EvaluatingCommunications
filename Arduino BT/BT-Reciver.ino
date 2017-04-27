#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3); // RX | TX
String input;
int i;

void setup() 
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.begin(9600);
  Serial.println("Arduino with HC-06 is ready");

  // HC-06 default baud rate is 9600
  BTSerial.begin(9600);  
  Serial.println("BTserial started at 9600");
}

void loop()
{
  String inBUffer;
  while (BTSerial.available() > 0) {

    Serial.print(BTSerial.read());
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(50);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }

};

