# 💬 Experiment 2: Creating a TCP Chat Server

![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-yellow?style=for-the-badge)
![Time](https://img.shields.io/badge/Time_Required-15_Minutes-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Tested-success?style=for-the-badge)

## 🤔 What are we doing?
In Experiment 1, we just connected to Wi-Fi. Now, we are going to make the ESP32 **listen** for messages.

We will turn the ESP32 into a **Server**. This means it will sit and wait for you to send it a message from your computer. When you send it "Hello", it will reply back "Echo: Hello". It's like building a simple chat bot!

---

## 🎒 What You Need (Checklist)
1.  **ESP32 Board** (Connected via USB).
2.  **Arduino IDE** (Installed on your computer).
3.  **Wi-Fi Credentials** (SSID and Password).
4.  **A Testing Tool:** We will use **Telnet** (built into Windows) or **Netcat**.

---

## 🛠️ Step-by-Step Guide

### Step 1: Prepare the Code
1.  Open the file `Experiment_2_TCP_Server.ino` in Arduino IDE.
2.  Just like before, find lines **4** and **5**:
    ```cpp
    const char* ssid = "Your_WiFi_Name";
    const char* password = "Your_WiFi_Password";
    ```
3.  **Action:** Replace `Your_WiFi_Name` and `Your_WiFi_Password` with your actual Wi-Fi details.

### Step 2: Upload the Code
1.  Plug in your ESP32.
2.  Select your **Board** and **Port** in `Tools`.
3.  Click the **Arrow Icon (➡️)** to upload.
    * *Reminder:* If it gets stuck at `Connecting...`, hold the **BOOT** button for 3 seconds!

### Step 3: Get the IP Address
1.  Open the **Serial Monitor** (Magnifying Glass 🔍).
2.  Set baud rate to **`115200`**.
3.  Press the **EN** (Reset) button on the ESP32.
4.  Wait for it to connect.
5.  **Look for this message:**
    > `TCP Server started on Port 3333`
    > `ESP32 IP: 192.168.1.105` (Your number will be different)
6.  📝 **Write down that IP Address!**

---

## 🧪 Step 4: How to Test (The Fun Part)
Now we will use your computer to talk to the ESP32.

### 🖥️ Option A: Using Telnet (Windows Users)
Windows has a hidden tool called "Telnet" that is perfect for this.

**1. Enable Telnet (Do this once):**
* Press `Windows Key + R`, type `cmd`, and press Enter.
* Copy and paste this command and hit Enter:
    ```cmd
    dism /online /Enable-Feature /FeatureName:TelnetClient
    ```
    *(Wait for it to finish. You might need to restart your terminal).*

**2. Connect to ESP32:**
* In your command prompt, type:
    ```cmd
    telnet <YOUR_ESP32_IP> 3333
    ```
    *(Example: `telnet 192.168.1.105 3333`)*
* **Hit Enter.**
* The screen might go blank. This is good! It means you are connected.

**3. Send a Message:**
* Type `Hello ESP32` and hit **Enter**.
* **Result:** The ESP32 should reply: `Echo: Hello ESP32`.

### 🍎 Option B: Using Netcat (Mac/Linux Users)
1.  Open your **Terminal**.
2.  Type:
    ```bash
    nc <YOUR_ESP32_IP> 3333
    ```
3.  Type a message and hit Enter. You should see the echo reply immediately.

---

## 🕵️ Step 5: Verify on Serial Monitor
While you are sending messages from your computer, look at the **Arduino Serial Monitor**. You should see logs like this:

```text
New Client Connected!
Received: Hello ESP32
Client Disconnected.
```
This proves the ESP32 actually received and processed your data!

---

### 🆘 Troubleshooting

| Problem | Solution |
| :--- | :--- |
| **"Could not open connection to the host"** | 1. Check if the IP address is correct.<br>2. Make sure your Computer and ESP32 are connected to the **SAME** Wi-Fi network. This is the #1 mistake. |
| **"Command not found: telnet"** | You didn't enable Telnet. Follow the "Enable Telnet" instructions in Step 4 again. |
| **I type but nothing appears** | Telnet sometimes doesn't show what you type until you hit Enter. Just type `Hello` blindly and press Enter. |
| **Wi-Fi won't connect** | Go back to Experiment 1 and make sure your password is correct. |

---

### 🔐 Security Note: Disable Telnet
*Telnet is an insecure protocol. After you finish this experiment, it is good practice to turn it off.*

Run this command in your Administrator Command Prompt:

```cmd
dism /online /Disable-Feature /FeatureName:TelnetClient