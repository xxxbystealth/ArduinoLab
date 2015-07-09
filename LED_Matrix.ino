#define rows 8
#define columns 7
typedef struct {
  char key;
  void (* functionPtr)();
} functionObject;

functionObject alphabet[26] = {
  {'A', patternA}, {'B', patternB}, {'C', patternC}, {'D', patternD},
  {'E', patternE}, {'F', patternF}, {'G', patternG}, {'H', patternH},
  {'I', patternI}, {'J', patternJ}, {'K', patternK}, {'L', patternL},
  {'M', patternM}, {'N', patternN}, {'O', patternO}, {'P', patternP},
  {'Q', patternQ}, {'R', patternR}, {'S', patternS}, {'T', patternT},
  {'U', patternU}, {'V', patternV}, {'W', patternW}, {'X', patternX},
  {'Y', patternY}, {'Z', patternZ}};
  
boolean pattern[columns][rows]= {
   {false, false, false, false, false, false, false, false},
   {false, false, false, false, false, false, false, false},
   {false, false, false, false, false, false, false, false},
   {false, false, false, false, false, false, false, false},
   {false, false, false, false, false, false, false, false},
   {false, false, false, false, false, false, false, false},
   {false, false, false, false, false, false, false, false}};

boolean firstLevel[columns][3] = {//3-bit channel select signal
   {false, false, true}, {false, true, false}, {false, true, true},
   {true, false, false}, {true, false, true}, {true, true, false},
   {true, true, true}};//channel_1to channel_7 (channel_0 unused)
   
boolean secondLevel[rows][3] = {//3-bit LED-pin select signal
    {false, false, false}, {false, false, true}, {false, true, false},
    {false, true, true}, {true, false, false}, {true, false, true},
    {true, true, false}, {true, true, true}};
    
void patternClear(){
  for (int i = 1; i < columns-1; i++)
    for (int j = 1; j < rows-1; j++)
      pattern[i][j] = false;
}

