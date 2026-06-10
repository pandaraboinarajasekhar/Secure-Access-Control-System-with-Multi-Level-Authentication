# 🔐 SECURE ACCESS CONTROL SYSTEM WITH MULTI-LEVEL AUTHENTICATION

## 📖 Project Overview

The **Secure Access Control System with Multi-Level Authentication** is an embedded security project designed to provide enhanced access control using multiple layers of authentication. The system verifies users through **User ID**, **Password**, and **Fingerprint Authentication** before granting access.

The project utilizes an **LPC2148 microcontroller**, **R305 fingerprint sensor**, **EEPROM**, **LCD**, and **keypad** to implement a reliable and secure access mechanism. A **DC motor** is used to simulate the door locking and unlocking process.

This system improves security by ensuring that access is granted only after successful completion of all authentication levels.

---

## 🎯 Aim of the Project

The main aim of this project is to develop a secure access control system that prevents unauthorized entry through multi-level user authentication.

The system validates:

* User ID
* Password
* Fingerprint

Only after successful verification of all three levels is access granted.

---

## ✨ Features

* Multi-Level Authentication
* User ID Verification
* Password Verification
* Fingerprint Authentication
* EEPROM-Based Password Storage
* Password Modification Function
* Fingerprint Enrollment
* Fingerprint Deletion
* LCD-Based User Interface
* Keypad-Based User Input
* Interrupt-Based Configuration Menu
* DC Motor Controlled Door Access
* Real-Time Authentication Status Display

---

## 🔧 Hardware Requirements

The following components are used in this project:

* LPC2148 Microcontroller
* R305 Fingerprint Sensor
* LCD Display
* AT25C256 EEPROM
* 4x4 Matrix Keypad
* Push Button Switch
* L293D Motor Driver
* DC Motor
* USB-to-UART Converter

---

## 💻 Software Requirements

* Embedded C Programming
* Keil µVision IDE
* Flash Magic

---

## 🏗️ System Architecture

### System Block Diagram

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/401b76d0-0e4b-4236-beaf-935c62c5af70" />


The system consists of:

* LPC2148 Controller
* Fingerprint Sensor
* EEPROM
* LCD Display
* Keypad
* Motor Driver
* DC Motor

All authentication and control operations are managed by the LPC2148 microcontroller.

---

## ⚙️ Working Principle

The system operates using a three-level authentication process.

### Step 1: User ID Verification

After power-up, the system waits for a valid User ID entry through the keypad.

If a valid User ID is entered, the system proceeds to password verification.

---

### Step 2: Password Verification

The user enters a password using the keypad.

The system:

* Reads the stored password from EEPROM.
* Compares it with the entered password.
* Proceeds to fingerprint verification if matched.

If the password is incorrect, access is denied.

---

### Step 3: Fingerprint Verification

The R305 fingerprint sensor performs:

* Finger detection
* Image capture
* Character file generation
* Template matching

The fingerprint is compared with stored templates in the fingerprint database.

If matched, access is granted.

---

### Step 4: Door Control

After successful authentication:

* DC Motor rotates forward.
* Door opens.
* LCD displays "ACCESS GRANTED".

If authentication fails:

* DC Motor remains locked or rotates reverse.
* LCD displays "ACCESS DENIED".

---

## 🔐 Interrupt-Based User Configuration

When the external interrupt button is pressed, the system enters configuration mode.

### Menu Options

1. Edit Password
2. Edit Fingerprint

The user can navigate using the keypad.

---

### Password Modification

The user can:

* Enter current password
* Enter new password
* Confirm new password

If both passwords match:

* New password is stored in EEPROM.

Otherwise:

* Previous password remains unchanged.

---

### Fingerprint Management

The user can:

#### Enroll Fingerprint

* Capture fingerprint image
* Generate template
* Store template in sensor memory

#### Delete Fingerprint

* Remove stored fingerprint IDs

---

## 🖼️ Project Images

### 📊 1. System Block Diagram

<img width="1537" height="1023" alt="image" src="https://github.com/user-attachments/assets/910a83a6-ceb5-42ab-943b-9b12675abf1d" />



---

### 🔌 2. Hardware Setup

<img width="1546" height="856" alt="WhatsApp Image 2026-06-07 at 12 08 13 AM" src="https://github.com/user-attachments/assets/e7165eb7-ac67-45d8-bfb7-2d33337b754b" />



---

### 📟 3. Power ON Screen

Displays the project welcome message after power-up.

<img width="1787" height="880" alt="image" src="https://github.com/user-attachments/assets/41d1dc44-f0f0-4a1f-853c-211d6b705047" />



This screen is displayed immediately after the system is powered ON. It indicates that the LPC2148 microcontroller has successfully initialized all peripherals and that the Secure Access Control System is ready for authentication.


---

### 📟 4. User ID Entry Screen

