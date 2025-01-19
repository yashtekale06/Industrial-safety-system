# 🚨 Industrial Safety System

An advanced Industrial Safety System designed to monitor and respond to critical environmental and operational parameters. This project uses the ESP32 microcontroller, sensors, and an LCD for data display, and serves a web interface for remote monitoring.

## 🌟Features

- **📊Real-Time Monitoring:** Monitors temperature, humidity, smoke, fire, and light conditions.
- **🌐ESP32-Based Web Server:** Hosts a web interface displaying live sensor data.
- **🔔 Alerts and Notifications:** Activates a buzzer and LED during critical events like fire detection.
- **⚙️ Automatic Controls:** Adjusts motor operation based on humidity levels and controls lights based on day/night conditions.
- **📟LCD Display:** Displays live sensor readings.

## 🔧Components

1. **🖥️Microcontroller:** ESP32
2. **📡Sensors:**
   - 🌡️DHT11 (Temperature and Humidity)
   -  💨Smoke Sensor
   - 🔥 Fire Sensor
   - 💡LDR (Light-Dependent Resistor)
3. **Output Devices:**
   - 🔔Buzzer
   - 💡LED
   - ⚙️ Motor
4. **📟LCD Display:** 16x2 LCD with I2C module
5. **🌐Wi-Fi:** Built-in ESP32 Wi-Fi for hosting a web server

## 📋Circuit Diagram
Connect the components as follows:

- **DHT11:** Pin 2
- **Smoke Sensor:** Pin 33
- **Fire Sensor:** Pin 34
- **Buzzer:** Pin 4
- **LDR Sensor:** Pin 35
- **Motor:** Pin 15
- **LED:** Pin 5

Ensure proper power supply and grounding for all components.

## 📝  Code Explanation

The Arduino sketch performs the following tasks:

1. Initializes the sensors, LCD, and Wi-Fi.
2. Reads sensor data:
   - Humidity and temperature from the DHT11 sensor.
   - Smoke levels from the smoke sensor.
   - Fire status from the fire sensor.
   - Day/night status from the LDR sensor.
3. Displays sensor data on the LCD and updates the web interface.
4. Triggers the buzzer and displays warnings on the LCD when fire is detected.
5. Controls the motor based on humidity levels.
6. Manages the LED based on day/night conditions.

## 🌐Web Interface

The system hosts a web page showing live sensor data. The page refreshes every second to provide real-time updates. Data displayed includes:

- Temperature
- Humidity
- Smoke Levels
- Fire Status
- Day/Night Indicator

## ⚙️Installation and Usage

1. **🛠️ Hardware Setup:**

   - Assemble the circuit as per the diagram.
   - Connect sensors and output devices to the respective pins.

2. **💻Software Setup:**

   - Install Arduino IDE and ESP32 board manager.
   - Add required libraries: `LiquidCrystal_I2C`, `WiFi`, `WebServer`, and `DHT`.
   - Upload the provided code to the ESP32.

3. **🚀Run the System:**

   - Power up the ESP32 and connected devices.
   - Access the web interface via the ESP32 Access Point (`ESP32-Access-Point`) at IP `192.168.4.1`.

## 🏭 Applications

- 🏭 Industrial environments

- ⚠️ Hazardous workplaces

- 🏠 Home automation systems

## 🤝Contribution

Contributions are welcome! If you'd like to contribute:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Submit a pull request for review.



## 📩 Contact

For queries or suggestions, please reach out:

 [![GitHub](https://img.shields.io/badge/GitHub-Profile-black?logo=github&style=for-the-badge)](https://github.com/yashtekale06)

