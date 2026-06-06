# Secure Access Control System with Multi-Level Authentication

## 📌 Project Title
Secure Access Control System with Multi-Level Authentication

---

## 📖 Description

The Secure Access Control System is an embedded security project designed to provide highly secure access using a three-level authentication mechanism. The system verifies a user through:

1. User ID Verification
2. Password Verification
3. Fingerprint Verification

Access is granted only when all three authentication levels are successfully verified. This approach provides better security, reliability, and accuracy than traditional single-level authentication systems.

---

## 🎯 Aim

To design and develop a secure access control system that prevents unauthorized access by implementing multi-level authentication using User ID, Password, and Fingerprint verification.

---

## 🔧 Hardware Requirements

- LPC2148 Microcontroller
- R305 Fingerprint Module
- LCD Display
- AT25C256 EEPROM
- 4x4 Keypad
- Push Button Switch
- L293D Motor Driver IC
- DC Motor
- USB-to-UART Converter

---

## 💻 Software Requirements

- Embedded C
- Keil µVision IDE
- Flash Magic
- Fingerprint Module Utility Software

---

## 🏗 System Architecture

### Authentication Levels

#### Level 1: User ID Verification
The user enters a valid User ID through the keypad.

#### Level 2: Password Verification
The user enters a password through the keypad. The entered password is compared with the password stored in EEPROM.

#### Level 3: Fingerprint Verification
The fingerprint is scanned using the R305 fingerprint sensor and compared with the stored fingerprint template.

Only when all three levels are successfully verified is access granted.

---

## 🔄 Working Principle

### Step 1: User ID Entry
The system waits for the user to enter a valid User ID using the keypad.

### Step 2: Password Verification
- User enters password.
- Password is stored in an array.
- Stored password is read from EEPROM.
- Both passwords are compared.

If matched, the system proceeds to fingerprint verification.

### Step 3: Fingerprint Verification
- Finger image is captured.
- Character file is generated.
- Fingerprint library is searched.
- Matching template is verified.

If the fingerprint matches, access is granted.

---

## 🔐 Password Modification

Using External Interrupt 0, the user can select:

1. Edit Password
2. Edit Fingerprint

### Edit Password Process

1. Enter current password.
2. Verify current password.
3. Enter new password.
4. Confirm new password.
5. If both passwords match:
   - Save new password into EEPROM.
6. Otherwise:
   - Old password remains unchanged.

---

## 👆 Fingerprint Management

### Enroll Fingerprint

1. Detect finger.
2. Capture fingerprint image.
3. Generate character file.
4. Store template in fingerprint memory.

### Delete Fingerprint

Delete a specified fingerprint ID from the fingerprint module memory.

### Search Fingerprint

1. Capture fingerprint image.
2. Generate character file.
3. Search fingerprint library.
4. Verify matching fingerprint ID.

---

## 🚪 Door Control System

A DC motor is used to simulate door movement.

### Access Granted
- Motor rotates forward.
- Door opens automatically.

### Access Denied
- Motor rotates in reverse direction.
- Door remains closed or locked.

---
---

## 🖼️ Project Images

### 1. System Architecture / Block Diagram

Add the complete system architecture showing:

- LPC2148 Microcontroller
- R305 Fingerprint Module
- LCD Display
- 4x4 Keypad
- EEPROM (AT25C256)
- L293D Motor Driver
- DC Motor
- External Interrupt Switch

<img width="168" height="299" alt="image" src="https://github.com/user-attachments/assets/a343a0c2-4fb3-49dd-a860-46ef1b1d7347" />


---

### 2. Power ON Display

Display shown immediately after powering the system.

![Power ON Screen](images/power_on_screen.jpg)

**Example LCD Output**

```text
SECURE ACCESS
CONTROL SYSTEM
```

---

### 3. User ID Entry Screen

System waiting for User ID.

![User ID Screen](images/user_id_entry.jpg)

**Example LCD Output**

```text
ENTER USER ID
_
```

---

### 4. Password Entry Screen

Password authentication screen.

![Password Entry](images/password_entry.jpg)

**Example LCD Output**

```text
ENTER PASSWORD
****
```

---

### 5. External Interrupt Menu

Displayed when External Interrupt (INT0) is pressed.

![Interrupt Menu](images/interrupt_menu.jpg)

**Example LCD Output**

```text
1. EDIT PASS
2. EDIT FP
```

---

### 6. Password Update Screen

Password modification process.

![Password Update](images/password_update.jpg)

**Example LCD Output**

```text
NEW PASSWORD
****
```

---

