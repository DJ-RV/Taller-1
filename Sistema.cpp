#include <string>
#include <vector>
#include "Sistema.h"


Sistema* Sistema::instancia = nullptr;

Sistema::Sistema() {}

Sistema* Sistema::getInstance() {
    if (instancia == nullptr) 
    {
        instancia = new Sistema();

        return instancia;
    }
    else
    {
        return instancia;
    }
}


bool Sistema::cargarMaterial(std::vector<std::string> datos) {
    MatBiblio* lol = nullptr;
    if(datos[6] == "libro") {
        lol = new Libro(datos[0], stoi(datos[1]), datos[2], datos[3], datos[4]);
    } else if (datos[6] == "revista") {
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

void Sistema::mostrarBiblioteca() {
    for (int i = 0; i < espacio; i++) {
        biblioteca[i] -> mostrarInformacion();
    }
}

void Sistema::deleteBiblioteca() {
    for (int i = 0; i < espacio; i++) {
        delete biblioteca[i];
    }
}