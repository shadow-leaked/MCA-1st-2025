# 📦 Experiment 3: UDP Echo Server (The "Fire and Forget" Protocol)

![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-yellow?style=for-the-badge)
![Time](https://img.shields.io/badge/Time_Required-15_Minutes-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Tested-success?style=for-the-badge)

## 🤔 What are we doing?
In Experiment 2, we used TCP, which is like a **Phone Call** (you say "Hello", I say "Hello", we know we are connected).

Now we are using **UDP**. This is like sending a **Letter** (or a text message).
* You send the message.
* You don't know if they got it unless they reply.
* It is faster but less reliable.

We will program the ESP32 to receive these "letters" (packets) and send a reply back to you.

---

## 🎒 What You Need (Checklist)
1.  **ESP32 Board** (Connected via USB).
2.  **Arduino IDE**.
3.  **Wi-Fi Credentials** (SSID and Password).
4.  **Testing Tool:**
    * **Windows:** We will use a special PowerShell command.
    * **Mac/Linux:** We will use `Netcat`.

---

## 🛠️ Step-by-Step Guide

### Step 1: Prepare the Code
1.  Open the file `Experiment_3_UDP_Echo_IPv4.ino`.
2.  Edit lines **4** and **5**:
    ```cpp
    const char* ssid = "Your_WiFi_Name";
    const char* password = "Your_WiFi_Password";
    ```
    *(Remember: Case Sensitive!)*

### Step 2: Upload
1.  Plug in the ESP32.
2.  Select **Board** and **Port**.
3.  Hit **Upload (➡️)**.
    *(Don't forget the **BOOT** button trick if it gets stuck!)*

### Step 3: Get the IP Address
1.  Open **Serial Monitor** (Baud Rate: `115200`).
2.  Press **EN** (Reset) on the ESP32.
3.  Wait for the connection message:
    > `Connected!`
    > `IP Address: 192.168.1.105`
    > `UDP server started on port 5555`
4.  📝 **Write down the IP Address.**

---

## 🧪 Step 4: How to Test
*Since UDP is different from TCP, we cannot use Telnet. We must use a tool that supports UDP.*

### 🖥️ Option A: PowerShell (Best for Windows)
Windows doesn't have a simple built-in tool for UDP, so we will use a "one-liner" script.

1.  Press **Windows Key + X** and select **Windows PowerShell (Admin)** or just **Terminal**.
2.  **Copy this entire command block below:**

    ```powershell
    $u = New-Object System.Net.Sockets.UdpClient; $u.Connect("YOUR_ESP_IP", 5555); $b = [Text.Encoding]::ASCII.GetBytes("Hello UDP"); $u.Send($b, $b.Length); $r = $u.Receive([ref]$u.Client.LocalEndPoint); [Text.Encoding]::ASCII.GetString($r)
    ```

3.  **Action:** Change `YOUR_ESP_IP` to the actual IP (e.g., `192.168.1.105`) and `Hello UDP` is the desired text , you can change according to your needs.
4.  Hit **Enter**.
5.  **Result:** You should see the text: `Acknowledged by ESP32`.

### 🍎 Option B: Netcat (Mac/Linux)
1.  Open your **Terminal**.
2.  Type this command:
    ```bash
    echo "Hello UDP" | nc -u -w 1 <YOUR_ESP32_IP> 5555
    ```
    *(The `-u` flag tells it to use UDP. The `-w 1` tells it to wait 1 second for a reply).*

3.  **Result:** You should see `Acknowledged by ESP32` printed on your screen.

---

## 🕵️ Step 5: Check Serial Monitor
Look at the Arduino Serial Monitor. When you sent the command, the ESP32 should have printed:

```text
Received 9 bytes from 192.168.1.5:58321
Data: Hello UDP
Sent reply to client.
```
### 🆘 Troubleshooting

| Problem | Solution |
| :--- | :--- |
| **I don't get any reply (Windows)** | Windows Firewall hates UDP. **Turn off your Firewall temporarily** or allow Port 5555. This is the #1 cause of failure. |
| **"Exception calling Connect"** | You typed the IP address wrong in the PowerShell command. Check it again. |
| **Serial Monitor says nothing** | The packet never reached the ESP32. Check: <br>1. Are you on the SAME Wi-Fi? <br>2. Is the IP correct? <br>3. Is your Firewall blocking it? |
| **Packets are lost** | UDP is "unreliable" by design. Try sending the command 2 or 3 times. |