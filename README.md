# 📡 MCA IoT Practical Experiments: ESP32 Networking

![ESP32](https://img.shields.io/badge/Hardware-ESP32-blue?style=for-the-badge&logo=espressif)
![Arduino](https://img.shields.io/badge/IDE-Arduino-teal?style=for-the-badge&logo=arduino)
![Status](https://img.shields.io/badge/Status-Complete-green?style=for-the-badge)

Welcome to the collection of IoT networking experiments using the **ESP32** microcontroller. This repository covers IPv4 and IPv6 networking, TCP/UDP protocols, and socket programming.

## 📋 Experiments Overview

| Exp # | Title | Protocol | Description |
| :---: | :--- | :---: | :--- |
| [**01**](./Experiment_1_WiFi_Connect/README.md) | [**Wi-Fi Connection**](./Experiment_1_WiFi_Connect/README.md) | IPv4 | Connect ESP32 to Wi-Fi and verify via Ping. |
| [**02**](./Experiment_2_TCP_Server/README.md) | [**TCP Server**](./Experiment_2_TCP_Server/README.md) | TCP/IP | Establish a TCP server and exchange messages via Telnet. |
| [**03**](./Experiment_3_UDP_Echo_IPv4/README.md) | [**UDP Echo Server**](./Experiment_3_UDP_Echo_IPv4/README.md) | UDP/IP | Stateless packet exchange using UDP (IPv4). |
| [**04**](./Experiment_4_IPv6_Networking/README.md) | [**IPv6 Networking**](./Experiment_4_IPv6_Networking/README.md) | UDP/IPv6 | Advanced networking using IPv6 addressing. |

## 🛠️ Hardware & Software Requirements
* **Microcontroller:** ESP32 DevKit V1 or NodeMCU ESP-32S.
* **IDE:** Arduino IDE (v1.8 or 2.0+).
* **Libraries:** `WiFi.h`, `WiFiUdp.h` (Built-in with ESP32 board manager).
* **Tools:**
    * `Ping` (CMD/Terminal)
    * `Telnet` (Windows Feature)
    * `Netcat` (Optional for advanced testing)
    * `Packet Sender` (Optional GUI tool)

## ⚡ Quick Start
1.  Clone this repository:
    ```bash
    git clone https://github.com/shadow-leaked/MCA-1st-2025.git
    ```
2.  Open the `.ino` file for the desired experiment in Arduino IDE.
3.  Update the `ssid` and `password` variables with your Wi-Fi credentials.
4.  Select your Board (e.g., **DOIT ESP32 DEVKIT V1**) and Port.
5.  Upload and open the **Serial Monitor** (Baud Rate: `115200`).

---

## 👨‍💻 Contributors & Author
Maintained by **[Shadow Leaked]** for the MCA IoT curriculum.

* **Repository:** [[Link to repo](https://github.com/shadow-leaked/MCA-1st-2025.git)]
* **Issues:** Found a bug? [Open an issue here](https://github.com/shadow-leaked/MCA-1st-2025/issues)
* **License:** This project is open-source and available under the **MIT License**.

> *"The Internet of Things is not just about connecting things, it's about connecting people to data."*

---
*Created for MCA IoT Practicals.*