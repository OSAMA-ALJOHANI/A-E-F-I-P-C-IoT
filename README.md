# A-E-F-I-P-C-IoT

**IoT-Based Adaptive Environment for Indoor Plant Cultivation**


The Adaptive Environment for Plants is an Internet of Things (IoT) based system designed to optimize indoor plant growth by creating a tailored and efficient growing environment. This system utilizes various sensors, actuators, and a mobile app to monitor and control key environmental factors for plant health and growth.


**Features**


* **Customizable Plant Profiles:** Create individualized profiles for different plants, specifying ideal conditions and care instructions.

* **Sensor Integration:** The system integrates various sensors including LDR (Light Dependent Resistor), capacitive soil moisture sensor, and DHT11 (Temperature and Humidity) sensor.

* **Actuator Control:** Control actuators such as water pump, fans, humidifier atomizer plate, and lamp light.

* **Smart Watering:** The water pump activates when soil moisture drops below a threshold and stops when it reaches optimal levels, conserving water.

* **Remote Monitoring:** Access and control the system remotely via a mobile app created using the Blynk library.

* **Notifications:** Receive notifications about plant health issues detected by sensors.


**Hardware Components**


* ESP32 Microcontroller
* LDR (Light Dependent Resistor)
* Capacitive Soil Moisture Sensor
* DHT11 Temperature and Humidity Sensor
* Water Pump
* Fans
* Humidifier Atomizer Plate
* Lamp Light
* LCD Display


**Software Components**


* Arduino IDE for programming the microcontroller.
* Blynk Library for creating the mobile app and connecting to the Blynk server.


**Installation and Setup**
1. Clone this repository to your local machine.
2. Open the Arduino IDE and load the provided code.
3. Install the necessary libraries including the Blynk library.
4. Connect the hardware components according to the provided schematic.
5. Customize the code to match your hardware setup and preferences.
6. Create an account on the Blynk platform and obtain an API token.
7. Update the code with your Blynk API token and Wi-Fi credentials.
8. Upload the code to the ESP32 microcontroller.
9. Download the Blynk app on your mobile device and configure it using the provided template.


**Usage**
* Open the Blynk app and log in.
* Use the app to monitor sensor readings, control actuators, and adjust settings.
* Create and manage plant profiles for optimized growth conditions.
* Receive notifications in case of any plant health issues.


**Contributing**


Contributions are welcome! Please fork this repository and submit a pull request with your enhancements.

License
This project is licensed under the MIT License.
