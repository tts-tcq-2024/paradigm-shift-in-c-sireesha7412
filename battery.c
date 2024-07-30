#include <stdio.h>
#include "battery.h"

void printMessage(const char *message) {
    printf("%s", message);
}

int isTemperatureInRange(float temperature, float* warningLevel) {
    *warningLevel = (temperature >= 40 && temperature < 45) ? 1 : (temperature >= 0 && temperature <= 5) ? 2 : 0;
    return (temperature >= 0 && temperature <= 45);
}

int isSocInRange(float soc, float* warningLevel) {
    *warningLevel = (soc >= 76 && soc < 80) ? 1 : (soc >= 20 && soc < 24) ? 2 : 0;
    return (soc >= 20 && soc <= 80);
}

int isChargeRateInRange(float chargeRate, float* warningLevel) {
    *warningLevel = (chargeRate >= 0.76 && chargeRate <= 0.8) ? 1 : 0;
    return (chargeRate <= 0.8);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, 0, "Temperature out of range!\n", "Warning: Approaching charge-peak temperature\n"},
        {isSocInRange, soc, 0, "State of Charge out of range!\n", "Warning: Approaching charge-peak SoC\n"},
        {isChargeRateInRange, chargeRate, 0, "Charge Rate out of range!\n", "Warning: Approaching charge-peak charge rate\n"}
    };

    for (int i = 0; i < sizeof(checks) / sizeof(checks[0]); ++i) {
        float warningLevel = 0;
        if (!checks[i].check(checks[i].value, &warningLevel)) {
            printMessage(checks[i].message);
            return 0;
        } else if (warningLevel == 1) {
            printMessage(checks[i].warningMessage);
        } else if (warningLevel == 2) {
            printMessage("Warning: Approaching discharge level\n");
        }
    }

    return 1;
}
