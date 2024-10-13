#include <iostream>
#include "Revista.h"

Revista::Revista(std::string nombre, int isbn, std::string autor, std::string numeroEdicion, std::string mesPubli)
    : MatBiblio(nombre, isbn, autor)
    {
        this -> numeroEdicion = numeroEdicion;
        this -> mesPubli = mesPubli;
    }

void Revista::mostrarInformacion() const
{
    std::cout << '"' << nombre << '"' << ":" << std::endl;
    std::cout << "isbn - " << isbn << "\n" << "autor - " << autor << "\n";
    std::cout << "prestado - "; if (prestado == true) {std::cout << "si";} else {std::cout << "no";} std::cout << "\n";
    std::cout << "Numero de edicion - " << numeroEdicion << "\n";
    std::cout << "Mes de Publicación - " << mesPubli << "\n";
}

std::string Revista::extraData() const
{
    return numeroEdicion + ";" + mesPubli + ";revista";
}

Revista::~Revista() {
    std::cout << "Revista eliminada" << std::endl;
}