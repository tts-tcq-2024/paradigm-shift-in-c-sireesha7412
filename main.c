#include <stdio.h>
#include <assert.h>
#include "battery_check.h"
#include "language_support.h"

int main() {
    
    assert(batteryIsOk(20, 60, 0.55, LANG_ENG));  // All parameters within range
    assert(!batteryIsOk(49, 87, 0, LANG_ENG));    // Temperature and SOC out of range
    assert(!batteryIsOk(28, 87, 0, LANG_ENG));    // SOC out of range
    assert(!batteryIsOk(23, 69, 0.9, LANG_ENG));  // Charge rate out of range

    assert(batteryIsOk(22, 69, 0.65, LANG_GER));  // All parameters within range
    assert(!batteryIsOk(49, 88, 0, LANG_GER));    // Temperature and SOC out of range
    assert(!batteryIsOk(25, 89, 0, LANG_GER));    // SOC out of range
    assert(!batteryIsOk(24, 68, 0.91, LANG_GER)); // Charge rate out of range

    return 0;
}


