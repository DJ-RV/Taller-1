#include "Headers/Sistema.h"
#include <iostream>

Sistema::Sistema() {}

Sistema& Sistema::getInstance() {
    static Sistema instance; // Se crea una vez
    return instance;
}

std::string Sistema::testPalRV() {
    return "habemos un sistema funcional";
}