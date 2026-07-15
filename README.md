# Wearable Air Gesture Keyboard (Python & Hardware)

A wearable hardware-based glove that tracks hand movements and communicates with a laptop using Python to type characters in mid-air.

## 🛠️ Tech Stack & Components
* **Hardware:** Arduino Nano, MPU6050 Accelerometer, Flex Sensors, Bluetooth HC-05
* **Software Language:** Python (reads serial signals and emulates keypresses)
* **Python Libraries:** `pyserial` (serial reading), `pyautogui` (keyboard emulation)

## 🚀 How it Works
1. Wearable sensors (accelerometer & flex sensors) measure hand tilt and finger bends.
2. The microcontroller transmits these actions over Bluetooth to the laptop as serial packets (e.g., `TILT_LEFT` or `INDEX_BENT`).
3. The running **Python script** reads this incoming serial stream in real time and triggers corresponding system keypress events (like arrow keys, typing letters, or spacebar inputs).
