# Touchless Water Dispenser

Touchless Water Dispenser using Arduino and a Solenoid valve automatically opens and closes a faucet so that we can wash our hands safely and prevent spread of coronavirus disease. For detecting our hand when placed just below the valve we use an ultrasonic sensor and that leads to opening the valve.

# Materials Required
* Arduino UNO
* HC-SR04 ultrasonic sensor
* Transistor: BC547
* Diode: 1N4001
* Resistor: 220 ohm
* Power Supply: +5V DC,+12V DC and 230V AC
* Power Plugs
* Connecting Wires
* PCB

# Circuit Diagram 

## Wire Connections of Arduino and Ultrasonic Sensor
<img src = "https://user-images.githubusercontent.com/63898803/83017119-ba2bb880-a040-11ea-8c0a-70eec75fd980.jpeg" width=650 height = 400>


## Schematic Diagram
<img src = "https://user-images.githubusercontent.com/63898803/83017678-b0568500-a041-11ea-992e-c3f2fd3a47b7.jpeg" width = 650 height= 650>


# Working Principle

<img src = "https://user-images.githubusercontent.com/63898803/83060901-c7b16480-a079-11ea-976e-b8040626194e.jpg" width = 650 height = 400>



The HC-SR04 Ultrasonic sensor comes with both reciever and transmitter modules. The sensor uses sonar to determine the distance to an object.
1. The transmitter (Trig pin) transmit an high frequency signal of 40kHz.
2. The transmitted signal travels through air and reflects when incident on the surface of the object (in this case our hand).
3. The reciever (Echo pin) recieves the reflected signal.

## Pin Out Diagram of HC SR04 Ultrasonic Sensor:
<img src = "https://user-images.githubusercontent.com/63898803/83054937-c92a5f00-a070-11ea-8b26-05271b1ce2f5.jpg" width = 350 height = 350>

| Pins | Usage |
|:----:|:--------------:|
| VCC | +5V |
| Trig | TRIGGER(Input) |
| Echo | ECHO (Output) |
| GND | GROUND |

Now to generate the ultrasound signal the Trig pin must be HIGH for 10µs which will send out an 8 cycle sonic burst which will travel at the speed sound and it will be received in the Echo Pin. The Echo Pin will output the time in microseconds the sound wave traveled. The time duration between transmission and reception can be used to determine the distance to the object as the speed of sound is known.

![uploads2ftmp2f0e8762c9-13ef-48e3-8ee9-838c7f24ca8d2f2_ultrasonic_module_timing_diagram_IoXUGXtipu](https://user-images.githubusercontent.com/63898803/83060198-b9167d80-a078-11ea-8b52-48c3cdfcbdfb.jpg)

# Code

The following code needs to be uploaded to the Arduino IDE.

```
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
```

## working of the code
 
The variables for the trigger and echo pin called trigPin and echoPin, respectively. The trigger pin is connected to digital Pin 9, and the echo pins is connected to digital Pin 8. The variable for solenoid valve is called Valve and is connected to digital Pin 11:
```
const int trigPin = 9;
const int echoPin = 8;
const int Valve = 11;
```
Also two variables `duration` and `distance` are define. The `duration` variable will save the time between emission and reception of signal and `distance` variable will save the distance between the Ultrasonic sensor and the object which is calculated using the `duration` variable:
```
long duration;
int distance;
```
In the `setup()` function, the `triPin` is set as Output , the `echoPin` is set as Input and the `Valve` pin as Output.
Also the serial port is intialized at a baud rate of 9600:
```
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(Valve, OUTPUT); // Configure the pin connected to the Valve as OUTPUT
Serial.begin(9600); // Starts the serial communication
```
In the loop() funcion,the Ultrasonic sensor is triggered by sending a HIGH pulse of 10 microseconds through the `triPin`. But, before that,a short LOW pulse is send through it to ensure that we get a clean HIGH pulse:
```
 // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 ```
 Now, the `echoPin` is read which recieves a HIGH pulse from the **Echo pin** of the sensor whose duration is equal to the duration of time (in mircosecond) between transmission and reception of its echo from the object and the assigned to the variable `duration`.
 ```
 duration = pulseIn(echoPin, HIGH);
 ```
 The distance between the Object and the sensor is calculated using the formula below:
 ```
 distance= duration*0.034/2;
 ```
 Now, a range of distance is given as a condition between which the object should be placed for the valve to open. This condition could be set according to requirement.
 ```
  if(distance>10 && distance<50){
    digitalWrite(Valve, LOW); //Turns on the solenoid water valve
  }
  
  else{
    digitalWrite(Valve, HIGH); //Turns off the solenoid water valve
   }
 ```
 Lastly, the distance between the object and the sensor is printed on the Serial monitor:
 ```
  Serial.print("Distance: ");
  Serial.println(distance);
  ```
 # Credits
 
 
 
 
 # Contributing
 
 
 
