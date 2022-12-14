# Project 2 - Move

For my second project (Move), I decided to create a simple Unity app controlled by an Arduino board using a distance sensor as an input and a servo motor as an output. 

My experience goal is to provide users with a simple and fun mini-game to mess around with.

# Development Process

First, I created a project in Unity with a scene that included a rectangular surface, a boxing glove made up of a sphere and a cylinder, and a bunch of cubes stacked on top of the surface. I originally made code that moved the glove with the arrow keys to test the "punching" mechanic. I ran into an issue where the glove could go through the stack of cubes without them reacting until it got to a specific position in the map. I solved this by giving the glove object a Rigidbody component and placing constraints so it wouldn't move or rotate on its own.

Next, I started programming a distance check for the Arduino using the HC-SR04 sensor as an input. I borrowed most of the code from an example in class (linked to in the References section below). I went through the process twice since I didn't know if I programmed the distance check correctly the first time. I used an LED as a temporary output to make sure the check worked (an example we went through in class), then when I was sure it worked, I removed the LED output.

Then, I modified the Unity project to communicate with the Arduino through a serial port. I wrote code that took the printed output of the Arduino (borrowed from another in-class example), converted it to a float, divided it by 200, subtracted it by 1, then set the glove's Z posiiton to that number. I found that the distance sensor was a bit unreliable for small objects, so I came up with an idea to use a tissue box to cover more surface area, making it easier for the sensor to pick up.

After that, I added a servo motor into the mix to indicate when the glove reached a position where it could hit the cube tower. The servo motor goes downward when the glove is out of range and goes upward when the glove is in range. I added additional code to the distance check to handle this behavior. The servo's value is set to 180 when the distance is greater than or equal to 500 units, and the value is set to 0 when the distance is less than 500 units. I also made some changes to the code to calculate the average of eight input values and then print that out to the serial port. This prevented the glove from jittering as much as it did before this change.

Finally, I put some finishing touches on the presentation by covering the tissue box in brown construction paper to make it look more like a glove, cutting out a small triangle to paste onto the servo motor, and drawing a target, cutting it out with holes, to slide onto the distance sensor. I also gave the objects in the Unity project color.

# Code

https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P2%20Move/PComp%20-%20P2%20Move%20Code.ino

# Pictures / Video

Top-down view of the project:
![Breadboard with an Arduino, a distance sensor, and a servo motor](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P2%20Move/PComp%20-%20P2%20Move%20Top%20Down%20View.jpg?raw=true)

Servo motor down:
![Same, but at different angle](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P2%20Move/PComp%20-%20P2%20Move%20Servo%20Down.jpg?raw=true)

Servo motor up:
![Same, but with the servo pointing up](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P2%20Move/PComp%20-%20P2%20Move%20Servo%20Up.jpg?raw=true)

Video link: https://drive.google.com/file/d/1_pPxsaXbeynpk-hOwB109bdgeWiqOqzY/view?usp=share_link

# Diagram

![Diagram of the top-down view](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P2%20Move/PComp%20-%20P2%20Move%20Diagram.png?raw=true)

# References

- Class notes (5-2, 7-2, 9-1)
- https://create.arduino.cc/editor/wmharris/411cdb7c-3c68-4c38-9162-6686ca95db31/preview
- https://docs.arduino.cc/learn/electronics/servo-motors
- https://answers.unity.com/questions/59355/change-the-material-on-an-object-in-a-script.html
