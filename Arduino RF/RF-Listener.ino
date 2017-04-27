void setup() {
  pinMode(1, INPUT)
  pinMode(12, OUTPUT)
}

void loop() {
  while (AnalougeRead(1)== HIGH){ //while rf reciver reads high
    digitalWrite(12,HIGH) //turn on light
  } 
}
