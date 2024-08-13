#include "language_support.h"
// Enum for message types
typedef enum {
    MESSAGE_TEMPERATURE_OUT_OF_RANGE,
    MESSAGE_SOC_OUT_OF_RANGE,
    MESSAGE_CHARGE_RATE_OUT_OF_RANGE,
    MESSAGE_COUNT
} MessageType;

const char* messages[LANG_COUNT][MESSAGE_COUNT] = {
    [LANG_ENG] = {
        "Temperature out of range!",
        "State of Charge out of range!",
        "Charge Rate out of range!"
    },
    [LANG_GER] = {
        "Temperatur außerhalb des Bereichs!",
        "Ladezustand außerhalb des Bereichs!",
        "Laderate außerhalb des zulässigen Bereichs!"
    }
};

const char* getErrorMessage(Language lang, MessageType messageType) {
    // Ensure the language and messageType are within valid bounds
    if (lang >= LANG_COUNT || messageType >= MESSAGE_COUNT) {
        return "Invalid language or message type!";
    }
    return messages[lang][messageType];
}
