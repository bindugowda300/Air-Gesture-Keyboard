# Air Gesture Based Keyboard for Visually Impaired Peoples

A wearable assistive technology system that allows users to type characters in mid-air using hand gestures. Motion signals from an **MPU-6050 accelerometer** are transmitted to a PC over serial communication, where a **Machine Learning Support Vector Machine (SVM)** classifier trained with Scikit-learn classifies gestures into characters in real time.

---

## 📌 Features

- **Hardware Glove / Sensor Unit:** Uses Arduino Nano and an MPU-6050 accelerometer to capture 3-axis motion and gestures.
- **Machine Learning Classification:** Utilizes Scikit-learn's `SVC` (Support Vector Classifier) with Grid Search optimization to recognize gestures accurately.
- **Interactive Tkinter Display:** Displays recognized text in a GUI window (`window.py`) as characters are typed.
- **Autocorrect & Word Suggestions:** Integrated dictionary engine (`dict/english.txt`) provides suggestions and autocorrects misclassified letters.
- **Training & Recording Pipeline:** Easy-to-use CLI to record new gesture samples for any character and retrain the model.

---

## 🛠️ System Architecture & Tech Stack

- **Hardware:** Arduino Nano / Uno, MPU-6050 Accelerometer & Gyroscope, Push button trigger, Serial/Bluetooth communication
- **Software & Libraries:**
  - Python 3.x
  - `scikit-learn` (Support Vector Classifier)
  - `pyserial` (Serial communication with Arduino)
  - `numpy` & `joblib` (Data processing & model serialization)
  - `tkinter` (GUI display window)

---

## 🚀 Setup & Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/bindugowda300/Air-Gesture-Keyboard.git
   cd Air-Gesture-Keyboard
   ```

2. **Install dependencies:**
   ```bash
   pip install -r requirements.txt
   ```

3. **Upload Arduino Code:**
   - Open `Arduino/gesture_sensor/gesture_sensor.ino` in the Arduino IDE.
   - Connect the Arduino Nano with MPU-6050 and upload the sketch.

---

## 💻 How to Use

### 1. Recording Gesture Samples
To record samples for a specific letter (e.g. character `a`, batch `0` on port `COM3`):
```bash
python start.py target=a:0 port=COM3
```
*Hold the button on the device while performing the gesture in the air and release when finished.*

### 2. Training the SVM Classifier
Once sample data is collected in the `data/` folder, train the model:
```bash
python learn.py
```
This performs grid search optimization on the dataset and exports `model.pkl` and `classes.pkl`.

### 3. Real-Time Gesture Prediction & Typing
Run the GUI window:
```bash
python window.py
```
In a separate terminal, start the prediction reader:
```bash
python start.py port=COM3 predict
```
Characters gestured in mid-air will be recognized by the SVM model and displayed live on screen!

---

## 📁 Repository Structure

```
├── Arduino/
│   └── gesture_sensor/
│       └── gesture_sensor.ino   # Arduino firmware for MPU-6050
├── dict/
│   └── english.txt              # Dictionary wordlist for suggestions
├── air_gesture_keyboard.py      # Main script
├── start.py                     # CLI for recording, writing & predicting
├── learn.py                     # Machine learning SVM training script
├── signals.py                   # Signal filtering & feature extraction
├── suggestions.py               # Autocorrect and word suggestion engine
├── window.py                    # Tkinter GUI window to display text
├── test.py                      # Quick test for model loading
├── requirements.txt             # Python dependencies
└── README.md                    # Project documentation
```
