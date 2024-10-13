#include <iostream>
#include "Libro.h"

Libro::Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPubli, std::string resumen)
    : MatBiblio(nombre, isbn, autor)
    {
        this -> fechaPubli = fechaPubli;
        this -> resumen = resumen;
    }

void Libro::mostrarInformacion() const
{
    std::cout << '"' << nombre << '"' << ":" << std::endl;
    std::cout << "isbn - " << isbn << "\n" << "autor - " << autor << "\n";
    std::cout << "prestado - "; if (prestado == true) {std::cout << "si";} else {std::cout << "no";} std::cout << "\n";
    std::cout << "Fecha de publicación - " << fechaPubli << "\n";
    std::cout << "resumen - " << resumen << "\n";
}

std::string Libro::extraData() const
{
    return fechaPubli + ";" + resumen + ";libro";
}


Libro::~Libro() {
    std::cout << "Libro eliminado" << std::endl;
}