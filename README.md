# ⏰ Digital Clock on STM32F103RCT6 with LCD16x2
# Small project for my Microcontroller subject since 2022

## 📖 Introduction
This project implements a simple **digital clock** on the STM32F103RCT6 microcontroller.  
The time (hours, minutes, seconds) is displayed on an **LCD16x2** screen.  
Use external interrupt , configure on button
The project demonstrates how to use **HAL libraries** in STM32CubeIDE to interface with peripherals and build an embedded system application.
The Code.cpp is the main code for the program in .ioc file , sorry for the inconvinience


✨ Key features:
- Real-time clock display (HH:MM:SS).
- LCD16x2 interface using GPIO (or I2C if module is available).
- Modular and well-structured C code for easy extension.
- Potential to upgrade with **alarm** or **sensor integration**.

---

## 🛠️ Hardware
- **MCU**: STM32F103RCT6 (ARM Cortex-M3).  
- **Display**: LCD16x2.  
- **Optional**: 32.768kHz RTC crystal.  
- **Power**: 5V/3.3V supply.  
- **Others**: Breadboard, jumper wires.  

📌 Hardware setup diagram:  
GPIO PIN Configuration
<img src="https://github.com/xanhvuong/images/blob/master/GPIO_PIN.png" alt="Prototype" width="854" height="480"/>
<img src="https://github.com/xanhvuong/images/blob/master/GPIO_PIN1.png" alt="Prototype" width="854" height="480"/>

Timer (TIM1) configuration.
<img src="https://github.com/xanhvuong/images/blob/master/TIM1.png" alt="Prototype" width="480" height="854"/>

Timer (TIM1) interrupt configuration.
<img src="https://github.com/xanhvuong/images/blob/master/TIM1_interrupt.png" alt="Prototype" width="480" height="854"/>


---

## 💻 Software
- **IDE**: STM32CubeIDE.  
- **Language**: C (HAL-based).  
- **Libraries**: STM32 HAL drivers.  

---

## 🎥 Result
- The circuit ran successfully.
- The LCD correctly displayed the full time including hours, minutes, and seconds; the time increased continuously and reset back to 00:00:00 after 24 hours.
- When Button 1 was pressed, the hour display increased by 30 minutes.
- When Button 2 was pressed, the minute display increased by 30 seconds.
- The LED turned ON during the time range from 18:00 to 06:00, and turned OFF during the range from 06:00 to 18:00.
