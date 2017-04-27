const int TRIG_PIN = 12;
const int ECHO_PIN = 11;

#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST = 23200;
float lastcm;
void setup() {

  // The Trigger pin will tell the sensor to range find
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);

  // We'll use the serial monitor to view the sensor output
  Serial.begin(9600);
  BTserial.begin(9600); 
}

void loop() {

  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm;
  float inches;
  float diff;
  
  // Hold the trigger pin high for at least 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width)
  // Note: the () microscounter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

  // Calculate distance in centimeters and inches. The constants
  // are found in the datasheet, and calculated from the assumed speed 
  //of sound in air at sea level (~340 m/s).
  cm = pulse_width / 58.0;
  diff = cm - lastcm;
  lastcm = cm;
  
  // Print out results
  if ( pulse_width > MAX_DIST ) {
    BTserial.write("Out of range");
    lastcm = cm;
  } else {
    
    lastcm = cm;
    if (abs(diff)>15) {
      Serial.println(cm);
      BTserial.println(cm);
      delay(1000);
      }
      

  }
  
  // Wait at least 60ms before next measurement
  delay(300);
}

};

