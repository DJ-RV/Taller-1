#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <vector>
#include "MatBiblio.h"
#include "Libro.h"
#include "Revista.h"
#include "User.h"

class Sistema 
{
    private:
    MatBiblio* biblioteca[100];
    std::vector<User> usuarios;
    static Sistema* instancia;
    int espacio = 0;
    // Patrón de diseño Singleton
    Sistema(); // Constructor privado

    public:
    static Sistema* getInstance();
    bool cargarMaterial(std::vector<std::string> datos);
    void mostrarBiblioteca();
    void deleteBiblioteca();
};

#endif