# Download Proteus 8 Professional
Visit the official Proteus page:
https://www.labcenter.com/downloads/
Choose Proteus 8 Professional and click Download.
After downloading, run the setup file.

# Install Proteus 8 Professional
Double-click the installer to begin setup.
Choose the installation directory or proceed with the default.
If you have a license key, enter it when prompted.
Complete installation by following the on-screen instructions.

# Open and Modify Project Files
Launch Proteus 8 Professional.
To open a project:
Go to File → Open Project.
Browse to the directory containing .PDSPRJ (project) files.
Edit connections: Use the wire tool to change component connections.
Add components: From the sidebar → Pick Devices → Search and drag into the workspace.

# Upload firmware  .hex or files):
Double-click on a microcontroller 
In the properties window, browse and select the compiled .hex file.
Run simulation: Click the play ▶️ button in the toolbar.

---
---
---

# Simulation Results and Design Choices
The Results of the simulation helped confim the compatibility of the selected sensors with the chosen microcontroller. Together with comparison with alternative components, the following design choices were made:

## 1. Arduino Mega 2560 (Microcontroller)
**Why chosen:**
- Offers more memory and I/O pins than Arduino Uno, essential for interfacing with multiple sensors, GSM module, and control circuits simultaneously.  
- Reliable, widely supported, and easy to program for rapid prototyping.  

**Rating relevance:**
- Operates at **5V logic** with **16 MHz clock speed**, adequate for real-time data handling.  
- Provides **54 digital I/O pins** and **16 analog inputs**, ensuring scalability.  

**Reason for project:**  
Acts as the **brain of the system**, processing sensor data, managing control logic, and handling GSM/IoT communications.  

---

## 2. DHT22 Humidity & Temperature Sensor
**Why chosen:**
- Provides **higher accuracy** (±2% RH, ±0.5°C) compared to DHT11.  
- Digital output reduces noise issues in long wire setups, suitable for off-grid installations.  

**Rating relevance:**
- Supply voltage: **3.3–6V** → compatible with Arduino Mega.  
- Measurement range: **0–100% RH** and **-40°C to +80°C**, covering wide environmental conditions typical in rural communities.  

**Reason for project:**  
Ensures **accurate monitoring of humidity and ambient temperature**, vital for food preservation and cooling system optimization.  

---

## 3. GY-906 MLX90614 Infrared Non-contact Temperature Sensor
**Why chosen:**
- Measures **surface/object temperature without contact**, ideal for monitoring stored goods inside the cooling hub.  
- High accuracy and built-in **I2C interface** simplify integration.  

**Rating relevance:**
- Operating voltage: **3.6–5V** → directly compatible with Arduino Mega.  
- Temperature range: **-70°C to +380°C**, wide enough for food and medicine storage applications.  

**Reason for project:**  
Enables **non-invasive monitoring of perishable goods’ surface temperature**, reducing contamination risk.  

---

## 4. ZMPT101B Voltage Sensor
**Why chosen:**
- Small and precise sensor for **measuring AC voltage levels** from solar inverter or AC-powered backup sources.  
- Provides **galvanic isolation** between high voltage AC and low voltage Arduino circuits, ensuring safety.  

**Rating relevance:**
- Input range: up to **250V AC**.  
- Output: low voltage analog signal (**0–5V**) suitable for Arduino ADC.  

**Reason for project:**  
Protects system by **monitoring input voltage stability**, ensuring safe operation of cooling hub electronics.  

---

## 5. ACS712T Current Sensor (30A Range)
**Why chosen:**
- Measures **current flow in solar/battery circuits** to monitor energy usage of cooling system.  
- Hall-effect based → provides isolation and safety.  

**Rating relevance:**
- Available in **5A, 20A, and 30A ranges** → **30A selected** to accommodate higher current draw from compressors, fans, or pumps in cooling hub.  
- Output sensitivity: **66mV/A**, easily readable by Arduino ADC.  

**Reason for project:**  
Enables **real-time monitoring of power consumption**, essential for optimizing solar energy usage and preventing overcurrent damage.  

---

## 6. SIM800 GSM/GPRS Module
**Why chosen:**
- Provides **GPRS data connectivity** for IoT applications where Wi-Fi is unavailable (typical in off-grid rural areas).  
- Supports SMS and call alerts, ensuring redundancy.  

**Rating relevance:**
- Operates at **3.7–4.2V** (battery friendly).  
- Low power consumption in idle mode → fits into solar-powered design.  

**Reason for project:**  
Enables **remote monitoring and control** via web dashboard or SMS, ensuring accessibility for end-users and operators.  

---

## Why These Components Together?
- **Integration:** All chosen components communicate via **I2C, UART, or analog input**, making Arduino Mega an ideal controller.  
- **Low power consumption:** Each component is optimized for **solar-based, off-grid operation**.  
- **Scalability:** Allows adding more sensors (e.g., door status, motion detection) without hardware redesign.  
- **Affordability & availability:** Components are **cost-effective and widely available**, ensuring project replicability.  

---
