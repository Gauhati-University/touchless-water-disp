[![Open Source Love png3](https://badges.frapsoft.com/os/v3/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/) [![made-with-arduino](https://img.shields.io/badge/Made%20with-Arduino-blue)](https://www.arduino.cc/)

# Touchless Water Dispenser
## Description
Touchless Water Dispenser using Arduino and a Solenoid valve automatically opens and closes a faucet so that we can wash our hands safely and prevent spread of coronavirus disease. For detecting our hand when placed just below the valve we use an ultrasonic sensor and that leads to opening the valve.

## Materials Required
* Arduino UNO / Pro Mini (5V, 16MHz)
* HC-SR04 ultrasonic sensor
* Transistor: BC547
* Diode: 1N4001
* Resistors and Capacitors
* Relay (5V or 12V)
* Solenoid Valve
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

<img src = "https://user-images.githubusercontent.com/63898803/83060901-c7b16480-a079-11ea-976e-b8040626194e.jpg" width = 500>

The HC-SR04 Ultrasonic sensor comes with both reciever and transmitter modules. The sensor uses sonar to determine the distance to an object.
1. The transmitter transmits a high frequency signal of 40kHz.
2. The transmitted signal travels through air and reflects when incident on the surface of the object (in this case our hand).
3. The reciever recieves the reflected signal.
 
| Pins | Usage |
|:----:|:--------------:|
| VCC | +5V |
| Trig | TRIGGER(Input) |
| Echo | ECHO (Output) |
| GND | GROUND |

To generate the ultrasound signal the **Trig** pin must be HIGH for 10µs. The transmitter will then send out an 8 cycle sonic burst which will travel at the speed of sound, get reflected by an object and will be received by the receiver. The **Echo** Pin emits a pulse whose width is in proportion to the distance travelled by the sound wave. The time duration between transmission and reception can be used to determine the distance to the object as the speed of sound is known.

<img src="https://user-images.githubusercontent.com/63898803/83060198-b9167d80-a078-11ea-8b52-48c3cdfcbdfb.jpg" width=500>

### Relay:

<img src = "https://www.circuitbasics.com/wp-content/uploads/2015/11/5V-Relay-Pinout1-1024x478.png" width=400>

For a range of obstacle distance (say between 10cm and 60cm), the faucet of the solenoid valve needs to open. For all other cases, valve will be closed. This is done using a relay by connecting or disconnecting the valve to the AC source. The AC source is connected to **C** terminal and the solenoid valve to the **NO** terminal of the relay as shown in the figure. Here the relay, used in normally open configuration, upon recieving a HIGH signal at the **Signal** terminal from the Arduino allows the current to flow from **C** terminal to **NO** terminal. 

<img src = "https://user-images.githubusercontent.com/63898803/83359725-bd54da80-a399-11ea-89f4-378f80060193.jpeg" width=400>

The coil of a relay draws a relatively large current (activation current), typically 30mA for a 12V relay, but it can be as much as 100mA for other relays. But the Arduino UNO provides an output current of ~40mA. A transistor is used between the Arduino and the relay as a buffer to provide the required activation current to the relay.
The transistor used should be able to operate on more than 20% of the activation current (for safety purpose) of the relay (which can be found from the datasheet) and must have suffiecient a value of h<sub>fe</sub>(gain) to amplify the base current(in few mA) to the collector current required by the relay.
The flyback diode is connected to the relay coils to protect the transistor and the Arduino.
A resistor is used between the transistor and arduino to limit the base current to protect the Arduino pin from damage.


### Valve:
<img src = "https://instrumentationtools.com/wp-content/uploads/2016/01/instrumentationtools.com_direct-operated-direct-acting-solenoid-valves.png" width=400>

A Solenoid valve operates at ~250VAC/10A which is provided the AC power source. In normally closed configuration, when the solenoid coils get energized due to flow of current from the AC source via relay, the plunger gets pulled to open the faucet leading to flow of liquid (water). When the connection between the source and the Solenoid valve cuts off, the plunger retains its original position with the help of a spring which closes the faucet preventing the flow of liquid.


## Code

The code can be found at [arduino.ino](https://github.com/Gauhati-University/touchless-water-disp/blob/master/Program/arduino/arduino.ino).

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
 
 ## Testing
 [![license-apache](https://img.shields.io/badge/Tested%20on-UNO%2C%20Pro%20Mini-orange)](https://github.com/Gauhati-University/touchless-water-disp)
 
 The circuit was tested on Arduino UNO and Arduino Pro Mini
 
 ## Implementation
 <img src="https://user-images.githubusercontent.com/63898803/83333320-91642700-a2bd-11ea-9059-843baad686dd.jpeg" width=600>
 The circuit is implemented on a custom development board based on Arduino Pro Mini.

 ## Credits
 The contributors of this project are : Sharmistha Mazumdar, Rajdeep Choudhury, Nairit Barkataki, Tilak Deka, and Utpal Sharma.
 
 ## Contributing
 [![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](code_of_conduct.md)
 
 Contributions to this project are releasedto the public under the [project's open source license](LICENSE).

This project adheres to a [Code of Conduct][code-of-conduct]. By participating, you are expected to honor this code.

[code-of-conduct]: CODE_OF_CONDUCT.md

See [Contributing](CONTRIBUTING.md) for more details.

 
 ## License
 [![license-apache](https://img.shields.io/badge/license-Apache%202.0-green)](https://github.com/Gauhati-University/touchless-water-disp/blob/master/LICENSE) 
 
This work is licensed under the open source [Apache License 2.0](LICENSE)
 
