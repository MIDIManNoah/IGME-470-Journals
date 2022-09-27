# Project 1 - Blink

For my first project (Blink), I decided to create an interaction between two LEDs, a pontentiometer, and a switch. My idea was to have the potentiometer control how fast the LEDs flash, with the switch determining whether one of the two LEDs was active or not. One LED would flash, and the other would flash in the opposite voltage from the first LED.

My experience goal is to provide users with a fun way to alter the speed of flashing LEDs.

# Development Process

I started off by testing the potentiometer to see what values I was getting. I used the potentiometer example code given in class to print the input value to the serial monitor. The highest value I got was around 1023, and the lowest value I got was 0.

Next, I programmed code to make the LED flash whenever a counter went down to 0. The counter would go down by the input value rougly every other millisecond and get reset to a value of 1024\*8 every time it went to 0. However, this made the LED flash too fast if the potentionmeter was cranked up all the way. To combat this, I divided the input value by 4 so the highest value would only be roughly 255.

Then, I sent the code to the Arduino and tested it to make sure the LED flashed appropriately. After that, I added code to make the other LED flash in the opposite pattern from the first when the switch was on.

One issue I ran into was that the potentiometer cranked all the way to the right made the LEDs flash slower. I solved this by subtracting the maximum possible input value by the current input value and using that to determine how much to subtract from the flash counter.

# Pictures / Video

Top-down view of the project:
![Breadboard with an Arduino, two LEDs, one potentionmeter, and one switch](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P1%20Blink/PComp%20-%20P1%20Blink%20Topdown.jpg?raw=true)

Arduino unplugged:
![Same, but at different angle](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P1%20Blink/PComp%20-%20P1%20Blink%20Angled.jpg?raw=true)

Switch off:
![Same, but with one LED on](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P1%20Blink/PComp%20-%20P1%20Blink%20Red%20LED.jpg?raw=true)

Switch on:
![Same, but with the switch on](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P1%20Blink/PComp%20-%20P1%20Blink%20Red%20LED%202.jpg?raw=true)

Switch on (other LED):
![Same, but with the other LED on](https://github.com/MIDIManNoah/IGME-470-Journals/blob/main/P1%20Blink/PComp%20-%20P1%20Blink%20Yellow%20LED.jpg?raw=true)

Video link: https://drive.google.com/file/d/1pnepoA5hmKAB7CSISWnlRhuyvq5SZhvM/view?usp=sharing

# Diagram

(ADD PICTURE OF FRITZING DIAGRAM HERE)

# References

- Class notes (3-1, 3-2, 4-1)
- https://docs.arduino.cc/built-in-examples/digital/Button
- https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
