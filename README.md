# Wearable Air Gesture Keyboard

A wearable hardware-based device that allows users to type characters and control computer interfaces in mid-air through hand gestures.

## 🛠️ Hardware Components
* **Microcontroller:** Arduino Leonardo (or ATMega32U4 based board for native USB keyboard emulation)
* **Inertial Measurement Unit (IMU):** MPU6050 Gyroscope/Accelerometer (to track hand tilt and movement)
* **Flex Sensors:** Placed on fingers to detect individual finger bending/triggering
* **Connection:** USB Interface / Bluetooth Module (HC-05)

## 🚀 How it Works
1. The MPU6050 detects raw angular and acceleration velocities when the hand moves or tilts.
2. Flex sensors detect if specific fingers are bent.
3. The Arduino parses these analog inputs, translates them into keypress values (e.g., Space, Backspace, or letters), and sends them as HID (Human Interface Device) keypresses to the computer.
