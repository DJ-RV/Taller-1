#include "Headers/User.h"

User::User(std::string nombre, int id) {
    this -> nombre = nombre;
    this -> id = id;
}

void User::prestarMaterial(MatBiblio* material) {
    int i = 0;
    while(i < 5) {
        if (this -> materialesPrestados[i] == nullptr) {
            this -> materialesPrestados[i] = material;
            material -> setPrestado(true);
            return;
        }
        i++;
    }
}

void User::devolverMaterial(MatBiblio* material) {
    int i = 4;
    while (i > -1) {
        if (this -> materialesPrestados[i] == material) {
            this -> materialesPrestados[i] = nullptr;
            material -> setPrestado(false);
            return;
        }
        i--;
    }
}

void User::mostrarMaterialesPrestados() {
    for (int i = 0; i < 5; i++) {
        if (this -> materialesPrestados[i] != nullptr) {
            this -> materialesPrestados[i] -> mostrarInformacion();
        }
    }
}

void User::setId(int id) {
    this -> id = id;
}

void User::setNombre(std::string nombre) {
    this -> nombre = nombre;
}