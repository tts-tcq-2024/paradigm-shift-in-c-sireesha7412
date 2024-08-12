#include "battery_check.h"
#include "language_support.h"

#define MIN_TEMPERATURE 0.0
#define MAX_TEMPERATURE 45.0
#define MIN_SOC 20.0
#define MAX_SOC 80.0
#define MAX_CHARGE_RATE 0.8

typedef enum {
    TEMPERATURE_OUT_OF_RANGE,
    SOC_OUT_OF_RANGE,
    CHARGE_RATE_OUT_OF_RANGE
} MessageType;

int checkParameter(float value, float min, float max, MessageType messageType, Language lang) {
    if (value < min || value > max) {
        printf("%s\n", getErrorMessage(lang, messageType));
        return 0; // Not okay
    }
    return 1; // Okay
}

int isTemperatureOk(float temperature, Language lang) {
    return checkParameter(temperature, MIN_TEMPERATURE, MAX_TEMPERATURE, TEMPERATURE_OUT_OF_RANGE, lang);
}

int isSocOk(float soc, Language lang) {
    return checkParameter(soc, MIN_SOC, MAX_SOC, SOC_OUT_OF_RANGE, lang);
}

int isChargeRateOk(float chargeRate, Language lang) {
    return checkParameter(chargeRate, 0.0, MAX_CHARGE_RATE, CHARGE_RATE_OUT_OF_RANGE, lang);
}

int batteryIsOk(float temperature, float soc, float chargeRate, Language lang) {
    return isTemperatureOk(temperature, lang) &&
           isSocOk(soc, lang) &&
           isChargeRateOk(chargeRate, lang);
}

