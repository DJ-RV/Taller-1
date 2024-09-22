#include "Headers/Sistema.h"
#include <string>
#include <vector>

Sistema::Sistema() {}

Sistema& Sistema::getInstance() {
    static Sistema instance; // Se crea una vez
    return instance;
}

bool Sistema::cargarMaterial(std::vector<std::string> datos) {
    MatBiblio* lol = nullptr;
    if(datos[5] == "libro") {
        lol = new Libro(datos[0], stoi(datos[1]), datos[2], datos[3], datos[4]);
    } else if (datos[5] == "revista") {
        lol = new Revista(datos[0], stoi(datos[1]), datos[2], stoi(datos[3]), stoi(datos[4]));
    } else {
        return false;
    }
    if (espacio < 100) {
        this -> biblioteca[espacio] = lol;
        this -> espacio++;
        return true;
    } else {
        delete lol;
        return false;
    }
}