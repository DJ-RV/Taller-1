#include "Headers/Libro.h"

Libro::Libro(std::string nombre, int isbn, std::string autor, bool prestado, std::string fechaPubli, std::string resumen)
    : MatBiblio(nombre, isbn, autor, prestado)
    {
        this -> fechaPubli = fechaPubli;
        this -> resumen = resumen;
    }

void Libro::mostrarInformacion()
{
    std::cout << "datos" << std::endl;
}