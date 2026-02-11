# Getting Started with BLESpam Library

This guide will help you get started with the BLESpam library on your microcontroller.

## Prerequisites

### Hardware
- ESP32 development board (ESP32, ESP32-S3, ESP32-C3, etc.)
- USB cable for programming
- Computer with Arduino IDE or PlatformIO

### Software
- Arduino IDE 1.8.13+ or Arduino IDE 2.x
- ESP32 board support package

## Setup Instructions

### 1. Install Arduino IDE

If you haven't already, download and install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software).

### 2. Install ESP32 Board Support

1. Open Arduino IDE
2. Go to **File → Preferences**
3. In "Additional Board Manager URLs", add:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Go to **Tools → Board → Boards Manager**
5. Search for "esp32"
6. Install "esp32 by Espressif Systems"

### 3. Install BLESpam Library

See the main README.md for installation instructions.

### 4. Connect Your ESP32

1. Connect your ESP32 board to your computer via USB
2. In Arduino IDE, go to **Tools → Board** and select your ESP32 board
3. Go to **Tools → Port** and select the appropriate COM port

### 5. Upload Your First Sketch

1. Go to **File → Examples → BLESpam → AppleBLESpam**
2. Click the **Upload** button (→)
3. Wait for the sketch to compile and upload
4. Open the Serial Monitor (**Tools → Serial Monitor**) at 115200 baud

You should see output indicating that BLE has been initialized and advertising has started.

## Testing

### Testing Apple Device Spam

1. Upload the **AppleBLESpam** example to your ESP32
2. Have an iPhone or iPad nearby
3. You should see popup notifications appearing on the iOS device showing different Apple products

### Testing Windows Swift Pair

1. Upload the **WindowsSwiftPair** example to your ESP32
2. Have a Windows 10/11 PC with Bluetooth enabled nearby
3. You should see Swift Pair notifications in the system tray

### Testing Samsung Easy Setup

1. Upload the **SamsungEasySetup** example to your ESP32
2. Have a Samsung phone with Bluetooth enabled nearby
3. You should see Easy Setup notifications

## Troubleshooting

### "Failed to initialize BLE!"

**Problem:** The BLE initialization failed.

**Solutions:**
- Make sure you're using an ESP32 board (not ESP8266)
- Try resetting the board
- Check that your ESP32 board has BLE support

### No popups appearing on target devices

**Problem:** No notifications are showing up on nearby devices.

**Solutions:**
- Make sure Bluetooth is enabled on the target device
- Move the ESP32 closer to the target device
- Try increasing the TX power: `bleSpam.setTxPower(9);`
- Some devices may have patched these vulnerabilities
- iOS 17.2+ has partially patched some Apple Continuity popups

### Upload errors

**Problem:** Can't upload sketch to ESP32.

**Solutions:**
- Hold the BOOT button on the ESP32 while uploading
- Make sure the correct COM port is selected
- Try a different USB cable
- Install CP210x or CH340 drivers if needed

### Compilation errors

**Problem:** Sketch won't compile.

**Solutions:**
- Make sure you have ESP32 board support installed
- Update to the latest ESP32 board package
- Check that the BLESpam library is installed correctly

## Next Steps

Once you have the basic examples working:

1. Try the **AllDevicesSpam** example to see multiple spam types
2. Experiment with different advertising intervals
3. Adjust TX power for different ranges
4. Create your own custom spam patterns

## Safety and Legal Notes

- This tool is for **educational purposes only**
- Always get permission before testing on devices you don't own
- Be aware of local laws regarding wireless transmissions
- Use responsibly and ethically

## Additional Resources

- [BLESpam Library README](../README.md)
- [ESP32 BLE Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/bluetooth/esp_gap_ble.html)
- [Arduino ESP32 Documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

## Support

If you encounter issues:
1. Check the troubleshooting section above
2. Search existing GitHub issues
3. Create a new issue with:
   - Your board model
   - Arduino IDE version
   - ESP32 board package version
   - Complete error messages
   - What you've already tried

Happy hacking! 🚀
