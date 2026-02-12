/**
 * Basic compilation test for BLESpam library
 * This file verifies that the library headers compile correctly
 */

#include "BLESpam.h"

// Test that all enums are defined
void test_enums() {
    BLESpamTarget target = TARGET_APPLE_IOS;
    AppleDeviceType device = AIRPODS_PRO;
    AppleContinuityType continuity = CONTINUITY_NEW_DEVICE;
    
    (void)target;
    (void)device;
    (void)continuity;
}

// Test that the main class can be instantiated
void test_class_instantiation() {
    BLESpam spam;
    (void)spam;
}

// Test that constants are defined
void test_constants() {
    uint16_t apple = MANUFACTURER_ID_APPLE;
    uint16_t microsoft = MANUFACTURER_ID_MICROSOFT;
    uint16_t samsung = MANUFACTURER_ID_SAMSUNG;
    uint8_t max_size = MAX_BLE_ADVERTISEMENT_SIZE;
    
    (void)apple;
    (void)microsoft;
    (void)samsung;
    (void)max_size;
}

// Main function (required for compilation test)
int main() {
    test_enums();
    test_class_instantiation();
    test_constants();
    return 0;
}
