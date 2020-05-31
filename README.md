[![Open Source Love png3](https://badges.frapsoft.com/os/v3/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/) [![made-with-arduino](https://img.shields.io/badge/Made%20with-Arduino-blue)](https://www.arduino.cc/)

# Touchless Water Dispenser
## Description
Touchless Water Dispenser using Arduino and a Solenoid valve automatically opens and closes a faucet so that we can wash our hands safely and prevent spread of coronavirus disease. For detecting our hand when placed just below the valve we use an ultrasonic sensor and that leads to opening the valve.

## Materials Required
* Arduino UNO
* HC-SR04 ultrasonic sensor
* Transistor: BC547
* Diode: 1N4001
* Resistor: 220 ohm
* Power Supply: +5V DC (from Arduino),+12V DC and 230V AC
* Power Plugs
* Connecting Wires
* PCB

## Circuit Diagram 

### Wire Connections of Arduino and Ultrasonic Sensor
<img src = "https://user-images.githubusercontent.com/63898803/83017119-ba2bb880-a040-11ea-8c0a-70eec75fd980.jpeg" width=650> 


### Schematic Diagram
<img src = "https://user-images.githubusercontent.com/63898803/83017678-b0568500-a041-11ea-992e-c3f2fd3a47b7.jpeg" width = 650> 


## Working Principle

### Sensor:

<img src = "https://user-images.githubusercontent.com/63898803/83060901-c7b16480-a079-11ea-976e-b8040626194e.jpg" width = 650>

The HC-SR04 Ultrasonic sensor comes with both reciever and transmitter modules. The sensor uses sonar to determine the distance to an object.
1. The transmitter transmit an high frequency signal of 40kHz.
2. The transmitted signal travels through air and reflects when incident on the surface of the object (in this case our hand).
3. The reciever recieves the reflected signal.
 
| Pins | Usage |
|:----:|:--------------:|
| VCC | +5V |
| Trig | TRIGGER(Input) |
| Echo | ECHO (Output) |
| GND | GROUND |

To generate the ultrasound signal the **Trig** pin must be HIGH for 10µs.The transmitter will then send out an 8 cycle sonic burst which will travel at the speed of sound and will be received by the receiver. The **Echo** Pin emits a pulse whose width is in proportion to the distance travelled by the sound wave. The time duration between transmission and reception can be used to determine the distance to the object as the speed of sound is known.

![uploads2ftmp2f0e8762c9-13ef-48e3-8ee9-838c7f24ca8d2f2_ultrasonic_module_timing_diagram_IoXUGXtipu](https://user-images.githubusercontent.com/63898803/83060198-b9167d80-a078-11ea-8b52-48c3cdfcbdfb.jpg)

### Relay:
The [Relay](http://www.circuitstoday.com/working-of-relays) is an electronic Switch and is used in normally open mode.The main job of the relay is to connect or disconnect the Solenoid Valve to the AC power source depending upon the control signal coming from the Arduino. The Relay is used along with a Transistor and diode as shown in the figure below.


<img src = "https://user-images.githubusercontent.com/63898803/83359725-bd54da80-a399-11ea-89f4-378f80060193.jpeg" width=400>


The relay needs 12V on the input to turn on. The transistor is working a switch between the 12V source and the relay. The AC source is connected to common pin and the solenoid valve on the NO (Normal Open contact) pin of the relay. Once the relay coil is energized the contact between the two pins are developed.
The diode provides protection against reverse voltage across the relay coils when the transistor is non conducting.

### Valve:
<img src = "https://instrumentationtools.com/wp-content/uploads/2016/01/instrumentationtools.com_direct-operated-direct-acting-solenoid-valves.png" width=400>
The Solenoid valve is a electrically controlled valve.In this project, the orfice of the valve is normally closed and the relay controls it.
The Solenoid coils gets energized on connection to the AC source leading to pulling the plunger. This leads to openning of the orfice and flow of the liquid. Once the power source gets disconnected from the Valve, the spring pushes the plunger down to its orginal position preventing the flow of liquid.



## Code

The code can be found at [arduino.ino](https://github.com/Gauhati-University/touchless-water-disp/blob/master/Program/arduino/arduino.ino).

### Working of the code

#### Pins used:
 
The variables for the trigger and echo pin called **trig** and **echo**, respectively. The trigger pin of HC SR04 is connected to digital pin 9 of arduino, and the echo pin is connected to digital pin 8. The variable for controllong the state of the solenoid valve is called Valve and is connected to digital Pin 11:
```
const int trig = 9;
const int echo = 8;
const int Valve = 11;
```

#### Variables:
`duration` variable will save the time between emission and reception of signal and `distance` variable will save the distance between the Ultrasonic sensor and the object which is calculated using the `duration` variable:
```
long duration;
int distance;
```

#### setup():
The `trig` is set as Output, the `echo` is set as Input and the `Valve` pin as Output.

```
pinMode(trig, OUTPUT); // Sets the trig as an Output
pinMode(echo, INPUT); // Sets the echo as an Input
pinMode(Valve, OUTPUT); // Configure the pin connected to the Valve as OUTPUT
```

#### loop():
The Ultrasonic sensor is triggered by sending a HIGH pulse of 10 microseconds through the `trig` pin. But, before that, a short LOW pulse is send through it to ensure that we get a clean HIGH pulse:
```
 // Clear the trig
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  // Set the trig on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 ```
 
#### Reading the Echo pin of the sensor:
Now, the `echo` pin is read which recieves a HIGH pulse from the **Echo pin** of the sensor whose pulse width is equal to the duration of time (in mircosecond) between transmission and reception of its echo from the object and the assigned to the variable `duration`.
 ```
 duration = pulseIn(echo, HIGH);
 ```
 
 #### Calculating the distance:
 The distance between the Object and the sensor is calculated using the formula below:
 ```
 distance= duration*0.034/2;
 ```
 
 #### Condition to open the valve:
 Now, a range of distance is given as a condition between which the object should be placed for the valve to open. This condition could be set according to requirement.
 ```
  if(distance>10 && distance<60){
    digitalWrite(Valve, LOW); //Turns on the solenoid water valve
  }
  
  else{
    digitalWrite(Valve, HIGH); //Turns off the solenoid water valve
   }
 ```
 ## Implementation
 <img src="https://user-images.githubusercontent.com/63898803/83333320-91642700-a2bd-11ea-9059-843baad686dd.jpeg" width=650>
 The circuit is implemented on a custom development board based on Arduino Pro Mini.

 ## Credits
 The contributors of this project are : Utpal Sharma, Rajdeep Choudhury, Nairit Barkataki, Tilak Deka and @Sharmist13.
 
 ## Contributing
 [![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](code_of_conduct.md)
 Contributions to this project are releasedto the public under the [project's open source license](LICENSE).

This project adheres to a [Code of Conduct][code-of-conduct]. By participating, you are expected to honor this code.

[code-of-conduct]: CODE_OF_CONDUCT.md

See [Contributing](CONTRIBUTING.md) for more details.

 
 # License
 [![license-apache](https://img.shields.io/badge/license-Apache%202.0-green)](https://github.com/Gauhati-University/touchless-water-disp/blob/master/LICENSE) 
 
This work is licensed under the open source [Apache License 2.0](LICENSE)
 
