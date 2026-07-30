# Arduino Smart Lighting System (IoT)

An Arduino-based automatic lighting system that combines a light sensor (LDR) with three IR object-detection sensors to control three LEDs independently.

## How it works

- An LDR (light-dependent resistor) checks ambient light. The system only activates when it's dark.
- Three IR sensors each watch for a nearby object (e.g. a car or person passing a point).
- When it's dark and an IR sensor detects an object, its corresponding LED turns on; otherwise that LED stays off.
- In daylight, all LEDs stay off regardless of the IR sensors, saving power.

This mirrors real-world smart street lighting: lights only switch on for a detected presence, and only after dark.

## Files

- `ArduinoCode.ino` — the microcontroller sketch (setup + main loop)
- `circuit design.png` — the wiring/circuit diagram

## Hardware

- Arduino board (Uno/compatible)
- 1x LDR (light sensor)
- 3x IR obstacle/object sensors
- 3x LEDs

Built as part of a BTEC Level 5 HND Internet of Things unit.
