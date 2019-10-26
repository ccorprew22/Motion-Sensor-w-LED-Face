# Motion Sensor with LED Face

One day I was watching videos on electronics and Ardunios, so the next day I bought a starter kit and some addtional parts. After some practice projects and learning how to use a breadboard and how to wire the different parts of an Ardunio, I decided to make some sort of motion sensor that works as a radar. 

# Materials (Some are optional depending on how you wire it)
+ 1 Breadboard
+ 1 Ardunio Controller Board
+ Breadboard Jumper Wires
+ Female to Male Dupont Wires
+ 1 USB Port Cord (Power supply)
+ 1 8x8 LED Display Board
+ 1 Ultrasonic Sensor
+ 1 Servo Motor
+ ALOT of tape

# How Does It Work

The Ardunio Controller Board is attached to the breadboard with several jump wires. Connect a 5v wire and a Ground wire into he bread board. Connect four wires for VCC, Ground, Trig, and Echo to the sensor. Also wire five wires into the LED display for VCC, Ground, CLK, DIN, and CS. The motion sensor is then attached to a servo motor that is connected to the Ardunio Board. The servo motor is programmed to turn 90 degrees left and right. The LED Display is then programmed to have a face turn with the servo motor. When the sensor detects something within whatever the programmed range is, the LED and the motor will stop in place of the object. When the object is moved out of range, the motor will continue scanning back and forth.

# Demonstration

# What I Am Working on Now

I am working on a way to programming a radar like display for that will show what the sensor is picking up with Processing.
