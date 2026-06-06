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

```text
1. Edit Password
2. Edit Fingerprint
```

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

![Hardware Setup](images/hardware_setup.jpg)

---

### 📟 3. Power ON Screen

Displays the project welcome message after power-up.

![Power ON Screen](images/power_on.jpg)

---

### 📟 4. User ID Entry Screen

System waiting for User ID.

![User ID Entry](images/user_id_entry.jpg)

---

### 🔑 5. Password Entry Screen

Password authentication screen.

![Password Screen](images/password_entry.jpg)

---

### ⚙️ 6. Interrupt Configuration Menu

Displayed when External Interrupt is pressed.

![Interrupt Menu](images/interrupt_menu.jpg)

---

### 👆 7. Fingerprint Enrollment

Fingerprint registration process.

![Fingerprint Enrollment](images/fingerprint_enroll.jpg)

---

### 🔍 8. Fingerprint Verification

Fingerprint matching process.

![Fingerprint Verification](images/fingerprint_verify.jpg)

---

### 🚪 9. Access Granted

Successful authentication.

![Access Granted](images/access_granted.jpg)

---

### 🚫 10. Access Denied

Authentication failure.

![Access Denied](images/access_denied.jpg)

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
