# BLESpam Library

> [日本語ドキュメント](README_ja.md) | [English Documentation](README.md)

A powerful Arduino library for creating Bluetooth Low Energy (BLE) advertisements that mimic various device pairing services. Compatible with ESP32, nRF52, and other BLE-capable microcontrollers.

## Features

- 🍎 **Apple Continuity** - Generate "New Device" popups on iOS devices (AirPods, Beats, etc.)
- 🪟 **Microsoft Swift Pair** - Trigger pairing prompts on Windows devices
- 📱 **Samsung Easy Setup** - Create pairing dialogs on Samsung devices
- ⚡ **Easy to Use** - Simple API with minimal code required
- 🎯 **Customizable** - Adjust advertising interval, TX power, and MAC address
- 🔧 **Arduino Compatible** - Works with Arduino IDE and PlatformIO

## Supported Platforms

- **ESP32** (ESP32, ESP32-S3, ESP32-C3, etc.) - Fully supported
- **nRF52** series - Coming soon
- Other BLE-capable microcontrollers - Coming soon

## Installation

### Arduino IDE

1. Download the latest release from [GitHub Releases](https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon/releases)
2. In Arduino IDE, go to **Sketch → Include Library → Add .ZIP Library**
3. Select the downloaded ZIP file

### PlatformIO

Add to your `platformio.ini`:

```ini
lib_deps = 
    https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon.git
```

### Manual Installation

1. Clone or download this repository
2. Copy the `BLESpamLibrary` folder to your Arduino libraries directory:
   - Windows: `Documents\Arduino\libraries\`
   - Mac: `~/Documents/Arduino/libraries/`
   - Linux: `~/Arduino/libraries/`

## Quick Start

### Basic Apple Device Spam

```cpp
#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    Serial.begin(115200);
    
    // Initialize BLE
    bleSpam.begin("ESP32-BLE");
    
    // Configure parameters
    bleSpam.setAdvertisingInterval(100); // 100ms
    bleSpam.setTxPower(3);               // 3 dBm
    
    // Start advertising AirPods Pro
    bleSpam.advertiseAppleDevice(AIRPODS_PRO);
}

void loop() {
    // Keep running
    delay(1000);
}
```

### Windows Swift Pair

```cpp
#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    bleSpam.begin("ESP32-Swift");
    bleSpam.advertiseWindowsSwiftPair();
}

void loop() {
    delay(1000);
}
```

## API Reference

### Initialization

#### `bool begin(const char* deviceName = "BLE Spam")`

Initialize the BLE spam library.

- **Parameters:**
  - `deviceName`: Optional Bluetooth device name
- **Returns:** `true` if successful, `false` otherwise

#### `void stop()`

Stop BLE advertising.

### Apple Devices

#### `void advertiseAppleDevice(AppleDeviceType deviceType)`

Advertise an Apple device to trigger "New Device" popups on iOS devices.

**Supported Apple Devices:**
- `AIRPODS_PRO` - AirPods Pro
- `AIRPODS_MAX` - AirPods Max
- `AIRPODS` - AirPods (1st Gen)
- `AIRPODS_GEN2` - AirPods (2nd Gen)
- `AIRPODS_GEN3` - AirPods (3rd Gen)
- `AIRPODS_PRO_GEN2` - AirPods Pro (2nd Gen)
- `BEATS_FLEX` - Beats Flex
- `BEATS_SOLO3` - Beats Solo 3
- `POWERBEATS3` - Powerbeats 3
- `POWERBEATS_PRO` - Powerbeats Pro
- `BEATS_SOLO_PRO` - Beats Solo Pro
- `BEATS_STUDIO_BUDS` - Beats Studio Buds
- `BEATS_X` - Beats X
- `BEATS_STUDIO3` - Beats Studio 3
- `BEATS_STUDIO_PRO` - Beats Studio Pro
- `BEATS_FIT_PRO` - Beats Fit Pro
- `BEATS_STUDIO_BUDS_PLUS` - Beats Studio Buds+

### Windows Devices

#### `void advertiseWindowsSwiftPair()`

Advertise Microsoft Swift Pair to trigger pairing prompts on Windows devices.

### Samsung Devices

#### `void advertiseSamsungEasySetup(const char* model = "Buds")`

Advertise Samsung Easy Setup to trigger pairing dialogs on Samsung devices.

- **Parameters:**
  - `model`: Device model ("Buds", "Watch", etc.)

### Configuration

#### `void setAdvertisingInterval(uint16_t intervalMs)`

Set the BLE advertising interval.

- **Parameters:**
  - `intervalMs`: Interval in milliseconds (20-10240, default: 100)

**Note:** Lower intervals = more frequent advertisements but higher power consumption.

#### `void setTxPower(int8_t powerDbm)`

Set the transmission power level.

- **Parameters:**
  - `powerDbm`: Power in dBm (ESP32: -12, -9, -6, -3, 0, 3, 6, 9)

**Note:** Higher power = longer range but higher power consumption.

#### `void setRandomMac(bool enable)`

Enable or disable random MAC address.

- **Parameters:**
  - `enable`: `true` for random MAC, `false` for static MAC

## Examples

The library includes several example sketches:

1. **AppleBLESpam** - Cycle through different Apple devices
2. **WindowsSwiftPair** - Advertise Windows Swift Pair
3. **SamsungEasySetup** - Advertise Samsung Easy Setup
4. **AllDevicesSpam** - Cycle through all spam types
5. **RandomAppleSpam** - Advanced random device spam with statistics

## Hardware Requirements

### ESP32

- Any ESP32 board with BLE support
- Recommended: ESP32-DevKitC, ESP32-WROOM, ESP32-S3

### Power

- USB power: 5V via USB
- Battery: 3.3V LiPo battery (with appropriate voltage regulator)

## Range

The effective range depends on several factors:

- **TX Power Level**: Higher power = longer range
- **Antenna**: Built-in antenna vs external antenna
- **Environment**: Obstacles, interference, etc.

Typical range:
- Indoor: 10-30 meters
- Outdoor: 30-100 meters (with high TX power)

## Legal and Ethical Considerations

⚠️ **IMPORTANT DISCLAIMER** ⚠️

This library is provided for **educational and research purposes only**.

- This tool creates BLE advertisements that may cause unwanted popups on nearby devices
- Use of this library may be illegal in some jurisdictions
- Using this library to harass, annoy, or harm others is unethical and potentially illegal
- Always obtain permission before testing on devices you do not own
- The authors are not responsible for any misuse of this library

**Use responsibly and ethically.**

## Credits

This library is based on:

- [Bluetooth LE Spam Android App](https://github.com/simondankelmann/Bluetooth-LE-Spam) by Simon Dankelmann
- [Flipper Zero BLE Spam](https://github.com/Willy-JL/Flipper-XTREME) contributions
- Research by furiousMAC, Hexway, and others

Special thanks to all contributors and researchers in the BLE security community.

## License

This project is licensed under the GPL-3.0 License - see the [LICENSE](../LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Support

For issues, questions, or contributions:
- GitHub Issues: [Report an issue](https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon/issues)
- Discussions: [Join the discussion](https://github.com/hirorogo/Bluetooth-LE-Spam-for-micon/discussions)

## Changelog

### Version 1.0.0 (Initial Release)
- Apple Continuity support (17 device types)
- Microsoft Swift Pair support
- Samsung Easy Setup support
- ESP32 platform support
- Basic examples and documentation
