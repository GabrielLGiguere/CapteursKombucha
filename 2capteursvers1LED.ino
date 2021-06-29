int TriggerPIN1 = D8;
int EchoPIN1 = D7;
int TriggerPIN2 = D1;
int EchoPIN2 = D3;
int ledPin = D6;
int inputValue1 = 0;//variable to store the value coming from sensor
int outputValue1 = 0;//variable to store the output value
int inputValue2 = 0;//variable to store the value coming from sensor
int outputValue2 = 0;//variable to store the output value
int moy = 0;
int distObjet = 0;
int inputValue = 0;//variable to store the value coming from sensor
int outputValue = 0;//variable to store the output value
int myArray[5] = {0,0,0,0,0};
int monCompteur = 0;
int monTotal = 0;
int maMoy = 0;
int maLimite = 0;

void setup(){
  pinMode(TriggerPIN1,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  pinMode(TriggerPIN2,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  Serial.begin(115200); 
  }

void loop(){  
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

 moy = (outputValue1 + outputValue2) /2;

  myArray[monCompteur] = moy; 
  
  // calcul de la moyenne 
  for (int i = 0; i< 5; i = i+1){
    monTotal = myArray[i] + monTotal;
  }
  
  maMoy = monTotal / 5; // myArray.length fonction prédéfinie qui donne le nombre d'éléments dans un tableau
  
  monCompteur = monCompteur + 1;
  if (monCompteur == 5){
    monCompteur = 0;
  }

 monTotal = 0;

 

  analogWrite(ledPin,maMoy);
  }
