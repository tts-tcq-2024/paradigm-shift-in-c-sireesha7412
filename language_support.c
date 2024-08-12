#include "language_support.h"

const char* messages[LANG_COUNT][3] = {
    [LANG_ENG] = {
        "Temperature out of range!",
        "State of Charge out of range!",
        "Charge Rate out of range!"
    },
    [LANG_GER] = {
        "Temperatur außerhalb des Bereichs!",
        "Ladezustand außerhalb des Bereichs!",
        "Laderate außerhalb des zulässigen Bereichs!"
    },
    [LANG_SPA] = {
        "¡Temperatura fuera de rango!",
        "¡Estado de carga fuera de rango!",
        "¡Tasa de carga fuera de rango!"
    }
};

const char* getErrorMessage(Language lang, int messageType) {
    // Ensure the language and messageType are within valid bounds
    if (lang >= LANG_COUNT || messageType < 0 || messageType > 2) {
        return "Invalid language or message type!";
    }
    return messages[lang][messageType];
}

// Usage examples:
// const char* tempMessage = getErrorMessage(LANG_ENG, 0);
// const char* socMessage = getErrorMessage(LANG_GER, 1);
// const char* chargeRateMessage = getErrorMessage(LANG_SPA, 2);

