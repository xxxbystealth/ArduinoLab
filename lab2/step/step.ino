#define A 3
#define _A 4
#define B 5
#define _B 6
char readChar;

volatile int state[8][4] = {
    {HIGH, LOW, LOW, LOW},
    {HIGH, HIGH, LOW, LOW},
    {LOW, HIGH, LOW, LOW},
    {LOW, HIGH, HIGH, LOW},
    {LOW, LOW, HIGH, LOW},
    {LOW, LOW, HIGH, HIGH},
    {LOW, LOW, LOW, HIGH},
    {HIGH, LOW, LOW, HIGH}};
void act(){  
  digitalWrite(2, HIGH);
  for(unsigned int i = 0; i < 700; i++){
    for(int j = 0; j < 8; j++){
      digitalWrite(A, state[j][0]);  
      digitalWrite(_A, state[j][1]);  
      digitalWrite(B, state[j][2]);  
      digitalWrite(_B, state[j][3]);  
      delayMicroseconds(17730);
    } 
  }
  for(unsigned int i = 0; i < 420; i++){
    for(int j = 7; j >= 0; j--){
      digitalWrite(A, state[j][0]);  
      digitalWrite(_A, state[j][1]);  
      digitalWrite(B, state[j][2]);  
      digitalWrite(_B, state[j][3]);  
      delayMicroseconds(17730);
    } 
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
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
