///sensor 1///


int TriggerPIN1 = D8;
int EchoPIN1 = D7;
int ledPin1 = D6;
int ledPin2 = D5;
int ledPin3 = D0;
int inputValue1 = 0;//variable to store the value coming from sensor
int outputValue1 = 0;//variable to store the output value
int myArray1[5] = {0,0,0,0,0};
int monTotal1 = 0;
int maMoy1 = 0;
int distObjet1 = 0;
///sensor 2///

int TriggerPIN2 = D4;
int EchoPIN2 = D3;
int ledPin4 = D2;
int ledPin5 = D1;
int inputValue2 = 0;//variable to store the value coming from sensor
int outputValue2 = 0;//variable to store the output value
int myArray2[5] = {0,0,0,0,0};
int monTotal2 = 0;
int maMoy2 = 0;
int distObjet2 = 0;


int monCompteur = 0;
int maLimite = 0;

void setup(){
  pinMode(TriggerPIN1,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  pinMode(TriggerPIN2,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  Serial.begin(115200); 
  }

void loop(){  
  maLimite++;
  if (maLimite ==5) {
    distObjet1 = maMoy1;
    distObjet2 = maMoy2;
  }
  digitalWrite(TriggerPIN1,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,HIGH);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,LOW);

  long timedelay = pulseIn(EchoPIN1,HIGH);
  int distance1 = 0.0343 * (timedelay/2);

  Serial.print("Sensor 1 : ");
  Serial.println(distance1);

  delayMicroseconds(60);

  digitalWrite(TriggerPIN2,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,HIGH);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,LOW);

  long td = pulseIn(EchoPIN2,HIGH);
  int distance2 = 0.0343 * (td/2);

  Serial.print("Sensor 2 : ");
  Serial.println(distance2);

 int inputValue1 = distance1;
 int outputValue1 = map(inputValue1, 10, 2300, 0, 20000);
 int inputValue2 = distance2;
 int outputValue2 = map(inputValue2, 10, 2300, 0, 20000);

 myArray1[monCompteur] = outputValue1; 
  
  // calcul de la moyenne 
  for (int i = 0; i< 5; i = i+1){
    monTotal1 = myArray1[i] + monTotal1;
  }
  
  maMoy1 = monTotal1 / 5; // myArray.length fonction prédéfinie qui donne le nombre d'éléments dans un tableau
  
  monCompteur = monCompteur + 1;
  if (monCompteur == 5){
    monCompteur = 0;
  }

 monTotal1 = 0;

 

 myArray2[monCompteur] = outputValue2; 
  
  // calcul de la moyenne 
  for (int i = 0; i< 5; i = i+1){
    monTotal2 = myArray2[i] + monTotal2;
  }
  
  maMoy2 = monTotal2 / 5; // myArray.length fonction prédéfinie qui donne le nombre d'éléments dans un tableau
  
  monCompteur = monCompteur + 1;
  if (monCompteur == 5){
    monCompteur = 0;
  }

 monTotal2 = 0;

  if (maMoy1 >= (distObjet1 - 200)) {
    analogWrite(ledPin1,0);
    analogWrite(ledPin2,0);
    analogWrite(ledPin3,0);;
  }
  else if (maMoy1 < distObjet1) {
    analogWrite(ledPin1,maMoy1);
    analogWrite(ledPin2,maMoy1);
    analogWrite(ledPin3,maMoy1);
  }

   if (maMoy2 >= (distObjet2 - 200)) {
    analogWrite(ledPin4,0);
    analogWrite(ledPin5,0);
  }
  else if (maMoy2 < distObjet2) {
    analogWrite(ledPin4,maMoy2);
    analogWrite(ledPin5,maMoy2);
  }
 

  }
