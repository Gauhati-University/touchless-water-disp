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

## Pin Out Diagram of HC SR04 Ultrasonic Sensor:
![hc-sr04-ultrasonic-sensor-module-500x500](https://user-images.githubusercontent.com/63898803/83054937-c92a5f00-a070-11ea-8b26-05271b1ce2f5.jpg)

| Pins | Usage |
|:----:|:--------------:|
| VCC | +5V |
| Trig | TRIGGER(Input) |
| Echo | ECHO (Output) |
| GND | GROUND |

Now to generate the ultrasound signal the Trig pin must be HIGH for 10µs which will send out an 8 cycle sonic burst which will travel at the speed sound and it will be received in the Echo Pin. The Echo Pin will output the time in microseconds the sound wave traveled. The time duration between transmission and reception can be used to determine the distance to the object as the speed of sound is known.

![uploads2ftmp2f0e8762c9-13ef-48e3-8ee9-838c7f24ca8d2f2_ultrasonic_module_timing_diagram_IoXUGXtipu](https://user-images.githubusercontent.com/63898803/83060198-b9167d80-a078-11ea-8b52-48c3cdfcbdfb.jpg)
  
  


![How-ultrasonic-sensor-works](https://user-images.githubusercontent.com/63898803/83060901-c7b16480-a079-11ea-976e-b8040626194e.jpg)