void patternUpdate(){
  for(int i = 0; i < columns; i++){
    for(int j = 0; j < rows; j++){
      if(pattern[i][j]){
        digitalWrite(2, firstLevel[i][0] ? HIGH : LOW);
        digitalWrite(3, firstLevel[i][1] ? HIGH : LOW);
        digitalWrite(4, firstLevel[i][2] ? HIGH : LOW);
        digitalWrite(5, firstLevel[j-1][0] ? HIGH : LOW);
        digitalWrite(6, firstLevel[j-1][1] ? HIGH : LOW);
        digitalWrite(7, firstLevel[j-1][2] ? HIGH : LOW);
        delay(10);
      }  
    }//end inner loop
  }//end outer loop
}
void patternA(){
  pattern[1][1] = true;
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[2][3] = true;
  pattern[2][5] = true;
  pattern[3][3] = true;
  pattern[3][6] = true;
  pattern[4][3] = true;
  pattern[4][5] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;  
}
void patternB(){
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][5] = true;
  pattern[2][1] = true;
  pattern[2][4] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][4] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][4] = true;
  pattern[4][6] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;  
  pattern[5][6] = true;
}
void patternC(){
  pattern[1][2] = true;
  pattern[1][5] = true;
  pattern[2][1] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][6] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;  
}
void patternD(){
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[2][1] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][6] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternE(){
  pattern[1][1] = true;
  pattern[1][4] = true;
  pattern[1][6] = true;
  pattern[2][1] = true;
  pattern[2][4] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][4] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][4] = true;
  pattern[4][6] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternF(){
  pattern[1][4] = true;
  pattern[1][6] = true;
  pattern[2][4] = true;
  pattern[2][6] = true;
  pattern[3][4] = true;
  pattern[3][6] = true;
  pattern[4][4] = true;
  pattern[4][6] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternG(){
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][5] = true;
  pattern[2][1] = true;
  pattern[2][3] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][3] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][6] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;   
}
void patternH(){
  pattern[1][1] = true;
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;  
  pattern[2][4] = true;
  pattern[3][4] = true;
  pattern[4][4] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternI(){
  pattern[2][1] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][2] = true;
  pattern[3][3] = true;
  pattern[3][4] = true;
  pattern[3][5] = true;
  pattern[3][6] = true;  
  pattern[4][1] = true;
  pattern[4][6] = true;
}
void patternJ(){
  pattern[2][6] = true;
  pattern[3][2] = true;
  pattern[3][3] = true;
  pattern[3][4] = true;
  pattern[3][5] = true;
  pattern[3][6] = true;  
  pattern[4][1] = true;
  pattern[4][6] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
}
void patternK(){
  pattern[1][1] = true;
  pattern[1][6] = true;
  pattern[2][2] = true;
  pattern[2][5] = true;
  pattern[3][3] = true;
  pattern[3][4] = true;
  pattern[4][4] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternL(){
  pattern[1][1] = true;
  pattern[2][1] = true;
  pattern[3][1] = true;
  pattern[4][1] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternM(){
  pattern[1][1] = true;
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;  
  pattern[2][5] = true;
  pattern[3][4] = true;
  pattern[4][5] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternN(){
  pattern[1][1] = true;
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;  
  pattern[2][3] = true;
  pattern[3][4] = true;
  pattern[4][5] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}

void patternO(){
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[2][1] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][6] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;  
}
void patternP(){
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[2][3] = true;
  pattern[2][6] = true;
  pattern[3][3] = true;
  pattern[3][6] = true;
  pattern[4][3] = true;
  pattern[4][6] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternQ(){
  pattern[1][1] = true;
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[2][1] = true;
  pattern[2][2] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][3] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][6] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;  
}
void patternR(){
  pattern[1][1] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[2][2] = true;
  pattern[2][3] = true;
  pattern[2][6] = true;
  pattern[3][3] = true;
  pattern[3][6] = true;
  pattern[4][3] = true;
  pattern[4][6] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;    
}
void patternS(){
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][5] = true;
  pattern[2][1] = true;
  pattern[2][4] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][4] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][4] = true;
  pattern[4][6] = true;
  pattern[5][2] = true;
  pattern[5][5] = true;  
}
void patternT(){
  pattern[1][6] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][2] = true;
  pattern[3][3] = true;
  pattern[3][4] = true;
  pattern[3][5] = true;
  pattern[3][6] = true;
  pattern[4][6] = true;
  pattern[5][6] = true;
}
void patternU(){
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;
  pattern[2][1] = true;
  pattern[3][1] = true;
  pattern[4][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternV(){
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;
  pattern[2][2] = true;
  pattern[3][1] = true;
  pattern[4][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternW(){
  pattern[1][1] = true;
  pattern[1][2] = true;
  pattern[1][3] = true;
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;
  pattern[2][2] = true;
  pattern[3][3] = true;
  pattern[4][2] = true;
  pattern[5][1] = true;
  pattern[5][2] = true;
  pattern[5][3] = true;
  pattern[5][4] = true;
  pattern[5][5] = true;
  pattern[5][6] = true;  
}
void patternX(){
  pattern[1][1] = true;
  pattern[1][6] = true;
  pattern[2][2] = true;
  pattern[2][5] = true;
  pattern[3][3] = true;
  pattern[3][4] = true;
  pattern[4][2] = true;
  pattern[4][5] = true;
  pattern[5][1] = true;
  pattern[5][6] = true;  
}
void patternY(){
  pattern[1][6] = true;
  pattern[2][5] = true;
  pattern[3][1] = true;
  pattern[3][2] = true;
  pattern[3][3] = true;
  pattern[3][4] = true;
  pattern[4][5] = true;
  pattern[5][6] = true;  
}
void patternZ(){
  pattern[1][1] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;
  pattern[2][1] = true;
  pattern[2][4] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][3] = true;
  pattern[3][6] = true;
  pattern[4][1] = true;
  pattern[4][2] = true;
  pattern[4][6] = true;
  pattern[5][1] = true;
  pattern[5][6] = true;  
}
void patternUnknown(){
  pattern[1][4] = true;
  pattern[1][5] = true;
  pattern[1][6] = true;
  pattern[2][4] = true;
  pattern[2][6] = true;
  pattern[3][1] = true;
  pattern[3][3] = true;
  pattern[3][4] = true;
  pattern[3][6] = true;
  pattern[4][6] = true;
  pattern[5][5] = true;  
  pattern[5][6] = true;  
}

char readChar;
boolean found;
void setup() {
  Serial.begin(9600);//serial monitor boud rate
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    found = false;
    readChar = Serial.read();
    patternClear();
    for (int i=0; i < 26; i++){
      if(alphabet[i].key == readChar){
        alphabet[i].functionPtr();  
        found = true;
      }
    }
    if(!found)
      patternUnknown();
  }//end if
  for (int i = 0; i < 200; i++)//delay and hold the pattern
    patternUpdate();
}
