# 🌱 **Pothos Guardian**  
### *Offline Plant Health Monitor for ESP8266*

---

## 📌 Overview  
**Pothos Guardian** is a **fully offline, local-only** plant monitoring system built for the **Pothos plant** (but adaptable to any houseplant). It runs on an **ESP8266 (NodeMCU)** and requires **no internet, cloud services, or phone notifications** — everything stays on your local Wi-Fi.

> ✅ **100% self-contained** • ✅ **No external dependencies** • ✅ **Privacy-first**

---

## 🎯 Core Features (MVP)

- 🌡️ **Real-time soil moisture monitoring** via analog sensor  
- 🌐 **Mobile-optimized local web dashboard** (accessible at `http://[IP]:8423`)  
- 💧 **Visual "Needs Water!" alert** when moisture drops below 30%  
- 📱 **Responsive design**: works on phones, tablets, and desktops  
- 🔌 **USB-powered** — runs 24/7 from a wall adapter or computer  
- 🌐 **Local Wi-Fi only** — no data leaves your network  

> ⛔ **SD card logging is paused** (Phase 2) due to ESP8266 power constraints.

---

## 📦 Hardware Used

| Component | Details |
|--------|--------|
| **Microcontroller** | ESP8266 NodeMCU (HiLetgo) |
| **Soil Sensor** | WWZMDiB LM393-based analog moisture sensor (3.3V compatible) |
| **Power** | USB 5V → onboard 3.3V regulator |
| **Connectivity** | 2.4GHz Wi-Fi only |
| **Optional** | Single status LED (e.g., on D4) for dry-alert (not required) |

> 🔌 **Wiring**:  
> - Soil Sensor `VCC` → **3.3V**  
> - Soil Sensor `GND` → **GND**  
> - Soil Sensor `A0` → **A0** on NodeMCU  

---

## 📁 Project Structure

```
PothosGuardian/
├── PothosGuardian.ino     // Main: Wi-Fi + setup/loop
├── web_server.ino         // Local web dashboard (mobile-optimized)
└── sensors.ino            // Calibrated soil moisture readings
```

> 📝 All files must be in the **same folder**. Arduino IDE auto-merges `.ino` files.

---

## 🛠️ Setup Instructions

### 1. **Configure Wi-Fi**
In `PothosGuardian.ino`, update:
```cpp
const char* ssid = "YOUR_2.4GHz_SSID";
const char* password = "YOUR_PASSWORD";
```
> ⚠️ Must be **2.4GHz Wi-Fi** — ESP8266 does **not support 5GHz**.

### 2. **Upload Code**
- Use **Arduino IDE** with **ESP8266 core v3.1.2+**
- Board: `NodeMCU 1.0 (ESP-12E Module)`
- Port: Select your COM port

### 3. **Access Dashboard**
1. Open **Serial Monitor (115200 baud)** after upload  
2. Note the **IP address** (e.g., `192.168.1.42`)  
3. On any device on the **same Wi-Fi**, visit:  
   ```
   http://[IP]:8423
   ```

---

## 🌐 Web Dashboard

- **Mobile-first design**: max-width `300px`, responsive down to 320px  
- Shows:  
  - Current soil moisture (%)  
  - Red "💧 NEEDS WATER!" banner if <30%  
- Dark theme for low-light readability  
- Auto-refresh: reload page manually or add `<meta refresh>` (optional)

![Dashboard Preview](Screenshot%202025-10-30%20083758.png)

---

## 🔬 Sensor Calibration

Calibrated using **real-world testing**:
- **Dry (air)**: ~970 → **0% moisture**  
- **Wet (submerged)**: ~410 → **100% moisture**  

Values are mapped linearly and clamped to `0–100%`.  
Edit `DRY_VALUE` / `WET_VALUE` in `sensors.ino` if re-calibrating.

---

## 🚫 Known Limitations

- **No persistent logging** (SD card integration deferred)  
- **No ambient sensors** (DHT22 support planned for Phase 2)  
- **Single plant only** (multi-plant requires hardware expansion)

---

## 🌿 Ideal Pothos Care Range
- **Moisture**: 30% – 70%  
- **Alert threshold**: <30% → time to water!  
- Avoid overwatering (>80% for extended periods)

---

## 📜 License  
MIT — use, modify, and share freely.

---

## 🙌 Credits  
Built with ❤️ for plant parents who value **simplicity, privacy, and reliability**.

> 🌱 *"The best plant tech is the kind that just works — quietly, locally, and without asking for your data."*

---

**Happy growing!** 🌿💧
