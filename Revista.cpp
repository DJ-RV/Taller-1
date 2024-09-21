#include <iostream>
#include "Headers/Revista.h"

Revista::Revista(std::string nombre, int isbn, std::string autor, bool prestado, int numeroEdicion, int mesPubli)
    : MatBiblio(nombre, isbn, autor, prestado)
    {
        this -> numeroEdicion = numeroEdicion;
        this -> mesPubli = mesPubli;
    }

void Revista::mostrarInformacion() const
{
    std::cout << "datos" << std::endl;
}

Revista::~Revista() {
    std::cout << "Revista eliminada" << std::endl;
}