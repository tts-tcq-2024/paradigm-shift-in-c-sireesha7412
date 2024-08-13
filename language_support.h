#ifndef LANG_H
#define LANG_H

#include <stdio.h>

// Enum for supported languages
typedef enum {
    LANG_ENG, 
    LANG_GER,
    LANG_COUNT 
} Language;

// Enum for message types
typedef enum {
    MESSAGE_TEMPERATURE_OUT_OF_RANGE,
    MESSAGE_SOC_OUT_OF_RANGE,
    MESSAGE_CHARGE_RATE_OUT_OF_RANGE,
    MESSAGE_COUNT
} MessageType;

// Function prototypes
void setPreferredLanguage(Language newLanguage); // Corrected spelling
const char* getErrorMessage(Language lang, MessageType messageType); // Unified error message function

#endif // LANG_H


