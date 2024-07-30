#include <assert.h>
#include "battery.h"

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 0.9));
    assert(batteryIsOk(41, 70, 0.7));  // Should trigger warning for temperature
    assert(batteryIsOk(25, 78, 0.7));  // Should trigger warning for SoC
    assert(batteryIsOk(25, 70, 0.78)); // Should trigger warning for charge rate
    printf("All tests passed!\n");
    return 0;
}