System waiting for User ID.

<img width="1798" height="875" alt="image" src="https://github.com/user-attachments/assets/db90cfcd-2d31-4862-ad2e-7022eb59e335" />


The system prompts the user to enter a valid User ID through the keypad as the first level of authentication. The entered ID is verified before proceeding to the password authentication stage. This step helps ensure that only registered users can access the system.


---

### 🔑 5. Password Entry Screen

Password authentication screen.

<img width="1893" height="831" alt="image" src="https://github.com/user-attachments/assets/d4826c2c-4cd3-4b7f-a641-71c773e89d97" />

The password authentication screen is displayed after successful User ID verification. The user enters the password using the keypad, and the entered password is compared with the password stored in EEPROM. Access proceeds to fingerprint verification only when the password is validated successfully.


---

### ⚙️ 6. Interrupt Configuration Menu

Displayed when External Interrupt is pressed.

<img width="1909" height="824" alt="image" src="https://github.com/user-attachments/assets/f52dad03-b9a9-4a30-ae2c-44bef8d288ea" />
This screen is displayed when the External Interrupt (INT0) button is pressed. The configuration menu allows the user to manage authentication settings without reprogramming the system.

Available options:

1. EDIT_PASS_FING → Modify the stored password or update fingerprint data.
2. RESET → Reset authentication settings or stored data.
3. EXIT → Return to the main authentication screen.

The menu is navigated using the keypad, providing a simple and user-friendly interface for system configuration



---

### 👆 7. Fingerprint Enrollment

Fingerprint registration process.

<img width="1640" height="959" alt="image" src="https://github.com/user-attachments/assets/7759199e-f4e5-4a28-a00f-8242c89e81eb" />


This screen is displayed during the fingerprint registration process. The user places a finger on the R305 fingerprint sensor, and the system captures the fingerprint image, generates a template, and stores it in the fingerprint database for future authentication.

The LCD provides guidance throughout the enrollment process and confirms successful fingerprint registration.

---

### 🔍 8. Fingerprint Verification

Fingerprint matching process.

<img width="1515" height="1038" alt="image" src="https://github.com/user-attachments/assets/f2bba0ff-233b-4448-bc15-f6552b1a022b" />

This screen is displayed during the fingerprint authentication process. After successful User ID and Password verification, the user places a registered finger on the R305 fingerprint sensor. The system captures the fingerprint image, generates a template, and compares it with the stored fingerprint database.

If a matching fingerprint is found, access is granted; otherwise, access is denied.


---

### 🚪 9. Access Granted

Successful authentication.

<img width="1913" height="822" alt="image" src="https://github.com/user-attachments/assets/b6c74b4f-88fc-4206-9685-5b4b9e76e07d" />

This screen is displayed after successful completion of all three authentication levels: User ID verification, Password verification, and Fingerprint verification.

When a valid user is authenticated, the system grants access and activates the door control mechanism through the motor driver. The LCD confirms successful authentication and indicates that the door has been opened.

---

### 🚫 10. Access Denied

Authentication failure.

<img width="1914" height="822" alt="image" src="https://github.com/user-attachments/assets/b74dcf11-98ff-4fea-9a33-25cc994e9700" />

This screen is displayed when any authentication step fails, including User ID verification, Password verification, or Fingerprint verification. The system denies access to unauthorized users and keeps the door in the locked state.

The LCD notifies the user that authentication has failed and prevents further access until valid credentials are provided.

---

## 🚀 How to Run the Project

### 1. Create Project Folder

Create a project folder and add all source files.

---

### 2. Verify LCD Module

Check:

* Character display
* String display
* Integer display

---

### 3. Verify Keypad Module

Display pressed keys on LCD.

---

### 4. Verify EEPROM

Test:

* EEPROM Write
* EEPROM Read

Display data on LCD.

---

### 5. Verify UART Communication

Test UART transmission and reception using interrupts.

---

### 6. Verify Fingerprint Module

Connect R305 through USB-to-UART converter.

Test:

* Fingerprint Enrollment
* Fingerprint Search
* Fingerprint Delete

---

### 7. Integrate All Modules

Initialize:

* LCD
* Keypad
* EEPROM
* UART
* Fingerprint Sensor
* DC Motor

---

### 8. Build and Flash

Compile using **Keil µVision**.

Generate HEX file and flash using **Flash Magic**.

---

## 🌍 Applications

* Smart Door Lock Systems
* Office Security Systems
* Laboratory Access Control
* Restricted Area Security
* Attendance Systems
* Industrial Access Management

---

## 🔮 Future Improvements

* RFID Authentication
* GSM Alerts
* IoT-Based Remote Monitoring
* Mobile App Integration
* Face Recognition
* Cloud-Based Access Logs

---

## 👨‍💻 Author

**Rajasekhar Pandaraboina**

---
