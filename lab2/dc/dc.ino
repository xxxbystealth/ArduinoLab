char readChar;

void act(){  
  digitalWrite(2, HIGH);
  delay(5000);
  digitalWrite(2, LOW);
  delay(3000);
}
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  readChar = '0';
}

void loop() {
  if(readChar == '1')
    act();
  else
    digitalWrite(2, LOW);
  if (Serial.available() > 0){
    readChar = Serial.read();
    Serial.print(readChar);
  }
}
