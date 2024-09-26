#include <iostream>
#include "Libro.h"

Libro::Libro(std::string nombre, int isbn, std::string autor, std::string fechaPubli, std::string resumen)
    : MatBiblio(nombre, isbn, autor)
    {
        this -> fechaPubli = fechaPubli;
        this -> resumen = resumen;
    }

void Libro::mostrarInformacion() const
{
    std::cout << "datos de libro: " << nombre << std::endl;
}

Libro::~Libro() {
    std::cout << "Libro eliminado" << std::endl;
}