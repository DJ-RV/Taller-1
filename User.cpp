#include "User.h"
#include <iostream>
#include <string>

User::User(std::string nombre, int id)
    : nombre{nombre}
    , id{id} {
    }

void User::prestarMaterial(MaterialBibliografico* material) {
    int i = 0;
    while(i < 5) {
        if (this -> materialesPrestados[i] == nullptr) {
            this -> materialesPrestados[i] = material;
            material -> setLendedId(this -> id);
            return;
        }
        i++;
    }
}

void User::devolverMaterial(MaterialBibliografico* material) {
    int i = 4;
    while (i > -1) {
        if (this -> materialesPrestados[i] == material) {
            this -> materialesPrestados[i] = nullptr;
            material -> setLendedId(-1);
            return;
        }
        i--;
    }
}

void User::mostrarMaterialesPrestados() {
    for (int i = 0; i < 5; i++) {
        if (this->materialesPrestados[i] != nullptr) {
            std::cout << this -> materialesPrestados[i] -> ShowInfo() << "\n";
        }
    }
    std::cout << std::endl;
}

void User::setId(int id) {
    this -> id = id;
}

void User::setNombre(std::string nombre) {
    this -> nombre = nombre;
}