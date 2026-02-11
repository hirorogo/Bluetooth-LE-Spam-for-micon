/**
 * AllDevicesSpam Example
 * 
 * This example demonstrates how to use the BLESpam library to cycle through
 * different types of BLE spam advertisements targeting multiple platforms.
 * 
 * Compatible with ESP32 boards
 * 
 * DISCLAIMER: This is for educational purposes only. Use responsibly.
 */

#include <BLESpam.h>

BLESpam bleSpam;

// Spam types
enum SpamType {
    SPAM_APPLE,
    SPAM_WINDOWS,
    SPAM_SAMSUNG
};

SpamType currentSpam = SPAM_APPLE;
int appleDeviceIndex = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("BLESpam - All Devices Spam Example");
    Serial.println("===================================");
    
    // Initialize the BLE spam library
    if (!bleSpam.begin("ESP32-AllSpam")) {
        Serial.println("Failed to initialize BLE!");
        while(1) delay(1000);
    }
    
    Serial.println("BLE initialized successfully!");
    
    // Configure advertising parameters
    bleSpam.setAdvertisingInterval(100); // 100ms interval
    bleSpam.setTxPower(3);               // 3 dBm power
    bleSpam.setRandomMac(true);          // Use random MAC address
    
    Serial.println("Starting multi-platform spam...");
}

void loop() {
    // Stop current advertising
    bleSpam.stop();
    delay(100);
    
    switch (currentSpam) {
        case SPAM_APPLE:
            {
                Serial.print("Advertising Apple device: ");
                AppleDeviceType device = appleDevices[appleDeviceIndex].type;
                Serial.println(appleDevices[appleDeviceIndex].name);
                bleSpam.advertiseAppleDevice(device);
                
                // Move to next Apple device
                appleDeviceIndex = (appleDeviceIndex + 1) % appleDevicesCount;
                if (appleDeviceIndex == 0) {
                    currentSpam = SPAM_WINDOWS;
                }
            }
            break;
            
        case SPAM_WINDOWS:
            Serial.println("Advertising Windows Swift Pair");
            bleSpam.advertiseWindowsSwiftPair();
            currentSpam = SPAM_SAMSUNG;
            break;
            
        case SPAM_SAMSUNG:
            Serial.println("Advertising Samsung Easy Setup");
            bleSpam.advertiseSamsungEasySetup("Buds");
            currentSpam = SPAM_APPLE;
            break;
    }
    
    // Wait before next spam
    delay(3000);
}
