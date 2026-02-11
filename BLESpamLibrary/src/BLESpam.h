/**
 * BLESpam Library
 * 
 * A library for creating BLE advertisements that mimic various services
 * Compatible with ESP32, nRF52, and other BLE-capable microcontrollers
 * 
 * Based on the Bluetooth LE Spam Android app
 * https://github.com/simondankelmann/Bluetooth-LE-Spam
 * 
 * Copyright (C) 2024 hirorogo
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * DISCLAIMER: This is for educational purposes only. Use responsibly.
 */

#ifndef BLESPAM_H
#define BLESPAM_H

#include <Arduino.h>

// Manufacturer IDs
#define MANUFACTURER_ID_APPLE 0x004C      // 76
#define MANUFACTURER_ID_MICROSOFT 0x0006  // 6
#define MANUFACTURER_ID_SAMSUNG 0x0075    // 117

// Maximum advertisement data size
#define MAX_BLE_ADVERTISEMENT_SIZE 31

/**
 * BLE Spam Target Devices
 */
enum BLESpamTarget {
    TARGET_APPLE_IOS,
    TARGET_MICROSOFT_WINDOWS,
    TARGET_SAMSUNG,
    TARGET_GOOGLE_ANDROID,
    TARGET_ALL
};

/**
 * Apple Device Types for Continuity
 */
enum AppleDeviceType {
    AIRPODS_PRO,
    AIRPODS_MAX,
    AIRPODS,
    AIRPODS_GEN2,
    AIRPODS_GEN3,
    AIRPODS_PRO_GEN2,
    BEATS_FLEX,
    BEATS_SOLO3,
    POWERBEATS3,
    POWERBEATS_PRO,
    BEATS_SOLO_PRO,
    BEATS_STUDIO_BUDS,
    BEATS_X,
    BEATS_STUDIO3,
    BEATS_STUDIO_PRO,
    BEATS_FIT_PRO,
    BEATS_STUDIO_BUDS_PLUS
};

/**
 * Apple Continuity Message Types
 */
enum AppleContinuityType {
    CONTINUITY_NEW_DEVICE = 0x07,
    CONTINUITY_NOT_YOUR_DEVICE = 0x01,
    CONTINUITY_NEW_AIRTAG = 0x13,
    CONTINUITY_IOS17_CRASH = 0x12
};

/**
 * Main BLESpam class
 */
class BLESpam {
public:
    BLESpam();
    
    /**
     * Initialize the BLE spam library
     * @param deviceName The Bluetooth device name (optional)
     * @return true if initialization successful
     */
    bool begin(const char* deviceName = "BLE Spam");
    
    /**
     * Stop BLE spam
     */
    void stop();
    
    /**
     * Generate and advertise Apple Continuity "New Device" popup
     * @param deviceType The Apple device type to mimic
     */
    void advertiseAppleDevice(AppleDeviceType deviceType);
    
    /**
     * Generate and advertise Apple Continuity with custom data
     * @param continuityType The continuity message type
     * @param data Custom manufacturer data (without manufacturer ID)
     * @param dataLen Length of custom data
     */
    void advertiseAppleContinuity(AppleContinuityType continuityType, const uint8_t* data, uint8_t dataLen);
    
    /**
     * Generate and advertise Microsoft Swift Pair popup
     */
    void advertiseWindowsSwiftPair();
    
    /**
     * Generate and advertise Samsung Easy Setup popup
     * @param model Samsung device model (e.g., "Buds", "Watch")
     */
    void advertiseSamsungEasySetup(const char* model = "Buds");
    
    /**
     * Generate and advertise Fast Pair device
     * @param modelId 3-byte Fast Pair model ID (in hex string format, e.g., "0220")
     */
    void advertiseFastPair(const char* modelId);
    
    /**
     * Set advertising interval in milliseconds
     * @param intervalMs Interval in milliseconds (20-10240, default: 100)
     */
    void setAdvertisingInterval(uint16_t intervalMs);
    
    /**
     * Set TX power level
     * @param powerDbm Power in dBm (-12, -9, -6, -3, 0, 3, 6, 9 for ESP32)
     */
    void setTxPower(int8_t powerDbm);
    
    /**
     * Enable/disable random MAC address
     * @param enable true to use random MAC, false for static
     */
    void setRandomMac(bool enable);
    
    /**
     * Get random byte for payload generation
     */
    static uint8_t getRandomByte();
    
private:
    bool _initialized;
    uint16_t _advertisingInterval;
    int8_t _txPower;
    bool _randomMac;
    
    // Helper functions for generating advertisement data
    void _generateAppleNewDeviceData(AppleDeviceType deviceType, uint8_t* data, uint8_t* dataLen);
    void _generateSwiftPairData(uint8_t* data, uint8_t* dataLen);
    void _generateSamsungData(const char* model, uint8_t* data, uint8_t* dataLen);
    void _generateFastPairData(const char* modelId, uint8_t* data, uint8_t* dataLen);
    
    // Platform-specific advertising function
    bool _startAdvertising(uint16_t manufacturerId, const uint8_t* data, uint8_t dataLen);
    void _stopAdvertising();
};

/**
 * Apple Device Type to hex code mapping
 */
struct AppleDeviceData {
    AppleDeviceType type;
    const char* hexCode;
    const char* name;
};

// Device data table
extern const AppleDeviceData appleDevices[];
extern const uint8_t appleDevicesCount;

#endif // BLESPAM_H
