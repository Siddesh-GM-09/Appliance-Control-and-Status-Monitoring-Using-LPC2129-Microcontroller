# ⚡ Appliance Control and Status Monitoring – LPC2129 (ARM7)

![Platform](https://img.shields.io/badge/Platform-ARM7%20LPC2129-blue)
![Language](https://img.shields.io/badge/Language-Embedded%20C-green)
![Interface](https://img.shields.io/badge/Interface-UART0-yellow)
![Display](https://img.shields.io/badge/Display-16x2%20LCD-orange)
![Status](https://img.shields.io/badge/Project-Completed-success)

---

## 📌 Project Overview
An **appliance control and monitoring system** using **NXP LPC2129 (ARM7)**.  
The system controls **AC, Bulb, Fan, and TV** using **UART serial commands**.  
Current ON/OFF status is displayed on a **16×2 LCD** and also printed to the **UART terminal** for real-time monitoring and debugging.

---

## 🚀 Features
- UART-based appliance control using single-character commands  
- **UART0 interrupt-based** command reception  
- GPIO output control (LED / Relay driver)  
- **16×2 LCD** real-time status display  
- UART terminal output for monitoring  

---

## 🧰 Hardware Used
- NXP **LPC2129 (ARM7 Microcontroller)**
- **16×2 LCD** (HD44780 compatible)
- UART0 via **USB-to-Serial cable** / **HC-05 Bluetooth module (optional)**
- LEDs / Relay Driver Module (Appliance simulation)
- Regulated power supply

---

## 🧩 Software & Tools
- Embedded C
- Keil µVision IDE
- UART Serial Terminal (Tera Term / PuTTY)
- Proteus (optional for simulation)

---

## 🔌 UART Command Menu

| Command | Action |
|------:|--------|
| `A` | AC ON |
| `a` | AC OFF |
| `B` | Bulb ON |
| `b` | Bulb OFF |
| `F` | Fan ON |
| `f` | Fan OFF |
| `T` | TV ON |
| `t` | TV OFF |

---

## ⚙️ Working Principle
1. A command character is sent from the UART terminal or Bluetooth module.
2. **UART0 Interrupt Service Routine (ISR)** receives the command.
3. LPC2129 decodes the command and controls the corresponding GPIO pin.
4. Appliance status is updated on:
   - **16×2 LCD**
   - **UART terminal**
5. The system waits for the next command.

---

## 🧪 Example UART Output
```txt
=== Appliance Control Menu ===
A/a : AC ON/OFF
B/b : BULB ON/OFF
F/f : FAN ON/OFF
T/t : TV ON/OFF

Command: A
AC -> ON
```

---

## 🛠️ Build & Run (Keil µVision)
1. Open the project in **Keil µVision**.
2. Select target device **LPC2129**.
3. Build the project and generate HEX file.
4. Flash the HEX to the board.
5. Open UART terminal:
   - Baud Rate: **9600**
   - Data Bits: **8**
   - Parity: **None**
   - Stop Bits: **1**
6. Send commands and observe LCD + UART output.

---

## 📂 Project Structure
```
APPLIANCE_CONTROL_LPC2129/
├── main.c
├── header.h
├── uart0_driver.c
├── lcd4bit_driver.c
├── delay.c
├── Startup.s
├── project.uvproj
├── README.md
```

---

## 🎯 Key Learning Outcomes
- UART interrupt programming
- Command-based embedded control
- GPIO interfacing with ARM7
- LCD interfacing
- Real-time embedded system design
- Debugging using UART terminal

---

## 👤 Author
**Siddesh G M**  
Embedded Systems Fresher  
ARM7 | Embedded C | UART | GPIO
