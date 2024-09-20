#include "User.h"
#include <iostream>
#include <string>

User::user(std::string nombre, int id)
    : nombre{nombre}
    , id{id} {
    }

void User::prestarMaterial(MaterialBibliografico* material) {
    int i = 0;
    while(i < 5) {
        if (materialesPrestados[i] == nullptr) {
            this -> materialesPrestados[i] = material;
            material -> lendedId = this -> id;
            return;
        }
        i++;
    }
}

void User::devolverMaterial(MaterialBibliografico* material) {
    int i = 4;
    while (i > -1) {
        if (materialesPrestados[i] == material) {
            this -> materialesPrestados[i] = nullptr;
            material -> lendedId = null;
            return;
        }
        i--;
    }
}

void User::mostrarMaterialesPrestados() {
    for (int i = 0; i < 5; i++) {
        std::cout << this -> materialesPrestados[i] << "\n";
    }
    std::cout << std:endl;
    return;
}

void User::setId(int id) {
    this -> id = id;
}

void User::setNombre(std::string nombre) {
    this -> nombre = nombre;
}