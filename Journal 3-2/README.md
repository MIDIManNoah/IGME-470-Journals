# 3-2 - Moarrr Digital Ins and Outs

For my digital ins and outs project, I wanted to program something using the AND and XOR operators. What I did was have two LEDs (one red, one yellow) connected to an Arduino, and two switches connected to the same Arduino. The switches control which LED was turned on. If neither switch is on, then both LEDs are off. If one switch is on, then only the yellow LED turns on. If both switches are on, then only the red LED turns on.

The only thing I got stuck on was figuring out how to implement an XOR operator in my code. I did some research and found out you could just use the bitwise XOR operator (^) to compare two conditional statements.

One Switch On:
![Breadboard with one switch on and one yellow LED on](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/Journal%203-2/PComp%20-%20Journal%203-2%20One%20Switch.jpg?raw=true)

Two Switches On:
![Breadboard with two switches on and one red LED on](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/Journal%203-2/PComp%20-%20Journal%203-2%20Two%20Switches.jpg?raw=true)

Code: https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/Journal%203-2/PComp%20-%20Journal%203-2%20Code.ino

Sources: https://forum.arduino.cc/t/coding-an-xor/215527
