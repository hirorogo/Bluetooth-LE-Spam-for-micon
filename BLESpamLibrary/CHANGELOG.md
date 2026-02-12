# Changelog

> [日本語版](CHANGELOG_ja.md) | [English](CHANGELOG.md)

All notable changes to the BLESpam library will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2024-02-11

### Added
- Initial release of BLESpam Arduino library
- ESP32 platform support with full BLE functionality
- Apple Continuity advertisement support
  - 17 different Apple device types (AirPods, Beats, etc.)
  - New Device popup generation
  - Random battery levels and device-specific data
- Microsoft Swift Pair advertisement support
  - Windows 10/11 pairing prompt generation
- Samsung Easy Setup advertisement support
  - Samsung device pairing dialog generation
- Core library features:
  - Configurable advertising interval (20-10240ms)
  - Adjustable TX power level (-12 to 9 dBm on ESP32)
  - Random MAC address support
  - Platform-agnostic design for future expansion
- Five example sketches:
  - AppleBLESpam: Cycle through Apple devices
  - WindowsSwiftPair: Windows Swift Pair spam
  - SamsungEasySetup: Samsung Easy Setup spam
  - AllDevicesSpam: Multi-platform spam cycling
  - RandomAppleSpam: Advanced random device spam
- Comprehensive documentation:
  - Main README.md with full API reference
  - Japanese README (README_ja.md)
  - Getting Started guide
  - PlatformIO configuration example
  - Arduino IDE syntax highlighting (keywords.txt)
- License and legal notices:
  - GPL-3.0 license
  - Educational use disclaimer
  - Proper copyright headers

### Notes
- This library is based on the Bluetooth LE Spam Android app
- Credits to Simon Dankelmann and the BLE security research community
- For educational and research purposes only

## [Unreleased]

### Planned Features
- nRF52 series support
- Additional platform support (nRF Connect SDK, Zephyr)
- More device types and spam patterns
- Web-based configuration interface
- OTA update support
- Power management optimizations
- Additional Fast Pair device models
- Lovespouse/adult toy spam support
- BLE scanner/detector functionality

### Known Issues
- None reported yet

---

For more information, see the [README](README.md).
