long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int echoPin = D7;
int trigPin = D8;
const int ledPin = D6;//the led attach to
int distObjet = 0;
int inputValue = 0;//variable to store the value coming from sensor
int outputValue = 0;//variable to store the output value
  int myArray[5] = {0,0,0,0,0};
  int monCompteur = 0;
  int monTotal = 0;
  int maMoy = 0;
  int maLimite = 0;

void setup() {
 Serial.begin(115200);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
 pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {
  if (maLimite ==5) {
    distObjet = maMoy;
  }
  maLimite++;
  // code de détection de distance qui donne la duration'
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  int inputValue = distance;
  int outputValue = map(inputValue, 10, 2300, 0, 20000);

  
  myArray[monCompteur] = outputValue; 
  
  // calcul de la moyenne 
  for (int i = 0; i< 5; i = i+1){
    monTotal = myArray[i] + monTotal;
  }
  
  maMoy = monTotal / 5; // myArray.length fonction prédéfinie qui donne le nombre d'éléments dans un tableau
  
  monCompteur = monCompteur + 1;
  if (monCompteur == 5){
    monCompteur = 0;
  }

  if (maMoy >= (distObjet - 200)) {
    analogWrite(ledPin, 0);
  }
  else if (maMoy < distObjet) {
    analogWrite(ledPin, maMoy);
  }
//analogWrite(ledPin, maMoy);
  monTotal = 0;

  Serial.print("maMoy = ");
  Serial.println(maMoy);
  delay(5);
  Serial.println(distObjet);
}
