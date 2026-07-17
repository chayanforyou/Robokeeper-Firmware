# Robokeeper Firmware & App

This repository contains the **ESP32 firmware** and the **Necessary files** for the **Robokeeper** project—a smart robotic goalkeeper that tracks a ball in real-time using OpenCV and dynamically moves a servo-controlled keeper arm to block shots.

<p><a href="https://youtube.com/shorts/6pw2aRaE8rs">
  <img src="Cover Photo.png" width="70%" alt="Robokeeper">
</a></p>

### Download App
You can download the Android app directly from latest releases:
- [Robokeeper APK](https://github.com/chayanforyou/Robokeeper-Firmware/releases/latest)

---

## How It Works
1. **Target Identification**: Place the Android device in front of the mini-goal. The Android app uses OpenCV to lock onto the ball based on a selected color range (configured by tapping the ball on screen).
2. **Trajectory Prediction**: As the ball is shot towards the goal, the app tracks its positions and fits a regression model (Linear or Quadratic) to predict the exact coordinate where the ball will cross the goal line.
3. **Bluetooth Transmission**: The app calculates the target blocking angle and transmits it in real-time over Bluetooth to the ESP32.
4. **Physical Save**: The ESP32 receives the angle and drives a high-speed servo motor to rotate the goalkeeper arm, blocking the ball.

---

## Hardware Requirements
- **Microcontroller**: ESP32 Development Board (requires built-in Bluetooth Classic support).
- **Servo Motor**: High-speed metal gear servo (e.g., MG996R, DS3218, or coreless high-speed servo).
- **Goalkeeper Arm**: A lightweight blocking paddle/keeper model attached to the servo horn.
- **Power Supply**: Dedicated battery pack or UBEC regulator (5V–6V, 2A+) to feed the servo and prevent the ESP32 from resetting during rapid movements.
- **Smartphone**: Android device (mounted securely above the goal looking down the pitch).

---

## Installation & Setup

### 1. ESP32 Firmware
1. Open the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the **ESP32 Dev Board** package if you haven't already.
3. Install the **ESP32Servo** library from the Library Manager.
4. Open [Robokeeper.ino](./Robokeeper/Robokeeper.ino) and upload it to your ESP32.
5. Once uploaded, the ESP32 will broadcast a Bluetooth device named `Robokeeper-ESP32`.

### 2. Android App
1. Install the **Robokeeper.apk** to your Android device.
2. Turn on Bluetooth on your phone and pair with `Robokeeper-ESP32`.
3. Open the app, select the paired ESP32 from the device list, and click **Connect**.
4. Set up your camera view, tap the ball on the preview screen to select its color range, and start playing!

---

## Features
- **Real-Time Color Tracking**: Responsive color-thresholding and contour identification using OpenCV.
- **Trajectory Regression**: Instantly predicts crossing points on the goal line using Linear/Quadratic fit.
- **Dynamic Camera Zoom**: Configurable hardware-level zoom (1.0x to 3.0x) via the settings menu to narrow in on the pitch.
- **Hawkeye 3D Visualizer**: A broadcast-style cinematic overlay showing predicted flight arcs, ground shadows, impact reticles, and latency telemetry.
- **Developer Debug Panel**: On-screen statistics showing live FPS, processing latency (ms), servo commands, and regression coefficients.
