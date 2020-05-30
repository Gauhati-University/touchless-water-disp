/*
* Touchless Water Dispenser using Ultrasonic Sensor HC-SR04 and Arduino
*
* by Nairit Barkataki, Gauhati University
* nairitb@gauhati.ac.in
*
*/
// define pins numbers
const int trig = 9;
const int echo = 8;
const int Valve = 11;

// define variables
long duration;
int distance;
void setup() {
  
  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input
  pinMode(Valve, OUTPUT); // Configure the pin connected to the Valve as OUTPUT
  
}

void loop() {
  // Clear the trigPin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Read the echoPin, return the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  
  // Calculate the distance
  distance= duration*0.034/2;

  //Condition for opening Water Valve
  if(distance>10 && distance<60){
    digitalWrite(Valve, LOW); //Turns on the solenoid water valve
  }
  
  else{
    digitalWrite(Valve, HIGH); //Turns off the solenoid water valve
   }
  
}
