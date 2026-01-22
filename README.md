# Appliance Control and Status Monitoring Using LPC2129 (ARM7)

Control **AC, Bulb, Fan, and TV** using **UART serial commands** on the **NXP LPC2129 (ARM7)**.  
The current ON/OFF status is shown on a **16×2 LCD** and also printed to the **UART terminal**.

---

## 🚀 Overview
This embedded mini project implements a simple command-based appliance control system.  
UART0 receives commands using **interrupt-based input**, and GPIO pins switch outputs (LED/relay driver).  
LCD + UART terminal provide real-time status monitoring.

---

## ✨ Features
- UART command control: **A/a, B/b, F/f, T/t**
- **UART0 interrupt-based** command reception
- GPIO output switching (LED / Relay Driver)
- **16×2 LCD** real-time status display
- UART terminal status print (debug + monitoring)

---

## 🧰 Hardware Used
- **NXP LPC2129 (ARM7)**
- **16×2 LCD (HD44780 compatible)**
- **UART0** via **USB-to-Serial (UART cable)** / **HC-05 (optional)**
- Output loads via **GPIO** (LEDs / Relay Driver Module)
- Power supply as required

---

## 🔌 Command Menu
| Command | Action |
|--------:|--------|
| `A` | AC ON |
| `a` | AC OFF |
| `B` | Bulb ON |
| `b` | Bulb OFF |
| `F` | Fan ON |
| `f` | Fan OFF |
| `T` | TV ON |
| `t` | TV OFF |

---

## ⚙️ How It Works (Flow)
1. UART terminal / Bluetooth sends a single character command  
2. **UART0 ISR** reads the character  
3. GPIO output is updated (ON/OFF)  
4. LCD updates device status  
5. UART prints updated status

---

## 🛠️ Build & Run
### Using Keil uVision
1. Open the project in **Keil uVision**
2. Build the project (Target: **LPC2129**)
3. Flash the HEX to the board
4. Open a serial terminal:
   - **Baud Rate:** 9600  
   - **Data Bits:** 8  
   - **Parity:** None  
   - **Stop Bits:** 1  
   - **Flow Control:** None
5. Send commands (`A/a/B/b/F/f/T/t`) and observe LCD + UART output

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
