# ⏰ Digital Clock on STM32F103RCT6 with LCD16x2
# Small project for my Microcontroller subject since 2022

## 📖 Introduction
This project implements a simple **digital clock** on the STM32F103RCT6 microcontroller.  
The time (hours, minutes, seconds) is displayed on an **LCD16x2** screen.  
The project demonstrates how to use **HAL libraries** in STM32CubeIDE to interface with peripherals and build an embedded system application.

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
![Hardware Diagram](https://github.com/xanhvuong/images/blob/master/GPIO_PIN.png)  


---

## 💻 Software
- **IDE**: STM32CubeIDE.  
- **Language**: C (HAL-based).  
- **Libraries**: STM32 HAL drivers.  
- **Version Control**: Git.  

---

## 🎥 Demonstration
📷 LCD output example:  
![LCD Output](images/lcd_output.png)  

📹 Demo video:  
[![Watch the video](images/demo_thumbnail.png)](https://youtu.be/your-demo-link)  

---

## 🚀 How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/xanhvuong/Clock-on-STM32F103RCT6.git