### 7. Fingerprint Enrollment Screen

Fingerprint registration process.

![Fingerprint Enroll](images/fingerprint_enroll.jpg)

**Example LCD Output**

```text
PLACE FINGER
FOR ENROLL
```

---

### 8. Fingerprint Verification Screen

Fingerprint authentication process.

![Fingerprint Verification](images/fingerprint_verify.jpg)

**Example LCD Output**

```text
PLACE FINGER
FOR VERIFY
```

---

### 9. Access Granted / Door Open

Displayed when all authentication levels are successful.

![Door Open](images/access_granted.jpg)

**Example LCD Output**

```text
ACCESS GRANTED
DOOR OPENED
```

Motor rotates forward.

---

### 10. Access Denied / Door Closed

Displayed when authentication fails.

![Door Closed](images/access_denied.jpg)

**Example LCD Output**

```text
ACCESS DENIED
DOOR CLOSED
```

Motor rotates reverse.

---

### 11. Fingerprint Match Screen

Successful fingerprint verification.

![Fingerprint Match](images/fingerprint_match.jpg)

**Example LCD Output**

```text
FINGERPRINT
MATCHED
```

---

### 12. Fingerprint Not Matched Screen

Fingerprint verification failure.

![Fingerprint Not Matched](images/fingerprint_not_matched.jpg)

**Example LCD Output**

```text
FINGERPRINT
NOT MATCHED
```

---

### 13. Complete Hardware Setup

Final hardware implementation.

![Hardware Setup](images/hardware_setup.jpg)

Components:
- LPC2148 Development Board
- R305 Fingerprint Module
- LCD Display
- Keypad
- EEPROM
- L293D Driver
- DC Motor
- Power Supply

---

---

## 🧪 Module Testing Procedure

### LCD Testing
- Display character constants.
- Display strings.
- Display integer values.

### Keypad Testing
- Read key values.
- Display pressed keys on LCD.

### EEPROM Testing
- Write data into EEPROM.
- Read data from EEPROM.
- Display data on LCD.

### UART Testing
- Transmit characters.
- Transmit strings.
- Receive strings using UART Interrupts.

### Fingerprint Module Testing
- Connect R305 to USB-UART converter.
- Verify module functionality.
- Test enrollment and search operations.

---

## 📋 Fingerprint Enrollment Process

### Enrollment Steps

1. Capture fingerprint image.
2. Store image in ImageBuffer.
3. Generate character file.
4. Store in CharBuffer1 or CharBuffer2.
5. Store template in flash library.

---

## 🔍 Fingerprint Search Process

### Search Steps

1. Capture fingerprint image.
2. Generate character file.
3. Search entire fingerprint database.
4. Verify matching fingerprint ID.

---

## 📟 Expected Output

### Successful Authentication

```text
Enter User ID:
1234

Enter Password:
****

Fingerprint Matched

ACCESS GRANTED
DOOR OPENED
```

### Failed Authentication

```text
Enter User ID:
1234

Enter Password:
****

Fingerprint Not Matched

ACCESS DENIED
DOOR LOCKED
```

---

## 🌟 Features

- Three-Level Authentication
- User ID Verification
- Password Authentication
- Fingerprint Authentication
- EEPROM-Based Password Storage
- LCD User Interface
- Fingerprint Enrollment and Deletion
- Secure Access Control
- DC Motor-Based Door Control
- Embedded C Implementation

---

## 🚀 Applications

- Smart Door Lock Systems
- Office Security Systems
- Restricted Area Access Control
- Laboratory Security
- Industrial Security Systems
- Attendance Monitoring Systems
- Biometric Authentication Systems

---

## 🔮 Future Enhancements

- RFID Authentication
- GSM Alert Notifications
- Wi-Fi Connectivity
- IoT-Based Monitoring
- Mobile Application Integration
- Face Recognition System
- Cloud Database Support

---

## 📚 Technologies Used

- Embedded C
- LPC2148 ARM7 Microcontroller
- UART Communication
- EEPROM Memory Interface
- Fingerprint Recognition Technology
- LCD Interfacing
- Keypad Interfacing
- DC Motor Control

---

## 👨‍💻 Author

**Rajasekhar Pandaraboina**  
B.Tech – Electronics and Communication Engineering (ECE)  
Chalapathi Institute of Engineering and Technology

---

## ✅ Conclusion

The Secure Access Control System with Multi-Level Authentication provides enhanced security by combining User ID, Password, and Fingerprint verification. The system ensures that only authorized users can gain access, making it suitable for secure environments where high reliability and security are required.
