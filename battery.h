#ifndef BATTERY_H
#define BATTERY_H

typedef int (*CheckFunc)(float, float*);

typedef struct {
    CheckFunc check;
    float value;
    float warningLevel;
    const char *message;
    const char *warningMessage;
} Check;

void printMessage(const char *message);
int isTemperatureInRange(float temperature, float* warningLevel);
int isSocInRange(float soc, float* warningLevel);
int isChargeRateInRange(float chargeRate, float* warningLevel);
int batteryIsOk(float temperature, float soc, float chargeRate);

#endif // BATTERY_H
