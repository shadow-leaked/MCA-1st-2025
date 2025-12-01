# 🌐 Experiment 4: IPv6 Networking (The Future of Internet)

![Difficulty](https://img.shields.io/badge/Difficulty-Advanced-red?style=for-the-badge)
![Time](https://img.shields.io/badge/Time_Required-20_Minutes-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Tested-success?style=for-the-badge)

## 🤔 What are we doing?
Up until now, we used **IPv4** addresses (like `192.168.1.105`). These are running out globally!
The future is **IPv6**, which looks crazy long (like `fe80::2s44:56ff:fe12:3456`).

In this experiment, we will force the ESP32 to:
1.  Enable IPv6 (it's off by default).
2.  Get a new, long IPv6 address.
3.  Receive a message from your computer using this new address.

---

## 🎒 What You Need (Checklist)
1.  **ESP32 Board**.
2.  **Arduino IDE** (Updated to the latest version).
3.  **Wi-Fi Router** (Must be modern enough to support IPv6 - most do).
4.  **Testing Tool:**
    * **Windows:** `Ping` and `Netcat` (optional).
    * **Mac/Linux:** `Ping6` and `Netcat`.

---

## 🛠️ Step-by-Step Guide

### Step 1: Prepare the Code
1.  Open the file `Experiment_4_IPv6_Networking.ino`.
2.  [cite_start]Edit lines **4** and **5** with your Wi-Fi credentials[cite: 220].
    ```cpp
    const char* ssid = "Your_WiFi_Name";
    const char* password = "Your_WiFi_Password";
    ```
3.  [cite_start]**Note:** This code uses special commands (`esp_netif`) to turn on the IPv6 switch inside the chip[cite: 217, 242].

### Step 2: Upload
1.  Plug in the ESP32.
2.  Select **Board** and **Port**.
3.  Hit **Upload (➡️)**.

### Step 3: Get the IPv6 Address (The Hard Part)
1.  Open **Serial Monitor** (`115200` baud).
2.  Press **EN** (Reset).
3.  Wait for the connection.
4.  You will see TWO addresses now:
    * **IPv4:** `192.168.1.xxx` (The old style)
    * **IPv6:** `FE80::A6CF:12FF:FE6D:CCDC` (The new style - yours will be different!) 
5.  📝 **Write down the IPv6 Address carefully.** (It is very long!).

---

## 🧪 Step 4: How to Test

### 🖥️ Option A: Ping Test (Windows)
1.  Open Command Prompt (`cmd`).
2.  Type:
    ```cmd
    ping <YOUR_IPV6_ADDRESS>
    ```
    *(Example: `ping FE80::A6CF:12FF:FE6D:CCDC`)*.
3.  **Result:** You should see `Reply from...`.

### 🍎 Option B: Ping Test (Mac/Linux)
1.  Open Terminal.
2.  Type:
    ```bash
    ping6 <YOUR_IPV6_ADDRESS>
    ```
    *Note: Sometimes you need to add `%en0` or `%wlan0` to the end of the address on Mac/Linux to tell it which network card to use (e.g., `ping6 fe80::1234%en0`).*

### 🚀 Option C: Sending Data (Advanced)
If you have **Netcat** installed (or use the Ncat tool from Exp 2), you can send a real message.

**Command:**
```bash
ncat -6 -u <YOUR_IPV6_ADDRESS> 5555
```

* `-6` means "Use IPv6".
* `-u` means "Use UDP".
* `5555` is the port number.

Type `Hello IPv6` and hit **Enter**. The ESP32 should reply!

---

### 🕵️ Step 5: Serial Monitor Output
If successful, the ESP32 Serial Monitor will show:

```text
IPv6 Link-local address created.
IPv6 Address: FE80::A6CF:12FF:FE6D:CCDC
Received 12 bytes via UDP
Data: Hello IPv6
Sent reply.
```
### 🆘 Troubleshooting

| Problem | Solution |
| :--- | :--- |
| **"Destination host unreachable"** | Your computer and ESP32 must be on the **SAME** Wi-Fi. Also, your router might have IPv6 disabled in its settings. |
| **I don't see an IPv6 address in Serial Monitor** | The code waits 10 seconds for an address. If it fails, your router might not support IPv6. You can still pass the experiment by showing the IPv4 part working. |
| **Ping works but Netcat fails** | Ensure you are using the `-6` flag in Netcat. Normal Netcat defaults to IPv4. |
| **"General Failure" (Windows)** | Windows sometimes blocks IPv6 Pings to "Link-Local" addresses without a "Zone ID". Try `ping <IPv6>%<InterfaceIndex>`. (This is advanced; usually standard ping works). |