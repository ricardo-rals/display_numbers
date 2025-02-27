# Display Numbers Project

This project implements a simple number display system using a matrix display and buttons for user interaction. The user can increment or decrement a displayed number (from 0 to 9) using two buttons. Additionally, a red LED blinks to indicate that the system is active.

## Table of Contents

1. [Features](#features)
2. [Hardware Requirements](#hardware-requirements)
3. [Software Requirements](#software-requirements)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Code Structure](#code-structure)
7. [Video Tutorial](#video-tutorial)

## Features

- Increment and decrement a number displayed on a matrix display using two buttons.
- Blink a red LED to indicate system activity.
- Debounce button presses to ensure reliable input.
- Display numbers from 0 to 9 using a predefined pattern.

## Hardware Requirements

- Raspberry Pi Pico or compatible microcontroller.
- 5x5 matrix display.
- Two push buttons (BUTTON_A and BUTTON_B).
- One red LED.
- Resistors for buttons and LED (if necessary).
- Breadboard and jumper wires for connections.

## Software Requirements

- Visual Studio Code with the C/C++ extension.
- Raspberry Pi Pico SDK.
- CMake for building the project (if needed for other setups).

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/display_numbers.git
   cd display_numbers
   ```

2. Open the project in Visual Studio Code.

3. Set up the Raspberry Pi Pico W SDK according to the [official documentation](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

4. Follow the instructions in Visual Studio Code to build and upload the project to your Raspberry Pi Pico.

## Usage

1. Connect the hardware components as per the schematic.
2. Power on the Raspberry Pi Pico.
3. The initial number displayed will be `0`.
4. Press BUTTON_A to increment the number and BUTTON_B to decrement it.
5. The red LED will blink every 200ms to indicate that the system is running.

## Code Structure

- `button_control.c`: Handles button initialization and interrupt service routines for button presses.
- `led_control.c`: Manages the blinking of the red LED.
- `matrix_display.c`: Contains functions for displaying numbers on the matrix display.
- `numbers.c`: Defines the patterns for numbers 0-9.
- `display_numbers.c`: The main application file that initializes the system and runs the main loop.

## Video Tutorial

For a visual guide on how to set up and run this project, check out this 
[YouTube video](https://www.youtube.com/watch?v=_D2JNvoOLlQ).
