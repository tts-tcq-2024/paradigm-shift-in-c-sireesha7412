#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <stdio.h>

typedef enum {
    LANG_ENG, 
    LANG_GER,
    LANG_COUNT 
} Language;

typedef enum {
    MESSAGE_TEMPERATURE_OUT_OF_RANGE,
    MESSAGE_SOC_OUT_OF_RANGE,
    MESSAGE_CHARGE_RATE_OUT_OF_RANGE,
    MESSAGE_COUNT
} MessageType;

void setPreferredLanguage(int newLanguage); 
const char* getErrorMessage(Language lang, MessageType messageType);

