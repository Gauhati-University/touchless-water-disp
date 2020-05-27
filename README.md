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

![signal-attachment-2020-05-27-171357_001](https://user-images.githubusercontent.com/63898803/83017119-ba2bb880-a040-11ea-8c0a-70eec75fd980.jpeg)

![signal-attachment-2020-05-27-171357_002](https://user-images.githubusercontent.com/63898803/83017678-b0568500-a041-11ea-992e-c3f2fd3a47b7.jpeg)

# Working Principle

The HC-SR04 Ultrasonic sensor comes with both reciever and transmitter modules. The sensor uses sonar to determine the distance to an object.
1. The transmitter (Trig pin) transmit an high frequency signal of 40kHz.
2. The transmitted signal travels through air and reflects when incident on the surface of the object (in this case our hand).
3. The reciever (Echo pin) recieves the reflected signal.


