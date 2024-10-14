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
    std::vector<User*> usuarios;
    static Sistema* instancia;
    int espacio = 0;
    // Patrón de diseño Singleton
    Sistema(); // Constructor privado

    public:
    static Sistema* getInstance();
    bool cargarMaterial(std::vector<std::string> datos);
    void cargarUsuarios(std::vector<std::string> datos);
    void prestarMaterial(std::string argumento, std::string nombreUsuario);
    void mostrarBiblioteca();
    void guardarDatos();
    void deleteBiblioteca();
    void mostrarMaterialUsuarios(std::string argumento);
    User* buscarUsuario(std::string argumento);
    MatBiblio* buscarMatBiblioObj(std::string argumento);
    void buscarMatBiblio(std::string argumento, int tipo);
    void devolverMaterial(std::string argumento, std::string nombreUsuario)
    void crearUsuario(std::string nombre, int id);
};

#endif