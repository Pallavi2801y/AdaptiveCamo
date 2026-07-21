# AdaptiveCamo – Adaptive Camouflage System

## Overview

AdaptiveCamo is an ESP32-based embedded system that demonstrates real-time environmental color adaptation. The system continuously detects the dominant ambient color using a TCS3200 color sensor and reproduces the detected color on an RGB LED matrix.

The project demonstrates sensor interfacing, embedded signal processing, RGB color mapping, and real-time LED control using the ESP32 platform.

## Features

- Real-time ambient color detection
- TCS3200 color sensor interfacing
- RGB calibration and normalization
- Dominant color extraction
- Dynamic RGB LED matrix control
- ESP32-based embedded implementation

## Hardware Components

- ESP32 Development Board
- TCS3200 Color Sensor
- 8×8 WS2812B RGB LED Matrix
- USB Power Supply

## Software

- Arduino IDE
- Embedded C/C++
- Adafruit NeoPixel Library

## Working Principle

1. The TCS3200 sensor measures the intensity of Red, Green and Blue components of the surrounding object.
2. Raw sensor values are calibrated using experimentally determined minimum and maximum values.
3. The calibrated RGB values are mapped to the 0–255 range.
4. The dominant color component is identified.
5. The ESP32 updates every LED of the RGB matrix to display the detected color in real time.

## Implemented Concepts

- Embedded Systems
- Sensor Interfacing
- RGB Color Processing
- Signal Calibration
- PWM LED Control
- Real-Time Data Processing

## Future Improvements

- Multi-color pattern generation
- Machine learning based color classification
- Flexible LED strips for wearable camouflage
- Camera-based color detection
- Low-power wearable implementation

## Project Status

✅ Prototype Completed

The project successfully demonstrates real-time ambient color sensing and adaptive color reproduction using an ESP32, TCS3200 color sensor, and RGB LED matrix.
