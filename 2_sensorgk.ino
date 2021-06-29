

int TriggerPIN1 = D5;
int EchoPIN1 = D0;
int TriggerPIN2 = D8;
int EchoPIN2 = D7;
const int ledPin = D6;//the led attach to
int myArray[5] = {0,0,0,0,0};
int monTotal = 0;
int MaMoy = 0;
int distObjet1 = 0;
int distObjet2 = 0;
//int myArray2[5] = {0,0,0,0,0};
int monCompteur = 0;
int maLimite = 0;
//int monTotal2 = 0;
//int MaMoy2 = 0;
int inputValue1 = 0;//variable to store the value coming from sensor
int outputValue1 = 0;//variable to store the output value
int inputValue2 = 0;//variable to store the value coming from sensor
int outputValue2 = 0;//variable to store the output value
void setup(){
  Serial.begin(115200);
  pinMode(TriggerPIN1,OUTPUT);
  pinMode(EchoPIN1,INPUT);
  pinMode(TriggerPIN2,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  }

void loop(){  
  if (maLimite ==5) {
    distObjet1 = MaMoy;
    distObjet2 = MaMoy;
  }
  monCompteur++;
  maLimite++;
  
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

  //int inputValue = distance;
  //int outputValue = map(inputValue, 0, 2300, 0, 20000);
  //analogWrite(ledPin, outputValue);
  //myArray2[monCompteur] = distance2; 
  // calcul de la moyenne 
//for (int i = 0; i< 5; i = i+1){
 //   monTotal1 = myArray1[i] + monTotal1;
//  }
//   for (int i = 0; i< 5; i = i+1){
 //   monTotal2 = myArray2[i] + monTotal2;
//}
 //MaMoy1 = monTotal1 / 5; // myArray.length fonction prédéfinie qui donne le nombre d'éléments dans un tableau
// MaMoy2 = monTotal2 / 5; // myArray.length fonction prédéfinie qui donne le nombre d'éléments dans un tableau
 
//  monTotal1 = 0;
//  monTotal2 = 0;

 // Serial.print("maMoy1 = ");
  //Serial.println(MaMoy1);
//  Serial.print("maMoy2 = ");
  //Serial.println(MaMoy2);
  if (distance1 >= distObjet1 && distance2 >= distObjet2 && maLimite >=5 ) {
    analogWrite(ledPin, 0);
  }
   
  else {
    if  (distance1 >= distance2 && distance2 < distObjet2 && maLimite >=5 ) {
      int inputValue = distance1;
      int outputValue = map(inputValue, 0, distObjet1, 0, 255); //set.brightness fonctionne de 0-255      
      myArray[monCompteur] = distance1; 
      for (int i = 0; i< 5; i = i+1){
        monTotal = myArray[i] + monTotal;
        }
      MaMoy = monTotal / 5;
      analogWrite(ledPin, MaMoy);

    }

    else if (distance2 >= distance1 && distance1 < distObjet1 && maLimite >=5 ) {
      int inputValue = distance2;
      int outputValue = map(inputValue, 0, distObjet2, 0, 255); //une des valeurs devrait etre distObjet soit comme tel ou modifie
      myArray[monCompteur] = distance2; 
      for (int i = 0; i< 5; i = i+1){
        monTotal = myArray[i] + monTotal;
        }
      MaMoy = monTotal / 5;
      analogWrite(ledPin, MaMoy);
    }
  }
  if (monCompteur == 5){
    monCompteur = 0;
  }
 monTotal = 0;
  }
