#pragma once
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <string>
#include <iostream>

class MatBiblio {
    private:
        std::string nombre;
        int isbn;
        std::string autor;
        bool prestado;
    public:
        MatBiblio(std::string nombre, int isbn, std::string autor, bool prestado);
        virtual void mostrarInformacion();


        std::string getNombre();
        std::string getAutor();
};

#endif