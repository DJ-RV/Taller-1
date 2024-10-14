#include "User.h"
#include <iostream>

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
    std::cout << "No se pudo prestar el material" << std::endl;
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

//devuelve los isbn de los materiales prestados en un formato para guardado en archivo txt
std::string User::mostrarIsbn() {
    std::string isbnData;
    for (int i = 0; i < 5; i++){
        if (materialesPrestados[i] != nullptr) {
            isbnData = isbnData + materialesPrestados[i]->getIsbn();
        } else { 
            isbnData = isbnData + "n"; 
        }

        if (i != 4){
            isbnData = isbnData + ";";
        }
    }
    return isbnData;
}

void User::setId(int id) {
    this -> id = id;
}

void User::setNombre(std::string nombre) {
    this -> nombre = nombre;
}

void User::devolverMaterialesPrestados() {
    for(int i = 0; i < 5; i++) {
        if (this -> materialesPrestados[i] != nullptr) {
            this -> materialesPrestados[i] -> setPrestado(false);
            this -> materialesPrestados[i] = nullptr;
        }
    }
}

User::~User() {
}