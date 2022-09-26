# Project 1 - Blink

For my first project (Blink), I decided to create an interaction between two LEDs, a pontentiometer, and a switch. My idea was to have the potentiometer control how fast the LEDs flash, with the switch determining whether one of the two LEDs was active or not. One LED would flash, and the other would flash in the opposite voltage from the first LED.

My experience goal is to provide users with a fun way to alter the speed of flashing LEDs.

# Development Process

I started off by testing the potentiometer to see what values I was getting. I used the potentiometer example code given in class to print the input value to the serial monitor. The highest value I got was around 1023, and the lowest value I got was 0.

Next, I programmed code to make the LED flash whenever a counter went down to 0. The counter would go down by the input value rougly every other millisecond and get reset to a value of 1024\*8 every time it went to 0. However, this made the LED flash too fast if the potentionmeter was cranked up all the way. To combat this, I divided the input value by 4 so the highest value would only be roughly 255.

Then, I sent the code to the Arduino and tested it to make sure the LED flashed appropriately. After that, I added code to make the other LED flash in the opposite pattern from the first when the switch was on.

# Pictures / Video

(ADD PICTURES HERE)

Video link: 

# Diagram

(ADD PICTURE OF FRITZING DIAGRAM HERE)

# References

- Class notes (3-1, 3-2, 4-1)
- https://docs.arduino.cc/built-in-examples/digital/Button
- https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
