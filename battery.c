#include <stdio.h>
#include "battery.h"

void printMessage(const char *message) {
    printf("%s", message);
}

int checkRange(float value, float lower, float upper) {
    return (value >= lower && value <= upper);
}

void setWarningLevel(float value, float upperLimit, float lowerLimit, float *warningLevel) {
    *warningLevel = (value >= upperLimit - 4 && value < upperLimit) ? 1 : 
                    (value >= lowerLimit && value < lowerLimit + 4) ? 2 : 0;
}

int isTemperatureInRange(float temperature, float* warningLevel) {
    setWarningLevel(temperature, 45, 0, warningLevel);
    return checkRange(temperature, 0, 45);
}

int isSocInRange(float soc, float* warningLevel) {
    setWarningLevel(soc, 80, 20, warningLevel);
    return checkRange(soc, 20, 80);
}

int isChargeRateInRange(float chargeRate, float* warningLevel) {
    setWarningLevel(chargeRate, 0.8, 0, warningLevel);
    return checkRange(chargeRate, 0, 0.8);
}

void handleWarnings(float warningLevel, const char* approachingPeak, const char* approachingDischarge) {
    if (warningLevel == 1) {
        printMessage(approachingPeak);
    } else if (warningLevel == 2) {
        printMessage(approachingDischarge);
    }
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
        } else {
            handleWarnings(warningLevel, checks[i].warningMessage, "Warning: Approaching discharge level\n");
        }
    }

    return 1;
}
