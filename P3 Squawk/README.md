# Project 3 - Squawk

For my third and final project (Squawk), I decided to create three different melodies played back on a piezo speaker that are controlled by paperclip-based switches. The notes of the melodies are displayed on a keyboard in a Unity app.

My experience goal is to let users mix and match melodies by "activating" paperclips and see the notes displayed in the app.

# Development Process

First, I set up two alligator clips with a paperclip on each. I attached one alligator clip to power on my breadboard and another alligator clip to an input on the Arduino. Then, I made a quick program for the Arduino to test the connection to make sure it worked.

Next, I borrowed the code from the sunshine melody demo we did in class and edited it to handle three different melodies at once. I used two more alligator clips with a paperclip on each for two more inputs. I tested each input to make sure they worked when connected to power. I also tested multiple inputs at once to make sure they worked as well.

Then, I created an app in Unity that took a stream of data from the Arduino and displayed the notes from each melody on a keyboard. Figuring out how to do this was a real challenge. My original plan was to take the note pitch and the note duration and have the notes on the keyboard highlighted for the duration given. However, I found out that the app was only updating everything time the Arduino sent a message to it via serial communication. To compensate, I made it so every note overlay is moved behind the keyboard every time a note is read in and move the overlay for the currently playing note in front of the keyboard.

Finally, I made some finishing touches to the presentation. I reused the boxing glove I made for the previous project, P2 Move, and I covered the top and side of it to make sure very little of Arduino was visible.

# Code

https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P3%20Squawk/P3Squawk.ino

https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P3%20Squawk/notes.h

# Pictures / Video

The project without its box:
![Project on its own](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P3%20Squawk/PComp%20-%20P3%20Squawk%20No%20Box.jpg?raw=true)

The project inside the box:
![Project inside of a box](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P3%20Squawk/PComp%20-%20P3%20Squawk%20Box.jpg?raw=true)

One connection:
![One paperclip connection](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P3%20Squawk/PComp%20-%20P3%20Squawk%20One%20Connection.jpg?raw=true)

Three connections:
![Three paperclip connections](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P3%20Squawk/PComp%20-%20P3%20Squawk%20Three%20Connections.jpg)

Video Link: https://drive.google.com/file/d/1uXw_vpAZqieJXDuHmY76JGJ1wpjRjoeY/view?usp=sharing

# Diagram

![Diagram of the project](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P3%20Squawk/PComp%20-%20P3%20Squawk%20Diagram.png?raw=true)

The loose wires represent alligator clips with paperclips attached on the end. The other three wires not attached to power act as inputs for the power connection.

# References

- Class Notes (3-1, 7-2, 11-2)
- https://create.arduino.cc/editor/wmharris/01bb396f-6707-42c8-8c8f-8c167f599acb/preview
