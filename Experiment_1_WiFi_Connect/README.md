# 📡 Experiment 1: Connecting ESP32 to Wi-Fi (The Hello World of IoT)

![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-green?style=for-the-badge)
![Time](https://img.shields.io/badge/Time_Required-10_Minutes-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Tested-success?style=for-the-badge)

## 🤔 What are we doing?
Imagine the **ESP32** is a tiny computer that doesn't know how to talk to the internet yet. In this experiment, we are simply giving it your Wi-Fi password so it can say "I'm here!" to your router.

We will then use your laptop to "ping" (poke) the ESP32 to confirm it is actually listening.

---

## 🎒 What You Need (Checklist)
Before you start, make sure you have these items:

1.  **ESP32 Board:** The "brain" of our project.
2.  **Micro USB Cable:** ⚠️ **IMPORTANT:** It must be a *Data Cable*. Some cables are for charging only and will not work. If the computer doesn't make a sound when you plug it in, try a different cable.
3.  **A Computer:** Windows, Mac, or Linux.
4.  **Wi-Fi Name & Password:** You need the credentials for the network you want to connect to.

---

## 🛠️ Step-by-Step Guide

### Step 1: Install the Software
If you haven't already, you need the **Arduino IDE**. This is the program we use to write instructions for the ESP32.
1.  Download and install it from the [Arduino Website](https://www.arduino.cc/en/software).
2.  Open Arduino IDE.


![Image of Arduino IDE interface](/Img/1.png)


### Step 2: Prepare the "Sketch" ( The Code)
In the Arduino world, code files are called "Sketches".
1.  Open the file `Experiment_1_WiFi_Connect.ino` provided in this folder.
2.  Look for lines **4** and **5**. They look like this:

```cpp
const char* ssid = "Your_WiFi_Name";
const char* password = "Your_WiFi_Password";
```
### 📝 Configuration
1.  **Action:** Replace `Your_WiFi_Name` with your actual Wi-Fi name.
2.  **Action:** Replace `Your_WiFi_Password` with your actual Wi-Fi password.
    * **Note:** Keep the quotation marks `""`!
    * **Note:** Wi-Fi names are **Case Sensitive** (Capital letters matter).

---

### 🛠️ Step 3: Connect the Hardware
1.  Plug one end of the USB cable into the **ESP32**.
2.  Plug the other end into your **Laptop**.
3.  Go to the top menu in **Arduino IDE**:
    * Click **Tools** > **Board** > **ESP32 Arduino** > Select **DOIT ESP32 DEVKIT V1** (or the specific name of your board).
    * Click **Tools** > **Port** > Select the port that appears (e.g., `COM3`, `COM4`, or `/dev/cu.usb...`).



![Image of ESP32 DevKit V1 pinout](https://encrypted-tbn3.gstatic.com/licensed-image?q=tbn:ANd9GcRQ9wAh2H6YJebmqQY6jlG-yUYHnNGw45loqSsEXqqzf5uce0tqwxnyc8FEGDdMkj36R53Ot-V8hkA7sGJ32ASmi-gSvXwdDewH3jmtsSNIEIdZyUc)


---

### 📤 Step 4: The Upload (The Tricky Part)
*This sends your code from the computer to the ESP32 chip.*

1.  Click the **Arrow Icon (➡️)** at the top left of the screen (The Upload Button).
2.  Watch the bottom black console area. It will say `Compiling sketch...` then `Uploading...`.
3.  ⚠️ **CRITICAL STEP:** If you see the message `Connecting........_____.....`, press and hold the **BOOT button** on your ESP32 board for **3 seconds**, then release it.
4.  Wait until you see the message: **`Done uploading.`**.

---

### 🖥️ Step 5: See the Result (Serial Monitor)
*Now the code is inside the chip, but how do we see what it's doing?*

1.  Click the **Magnifying Glass Icon (🔍)** top right (or go to `Tools` > `Serial Monitor`).
2.  **Crucial Setting:** At the bottom right of the new window, make sure the speed is set to **`115200 baud`**.
3.  Press the **EN** (Enable/Reset) button on the ESP32 board once to restart it.
4.  **You should see text appearing!**
    * It will print dots `.....` while trying to connect.
    * Once connected, it will proudly shout: `Connected. IP: 192.168.x.x`.
5.  **Write down that IP Address.** You will need it for the next step.

---

### 🕵️ Step 6: Verify with Ping (The "High Five")
*We will now use your computer to verify the connection is real.*

#### For Windows Users:
1.  Press `Windows Key + R` on your keyboard.
2.  Type `cmd` and hit **Enter**. A black box will appear.
3.  Type the following command and hit **Enter**:

```cmd
ping <YOUR_ESP32_IP_ADDRESS>
```
(Example: `ping 192.168.1.105`)

#### For Mac/Linux Users:
1.  Open your **Terminal** app.
2.  Type:

```bash
ping <YOUR_ESP32_IP_ADDRESS>
```
### ✅ What Success Looks Like:
If you see lines saying `Reply from... bytes=32 time=xxms`, **CONGRATULATIONS!** 🥳  
You have successfully built an IoT device that is talking to your network.

---

### 🆘 Troubleshooting (Help! It didn't work)

| Problem | Solution |
| :--- | :--- |
| **"A fatal error occurred: Failed to connect"** | You probably forgot to hold the **BOOT** button when the screen said `Connecting...`. Try uploading again. |
| **It keeps printing dots `.......` forever** | 1. Double-check your Wi-Fi password (case sensitive!).<br>2. Ensure you are using **2.4GHz Wi-Fi**. ESP32 generally does not work with 5GHz Wi-Fi. |
| **"Port" is greyed out in Tools** | Your computer doesn't see the ESP32. **Change your USB cable.** You are likely using a "Charge Only" cable. You need a data cable. |
| **Garbage text in Serial Monitor (`Q?`)** | Change the dropdown number in the Serial Monitor from `9600` to **`115200`**. |