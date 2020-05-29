/*
* Touchless Water Dispenser using Ultrasonic Sensor HC-SR04 and Arduino
*
* by Nairit Barkataki, Gauhati University
* nairitb@gauhati.ac.in
*
*/
// define pins numbers
const int trigPin = 9;
const int echoPin = 8;
const int Valve = 11;

// define variables
long duration;
int distance;
void setup() {
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(Valve, OUTPUT); // Configure the pin connected to the Valve as OUTPUT
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, return the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance= duration*0.034/2;

  //Condition for opening Water Valve
  if(distance>10 && distance<50){
    digitalWrite(Valve, LOW); //Turns on the solenoid water valve
  }
  
  else{
    digitalWrite(Valve, HIGH); //Turns off the solenoid water valve
   }
  
  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
