# Home Automation Project

This project utilizes an ESP32 microcontroller along with various sensors and actuators to create a home automation system. The system monitors temperature, humidity, and altitude using the BME280 sensor and displays the data on the Blynk app. It also includes a fan that automatically turns off when the temperature exceeds 35 degrees Celsius, two switches to control home lights, a soil sensor that automatically activates a pump when soil moisture is low, and an IR sensor for object detection at the toll gate.

## Components Used
- ESP32 microcontroller
- BME280 temperature, humidity, and altitude sensor
- Servo motor
- Relay module
- Soil moisture sensor
- IR sensor

## Dependencies
The following libraries are required for this project:
- WiFi.h
- ESP32Servo.h
- BlynkSimpleEsp32.h
- Adafruit_Sensor.h
- Adafruit_BME280.h

## Circuit Diagram
Please refer to the circuit diagram for the connections of the components.

## Blynk App Configuration
To connect the project with the Blynk app, create a new project with the following settings:
- Template ID: TMPL3HN3UJmj-
- Template Name: home automation

## Blynk App Widgets
Configure the following widgets in the Blynk app:
- V0: Display temperature
- V1: Display humidity
- V2: Display altitude
- V3: Display pressure
- V4: Switch for home lights control
- V7: Display soil moisture level
- V8: Switch for fan control

## Installation and Setup
1. Install the required libraries mentioned above.
2. Replace the BLYNK_AUTH_TOKEN with your Blynk authorization token.
3. Modify the SSID and password in the `setup()` function to match your WiFi credentials.
4. Upload the code to your ESP32 microcontroller.
5. Open the Serial Monitor to view the sensor readings.
6. Launch the Blynk app and control the devices using the configured widgets.

## Pin Configuration
- irPin: 18
- pump3: 13
- fan: 27
- relayOut: 25
- relayOut4: 4
- soilsensor: 33

## Functionality
- The system continuously reads the sensor values from the BME280 sensor and displays them on the Blynk app.
- If the temperature exceeds 35 degrees Celsius, the fan turns off automatically.
- The home lights can be controlled using the switch on V4 in the Blynk app.
- The pump is activated when the soil moisture level is low, based on the reading from the soil moisture sensor.
- The toll gate is controlled by an IR sensor. When the IR sensor detects an object
