/**
 * WindowsSwiftPair Example
 * 
 * This example demonstrates how to use the BLESpam library to create
 * Microsoft Swift Pair popups on nearby Windows devices.
 * 
 * Compatible with ESP32 boards
 * 
 * DISCLAIMER: This is for educational purposes only. Use responsibly.
 */

#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    Serial.begin(115200);
    Serial.println("BLESpam - Windows Swift Pair Example");
    Serial.println("====================================");
    
    // Initialize the BLE spam library
    if (!bleSpam.begin("ESP32-SwiftPair")) {
        Serial.println("Failed to initialize BLE!");
        while(1) delay(1000);
    }
    
    Serial.println("BLE initialized successfully!");
    
    // Configure advertising parameters
    bleSpam.setAdvertisingInterval(100); // 100ms interval
    bleSpam.setTxPower(3);               // 3 dBm power
    bleSpam.setRandomMac(true);          // Use random MAC address
    
    Serial.println("Starting Windows Swift Pair advertisements...");
    
    // Start advertising
    bleSpam.advertiseWindowsSwiftPair();
}

void loop() {
    // Just keep advertising
    Serial.println("Advertising Swift Pair...");
    delay(5000);
}
