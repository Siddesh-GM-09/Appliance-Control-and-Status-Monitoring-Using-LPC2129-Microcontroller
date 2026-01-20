# Appliance Control and Status Monitoring Using LPC2129

## Overview
Control AC, Bulb, Fan, and TV using UART commands. Status is displayed on LCD and also printed on UART.

## Features
- UART command control (A/a, B/b, F/f, T/t)
- LCD status display
- UART status monitoring
- UART interrupt based input

## Hardware
- LPC21xx (ARM7)
- 16x2 LCD
- UART0 (USB to Serial)
- Output loads via GPIO (LED/Relay Driver)

## Commands
A: AC ON, a: AC OFF  
B: BULB ON, b: BULB OFF  
F: FAN ON, f: FAN OFF  
T: TV ON, t: TV OFF

## How to Build/Run
- Use Keil uVision (or your toolchain)
- Flash to LPC2129
- Open serial terminal at 9600 baud
