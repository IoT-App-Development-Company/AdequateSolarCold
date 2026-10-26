#  IoT System – Hardware Configuration & Setup Instructions

Make the connections as shown below and power the Solar Battery System and the ssytem will work as expected

##  Table of Contents
- [Components List](#components-list)
- [Power Supply Architecture](#power-supply-architecture)
- [Arduino Pin Assignments](#arduino-pin-assignments)
- [Sensor Connections](#sensor-connections)
  - [DHT22 Sensors](#dht22-sensors)
  - [GY-906 MLX90614 Sensors](#gy-906-mlx90614-sensors)
  - [Relay Module](#relay-module)
  - [GSM Module (SIM800C)](#gsm-module-sim800c)
  - [Current Sensor](#current-sensor)
  - [Voltage Sensor](#voltage-sensor)
- [Power Distribution Summary](#power-distribution-summary)


---

##  Components List

| Component                              | Quantity |
|----------------------------------------|----------|
| Arduino Mega 2560                      | 1        |
| DHT22 Digital Temperature Sensors      | 15       |
| GY-906 MLX90614 IR Temperature Sensors | 15       |
| Relay Module (4-channel)               | 1        |
| SIM800C GSM/GPRS Module                | 1        |
| ACS712 Current Sensor                  | 1        |
| Voltage Sensor Module                  | 1        |
| 24V Solar Battery                      | 1        |
| Buck Converter (24V to 5V)             | 1        |
| Boost Converter (5V to 12V)            | 1        |
| GSM Antenna                            | 1        |


---

##  Power Supply Architecture

- **24V Solar Battery** is the main source.
- **Buck Converter (24V to 5V)**:
  - Powers: Arduino, DHT22, GY-906, GSM, sensors.
- **Boost Converter (5V to 12V)**:
  - Powers: Relay module.

> Note: Ensure all components share a **common GND**.

---

##  Arduino Pin Assignments
[Component Datasheet](https://docs.arduino.cc/resources/datasheets/A000067-datasheet.pdf)
<img width="1201" height="671" alt="image" src="https://github.com/user-attachments/assets/f468b458-7806-46f8-94d9-5dae5e636c56" />

| Arduino Pin | Connected Component              |
|-------------|----------------------------------|
| D14 (TX3)   | GSM Module RX                    |
| D15 (RX3)   | GSM Module TX                    |
| D20 (SDA)   | SDA for all GY-906 Sensors       |
| D21 (SCL)   | SCL for all GY-906 Sensors       |
| D4          | DHT22 Sensor 1                   |
| D5          | DHT22 Sensor 2                   |
| D6          | DHT22 Sensor 3                   |
| D7          | DHT22 Sensor 4                   |
| D8          | DHT22 Sensor 5                   |
| D9          | DHT22 Sensor 6                   |
| D10         | DHT22 Sensor 7                   |
| D11         | DHT22 Sensor 8                   |
| D12         | DHT22 Sensor 9                   |
| D13         | DHT22 Sensor 10                  |
| D33         | DHT22 Sensor 11                  |
| D31         | DHT22 Sensor 12                  |
| D29         | DHT22 Sensor 13                  |
| D27         | DHT22 Sensor 14                  |
| D25         | DHT22 Sensor 15                  |
| A0          | Relay Channel 1                  |
| A1          | Relay Channel 2                  |
| A2          | Relay Channel 3                  |
| A3          | Relay Channel 4                  |
| A15         | Current Sensor Output            |
| A14         | Voltage Sensor Output            |

---

##  DHT22 Sensors
[Component Datasheet](https://cdn.sparkfun.com/assets/f/7/d/9/c/DHT22.pdf)

<img width="393" height="524" alt="image" src="https://github.com/user-attachments/assets/98cf6d15-c5aa-4802-ae1b-2efea8792e45" />

Each DHT22 sensor has 3 pins:

- `VCC` → Arduino 5V
- `GND` → Arduino GND
- `Data` → Connected to:

| Sensor       | Signal Pin |
|--------------|------------|
| DHT22 #1     | D4         |
| DHT22 #2     | D5         |
| DHT22 #3     | D6         |
| DHT22 #4     | D7         |
| DHT22 #5     | D8         |
| DHT22 #6     | D9         |
| DHT22 #7     | D10        |
| DHT22 #8     | D11        |
| DHT22 #9     | D12        |
| DHT22 #10    | D13        |
| DHT22 #11    | D33        |
| DHT22 #12    | D31        |
| DHT22 #13    | D29        |
| DHT22 #14    | D27        |
| DHT22 #15    | D25        |

---

##  GY-906 MLX90614 Sensors
[Component Datasheet](https://www.espruino.com/MLX90614)

<img width="450" height="300" alt="image" src="https://github.com/user-attachments/assets/97bd70f5-0090-4fe0-8c79-6d33eb81b982" />

Each GY-906 sensor has 4 pins:

- `Vin` → Arduino 5V
- `GND` → Arduino GND
- `SCL` → D21
- `SDA` → D20

All 15 sensors share the same I2C bus (parallel connection).

---

##  Relay Module
[Similar Component Datasheet](https://www.handsontec.com/dataspecs/4Ch-relay.pdf)

<img width="680" height="680" alt="image" src="https://github.com/user-attachments/assets/85263b40-9a2a-4e78-83fd-5d9a1c7ecbb4" />

- `VCC` → 12V (from boost converter)
- `GND` → Arduino GND
- `IN1` → A0
- `IN2` → A1
- `IN3` → A3
- `IN4` → A4


---

##  GSM Module (SIM800C)
[Component Datasheet](https://www.elecrow.com/download/SIM800C_Hardware_Design_V1.02.pdf?srsltid=AfmBOoqcjs44B-wAQnXmSbQzKUEG9c5uxgpeJvIe-FnXu5Hr60QYr4p9)

<img width="450" height="450" alt="image" src="https://github.com/user-attachments/assets/91250fb6-e1ef-42a0-bc7a-1dc6e4c66233" />

- `VCC` → 5V (from buck converter)
- `GND` → Arduino GND
- `TX` → D14 (Arduino RX3)
- `RX` → D15 (Arduino TX3)
- `Antenna` → External antenna connected to module

---

## Current Sensor (ACS712)
[Component Datasheet](https://www.elecrow.com/download/ACS712-Datasheet.pdf)

<img width="450" height="337" alt="image" src="https://github.com/user-attachments/assets/5bfe31c0-8ef5-468c-834b-3321a219f8a0" />

- `VCC` → 5V
- `GND` → Arduino GND
- `OUT` → A15

---

##  Voltage Sensor
[Component Datasheet](https://www.makershop.de/download/voltage-sensor.pdf)

<img width="450" height="450" alt="image" src="https://github.com/user-attachments/assets/e3a699bd-15de-4f9a-8efd-acfa3c117a6b" />

- `VCC` → 5V
- `GND` → Arduino GND
- `OUT` → A14

---

