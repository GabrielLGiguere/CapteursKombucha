#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int echoPin = D7;
int trigPin = D8;
int distObjet = 0;
int inputValue = 0;//variable to store the value coming from sensor
int outputValue = 0;//variable to store the output value
int myArray[5] = {0,0,0,0,0};
int monCompteur = 0;
int monTotal = 0;
int maMoy = 0;
int maLimite = 0;

const int LED_PIN = D6;
const int LED_COUNT = 2;
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
 Serial.begin(115200);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
 pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
 pixels.begin();
 pixels.clear();
 #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
}

void loop() {
  pixels.clear();
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
  int outputValue = map(maMoy, 10, 2300, 0, 255);
 // uint32_t red = strip.Color(255, 0, 0);
 // uint32_t black = strip.Color(0, 0, 0);
  myArray[monCompteur] = distance; 
  
  // calcul de la moyenne 
  for (int i = 0; i< 5; i = i+1){
    monTotal = myArray[i] + monTotal;
  }
  
  maMoy = monTotal / 5; // myArray.length fonction prédéfinie qui donne le nombre d'éléments dans un tableau
  
  monCompteur = monCompteur + 1;
  if (monCompteur == 5){
    monCompteur = 0;
  }
Serial.println(outputValue);
Serial.println(distObjet);
  if (outputValue >= (distObjet - 200)) {
    pixels.clear();
  }
  else if (outputValue < distObjet) {
     Serial.print("workin");
     int outputValue = map(maMoy, 0, 2300, 0, 255);
     pixels.setPixelColor(0, pixels.Color(255, 0, 0));
     pixels.setPixelColor(1, pixels.Color(255, 0, 0));
     pixels.setBrightness(maMoy);
     pixels.show();
     

  }
//analogWrite(ledPin, maMoy);
  monTotal = 0;

  Serial.print("maMoy = ");
  Serial.println(maMoy);
  delay(200);
}
