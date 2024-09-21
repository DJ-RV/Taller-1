#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include "MatBiblio.h"

class User 
{
    private:
    std::string nombre;
    int id;
    MatBiblio* materialesPrestados[5];

    public:
    User(std::string nombre, int id);
    void prestarMaterial(MatBiblio* material);
    void devolverMaterial(MatBiblio* material);
    void mostrarMaterialesPrestados();
    int getId() {return id;}
    std::string getNombre() {return nombre;}
    void setId(int id);
    void setNombre(std::string nombre);
};
#endif