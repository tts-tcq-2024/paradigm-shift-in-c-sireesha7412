#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include "language_support.h" 
int batteryIsOk(float temperature, float soc, float chargeRate);
void setPreferredLanguage(Language newLanguage); // Corrected spelling

#endif // BATTERY_CHECK_H

