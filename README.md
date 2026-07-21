# AdaptiveCamo – Adaptive Camouflage System

## Overview

AdaptiveCamo is a proof-of-concept embedded system inspired by military adaptive camouflage. The project demonstrates real-time environmental color adaptation by detecting ambient RGB values using a TCS3200 color sensor and dynamically reproducing the detected color on a flexible 8×8 WS2812B RGB LED matrix.

Built around the ESP32 microcontroller, the system performs sensor interfacing, RGB calibration, dominant color extraction, and real-time LED control to simulate adaptive camouflage. The prototype serves as a low-cost demonstration of how embedded electronics can contribute to future smart camouflage systems.

---

## Features

- Real-time ambient color detection
- TCS3200 color sensor interfacing
- RGB calibration and normalization
- Dominant color extraction for enhanced color representation
- Real-time color reproduction on a flexible WS2812B RGB LED matrix
- ESP32-based embedded implementation
- Serial monitoring for sensor debugging and calibration

## Hardware Components

- ESP32 Development Board
- TCS3200 Color Sensor
- Flexible 8×8 WS2812B RGB LED Matrix
- USB Power Supply
- Jumper Wires

## Software

- Arduino IDE
- Embedded C/C++
- Adafruit NeoPixel Library

## Working Principle

1. The TCS3200 color sensor measures the Red, Green, and Blue components of the surrounding environment.
2. The ESP32 reads the frequency outputs corresponding to each color channel.
3. Raw RGB values are calibrated using predefined minimum and maximum reference values.
4. The calibrated values are mapped to the standard 0–255 RGB range.
5. The dominant color component is identified to improve visual representation.
6. The processed RGB values are transmitted to the flexible WS2812B RGB LED matrix.
7. The LED matrix dynamically updates its display in real time to match the detected ambient color.

## Implemented Concepts

- Embedded Systems
- Sensor Interfacing
- RGB Color Calibration
- RGB Value Mapping
- Dominant Color Extraction
- Addressable RGB LED Control (NeoPixel)
- Real-Time Data Processing
- Serial Debugging

## Future Improvements

- Dynamic multi-color camouflage pattern generation
- Flexible smart-fabric based adaptive camouflage
- AI-assisted terrain recognition and pattern optimization
- Thermal (IR) camouflage integration
- Wireless synchronization between multiple camouflage units
- Low-power wearable implementation

---

## Project Status

✅ **Prototype Completed**

The current prototype successfully demonstrates real-time ambient color detection, RGB calibration, dominant color extraction, and adaptive color reproduction using an ESP32, TCS3200 color sensor, and a flexible WS2812B RGB LED matrix.The project establishes the adaptive camouflage system and serves as a foundation for future wearable smart camouflage technologies.

The project successfully demonstrates real-time ambient color sensing and adaptive color reproduction using an ESP32, TCS3200 color sensor, and RGB LED matrix.
