The code establishes an IoT-based environment control system that ensures optimal growth conditions for indoor plants. It integrates temperature and humidity readings, soil moisture level detection, water level monitoring, and light intensity measurements. The system maintains an LCD display for real-time data visualization and employs various actuators like fans, pumps, lamps, and a humidifier atomizer plate to adjust environmental conditions accordingly. The system communicates with the Blynk server, enabling remote monitoring and control through a mobile app. It also incorporates thresholds for temperature and humidity, ensuring the environment stays within specified ranges. When certain conditions are met, such as low soil moisture or empty water tanks, the system generates alerts to ensure prompt intervention.


**Libraries Used:**


* **WiFi.h** and **WiFiClient.h**: These libraries enable the ESP32 to connect to a Wi-Fi network and establish internet connectivity.
* **BlynkSimpleEsp32.h**: This library facilitates communication between the ESP32 and the Blynk server, allowing for remote control and monitoring via the Blynk mobile app.
* **DHT.h**: This library provides functions for reading temperature and humidity data from the DHT11 sensor.
* **Wire.h** and **LiquidCrystal_I2C.h**: These libraries are used to interact with the LCD display via the I2C protocol.


**Note:** Ensure that you have installed the necessary libraries in your Arduino IDE to successfully compile and upload the code to your ESP32 board.


The provided code is designed to create a system that adapts to the varying needs of different plants and ensures optimal growth conditions, contributing to the overall health and vitality of indoor plants.
