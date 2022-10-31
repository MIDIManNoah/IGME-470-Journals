# Project 2 - Move

For my second project (Move), I decided to create a simple Unity app controlled by an Arduino board using a distance sensor as an input and a servo motor as an output. 

My experience goal is to provide users with a simple and fun app to kill time with (change the wording?).

# Development Process

First, I created a project in Unity with a scene that included a rectangular surface, a boxing glove made up of a sphere and a cylinder, and a bunch of cubes stacked on top of the surface. I originally made code that moved the glove with the arrow keys to test the "punching" mechanic. I ran into an issue where the glove could go through the stack of cubes without them reacting until I got to a specific position in the map. I solved this by giving the glove object a Rigidbody component and placing constraints so it wouldn't move or rotate on its own.

Next, I started programming a distance check for the Arduino using the HC-SR04 sensor as an input. I borrowed most of the code from an example in class (linked to in the References section below). I went through the process twice since I didn't know if I programmed the distance check correctly the first time. I used an LED as a temporary output to make sure the check worked (an example we went through in class), then when I was sure it worked, I removed the LED output.

Then, I modified the Unity project to communicate with the Arduino through a serial port. I wrote code that took the printed output of the Arduino, converted it to a float, divided it by a number (CHANGE), subtracted it by 1, then set the glove's Z posiiton to that number. I found that the distance sensor was a bit unreliable for small objects, so I came up with an idea to use a tissue box to cover more surface area, making it easier for the sensor to pick up.

After that, I added a servo motor into the mix to indicate when the glove would get in a position where it could hit the cube tower. The servo motor goes downward when the glove is out of range and goes upward when the glove is in range. I added additional code to the distance check to handle this behavior (INSERT CODE EXAMPLE HERE). I also made some changes to the code to calculate the average of ten values input and then print that out to the serial port. This prevented the glove from jittering as much as it did before this change.

Finally, I put some finishing touches on the presentation by covering the tissue box in red construction paper to make it look more like a glove, cutting out a small triangle to paste onto the servo motor, and creating and printing out a target graphic to slide onto the distance sensor.

# Code

(INSERT LINK HERE)

# Pictures / Video

(INSERT PICTURES HERE)

(INSERT VIDEO HERE)

# Diagram

(INSERT DIAGRAM HERE)

# References

- Class notes (5-2, 7-2, 9-1)
- https://create.arduino.cc/editor/wmharris/411cdb7c-3c68-4c38-9162-6686ca95db31/preview
- https://docs.arduino.cc/learn/electronics/servo-motors
