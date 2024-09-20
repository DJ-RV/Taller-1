#pragma once
#ifndef USER_H
#define USER_H
#include "MaterialBibliografico.h"
#include <string>

class User {
private:
    std::string nombre;
    int id;
    MaterialBibliografico* materialPrestado[5];
public:
    User(std::string nombre, int id);
    void prestarMaterial();
    void devolverMaterial();
    void mostrarMaterialesPrestados();
    int getId() {return id;}
    std::string getNombre() {return nombre;}
    void setId();
    void setNombre();
}

#endif