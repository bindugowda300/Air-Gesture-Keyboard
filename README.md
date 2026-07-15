import serial
import pyautogui
import time

# Configure the serial port connected to your hardware (Bluetooth or USB)
# Change 'COM3' to your hardware's active COM port on Windows
SERIAL_PORT = 'COM3' 
BAUD_RATE = 9600

try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=0.1)
    print(f"Connected to Air Gesture Hardware on {SERIAL_PORT}")
except Exception as e:
    print(f"Error connecting to serial port: {e}")
    ser = None

def process_gesture(data_line):
    """
    Decodes gesture data from the wearable hardware and emulates keypresses.
    """
    data = data_line.strip()
    if not data:
        return
        
    print(f"Hardware signal received: {data}")
    
    # Map signals to keyboard keypresses
    if data == "INDEX_BENT":
        pyautogui.write('A')
    elif data == "THUMB_BENT":
        pyautogui.write(' ')
    elif data == "TILT_LEFT":
        pyautogui.press('left')
    elif data == "TILT_RIGHT":
        pyautogui.press('right')

if __name__ == "__main__":
    if ser:
        try:
            print("Listening for gestures...")
            while True:
                if ser.in_waiting > 0:
                    line = ser.readline().decode('utf-8', errors='ignore')
                    process_gesture(line)
                time.sleep(0.01)
        except KeyboardInterrupt:
            print("Program stopped.")
            ser.close()
