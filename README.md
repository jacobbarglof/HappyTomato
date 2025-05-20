# HappyTomato V1 🍅

*A minimalist productivity device powered by ESP32, featuring a Pomodoro timer, Stopwatch, Breathing Excercises, and more.*

---

##  Project Overview

HappyTomato V1 is a microcontroller-based personal productivity assistant built on the ESP32 platform. It combines simplicity with utility, offering a tactile interface to boost focus and mindfulness through custom timer modes. The project leverages PlatformIO for development, structuring, and deployment.

---

## Features

* **Pomodoro Timer** – 25/5 minute cycles to optimize focus and break periods.
* **Stopwatch** – Millisecond-accurate tracking for any timed activity.
* **Progress Timer** – A countdown with adjustable duration for general tasks.
* **Breathing Mode** – Guided inhale-exhale prompts for stress reduction.
* **Power Nap** – Short-timed naps with optional vibration/alarm support (future update).
* **Rotary Encoder Interface** – Scroll/select intuitive tactile control.
* **OLED UI** – Clear, pixelated display menu and feedback using SSD1306.
* **Modular Design** – Easily extendable for new features like habit tracking, hydration reminders, and more.

---

##  Table of Contents

* [Installation](#installation)
* [Hardware Overview](#hardware-overview)
* [Usage Instructions](#usage-instructions)
* [Project Structure](#project-structure)
* [Feature Details](#feature-details)
* [PlatformIO Integration](#platformio-integration)
* [To-Do / Future Work](#to-do--future-work)
* [License](#license)

---

##  Installation

1. **Install PlatformIO**

   * Via [VSCode Extension](https://platformio.org/install/ide?install=vscode)
   * Or via `pip install platformio` (for CLI use)

2. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/happytomato-v1.git
   cd HappyTomatoV1
   ```

3. **Build the Project**

   ```bash
   pio run
   ```

4. **Upload Firmware**

   ```bash
   pio run --target upload
   ```

5. **Monitor Serial Output (Optional)**

   ```bash
   pio device monitor
   ```

---

## 🧰 Hardware Overview

| Component            | Description                         |
| -------------------- | ----------------------------------- |
| ESP32 DevKit-C       | Core microcontroller with Wi-Fi/BLE |
| OLED Display (0.96") | I2C, SSD1306-based                  |
| Rotary Encoder       | With push-button (EC11 or similar)  |
| Perfboard            | For stable soldered prototyping     |
| Micro USB Cable      | Power and flashing interface        |

**Pinout (default, may vary):**

* SDA → GPIO 21
* SCL → GPIO 22
* Encoder A/B → GPIO 32 / GPIO 33
* Encoder Button → GPIO 25
* OLED Address → `0x3C`

---

## ▶️ Usage Instructions

1. **Power the device** via USB or battery.
2. **Navigate Menu**:

   * Rotate encoder to scroll through options.
   * Press encoder to select.
3. **Modes**:

   * **Pomodoro**: Starts a 25 min session. A break prompt follows.
   * **Stopwatch**: Starts/stops on press. Resets on long press.
   * **Progress**: Countdown timer with preset durations.
   * **Breathing**: Displays timed inhale/exhale animations.
   * **Power Nap**: Set nap time (default 20 min). Will include optional buzz alarm.

OLED screen displays the current status and timers.

---

## 📂 Project Structure

```
happytomato-v1/
├── include/                # Header files (if needed)
├── lib/                    # Optional external libraries
├── src/
│   ├── main.cpp            # Main application entry point
│   ├── MenuManager.cpp     # UI navigation logic
│   ├── TimerModes.cpp      # Pomodoro, Stopwatch, etc.
│   └── DisplayManager.cpp  # OLED rendering logic
├── platformio.ini          # PlatformIO configuration
└── README.md               # This documentation
```

---

## 👋 Feature Details

### ✅ Pomodoro

* 25 minutes work + 5 minutes break cycle
* Flashing OLED or buzz alert on transitions
* Goal: 4 cycles/day for peak productivity

### ✅ Stopwatch

* Precision-timed using millis()
* Press to start/stop
* Long press to reset

### ✅ Breathing

* Visual breathing guide (e.g. "Inhale... Exhale...")
* Optional vibration feedback (future)

### ✅ Progress Timer

* Choose task length (e.g., 10, 20, 45 min)
* Countdown display

### 💤 Power Nap

* 20 min default nap countdown
* Alert planned via piezo or screen flashing

---

## ⚙️ PlatformIO Integration

### `platformio.ini`

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
lib_deps =
  adafruit/Adafruit GFX Library
  adafruit/Adafruit SSD1306
  encoder
```

### Benefits of PlatformIO:

* **Automated dependency management**
* **Integrated Serial Monitor**
* **Cross-platform build system**
* **Easy debugging and deployment**

---

## To-Do / Future Work

* [ ] Better visuals and integrate the sprite
* [ ] Add more features to the apps
* [ ] Have an online app library
* [ ] Build an enclosure or a PCB

---

## 📄 License

MIT License
©2025 Jacob Barglof
Feel free to fork, modify, or contribute.

---
