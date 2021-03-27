# Creative Embedded Systems - Module 4: Kinetic Art
This piece is a kinetic sculpture that illustrates the destructive effects of industrialization on the natural environment. This piece consists of a natural landscape where we can see two robotic legs causing destruction to the landscape, along with two spinning trees. A video demo of the piece can be found [here](https://www.youtube.com/watch?v=PhmWeasTCKc&ab_channel=MichaelLeoWinitch).


## The Enclosure and Robotic Legs
The enclosure was created from cardboard, and a plastic bag. The main part of the enclosure also uses popsicle sticks to provide structural support. The trees were created using skewers and cardstock. We used vine charcoal to add some texture to the front of a piece, and emphasize the destruction caused by the claws. 

The legs were created through cutting and drilling popsicle sticks, laser cutting the washers and pincers in basswood, and using skewers to connect the pieces.

Illustrator files for the pincers (`pincer.ai`) and the triangle joint (`triangle joint.ai`) can be found in the repo. Washers were simply circles with holes that matched the diameter of the skewers, and the eyelet pieces that connected the motors to the legs can be recreated by make trapezoid that was two centimeters in height, with the smaller side about one centimeter and the edger rounded. Finally, we used straws to connect the eyelet pieces and the motor. Although we made some adjustments to the design to fit our material limitations, it may be helpful to view [this video](https://www.youtube.com/watch?v=3HTDuWJHADY) in order to reconstruct the legs.

## The Wiring and the Hardware
Two ESP32s were used to control the motors. Two servo and two stepper motors were used. The servo motors were in one ESP32, while the two stepper motors were in the other ESP32. Because running the motors required a lot of power we connected the ESP32s directly to 9V power sources. 

We used the stepper and servo motos that came with the Freenove Ultimate Starter Kit for ESP32. More details on the wiring can be found [here](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_ESP32)

The ESP32 controlling the stepper motors were confirgured as follows: 
First each motor was connected to a motor driver, matching the red wire of the stepper to power on the driver. The pins of the motor driver were connected to GPIO 14, GPIO 27, GPIO 26, and GPIO 25 on the ESP 32. Note that if you change the GPIO pins the order on the code was 14, 26, 27, 25, <b> not </b> 14, 27, 26, 25. The two motors were configured using the same pins so that they moved in unison. 

The wiring of a single motor is illustrated below. The wiring for the second motor was using the same GPIO pins.
<br>
 <img src="https://github.com/Cina10/EmbeddedSys_Kinetic/blob/master/Images/Stepper%20Wiring.png" width="500">
 <br>

The stepper motors were glued to the eyelet pieces and moved the legs. For the stepper motor, [this website](https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/) helped us with setting up and running the stpper motor code. 

The ESP32 controlling the servo motors were confirgured as follows:
This setup simply connects the three wires of the servo motor to the breadboard and the ESP32. One wire connects to ground, and another wire connects to 5V. Then, the final wire of the servo motor connects to one of the GPIO pins of the ESP32. We used GPIO pins 15 and 19 for the servo motors, but you can use different ones, just make sure you change the code in `trees.ino` to reflect those changes. 

The servo motors were glued to the trees to make them rotate. 

## Arduino
First, edit the code in both `trees.ino` and `claws.ino` to include your wifi ssid and password. Below are the lines you will see which are currently empty strings:
~~~C++
const char *ssid_Router     = "";
const char *password_Router = "";
~~~
If you are using some open WiFi source then leave password field as the empty string. 


Then, flash the Arduino code `trees.ino` onto your ESP32 controlling servo motors and flash the Arduino code `claws.ino` onto the ESP32 controlling the stepper motors. If the code doesn't seem to be working, try resetting the ESP32. 


## The API
This project was originally connected to a web API so that when a button was clicked, the motors would all start up and the structure would run for 30 seconds. To access the button to start the sculture go to the following URL, where you replace YOUR-UNI with your UNI:
http://165.227.76.232:3000/YOUR-UNI

Make sure that the API endpoint in both Arduino files is correct:
~~~C++
String address= "http://165.227.76.232:3000/YOUR-UNI/running";
~~~

If you also want to just run the sculture without having the API setup, you can do that as well. In the `loop()` functions for both files just remove the lines where the HTTP request is made to the server, and your code should be good to run.

<br>
 <img src="https://github.com/Cina10/EmbeddedSys_Kinetic/blob/master/Images/Sculpture.jpeg" width="500">
 <br>
