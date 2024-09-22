#include <iostream>
#include "Headers/Revista.h"

Revista::Revista(std::string nombre, int isbn, std::string autor, int numeroEdicion, int mesPubli)
    : MatBiblio(nombre, isbn, autor)
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