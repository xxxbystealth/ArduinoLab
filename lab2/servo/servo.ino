int Control;
int change;
int readNum;;
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Control = 0;
  change = 1;
}

void loop() {
  if (Serial.available() > 0){
    readNum = Serial.read();
    if(readNum == 1)
      digitalWrite(2, HIGH);
    else
      digitalWrite(2, LOW);
  }
  for(int i = 0; i < 210; i++){
    digitalWrite(3, HIGH);
    delayMicroseconds(500 + Control);
    digitalWrite(3, LOW);
    delayMicroseconds(19500 - Control);
  }
  for(int i = 0; i < 210; i++){
    digitalWrite(3, HIGH);
    delayMicroseconds(2400 - Control);
    digitalWrite(3, LOW);
    delayMicroseconds(17600 + Control);
  }
  Control = Control + 50*change;
  if(Control <= 0 || Control >= 900)
    change = change*(-1);
}
