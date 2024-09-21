#include "Headers/Revista.h"

Revista::Revista(std::string nombre, int isbn, std::string autor, bool prestado, int numeroEdicion, int mesPubli)
    : MatBiblio(nombre, isbn, autor, prestado)
    {
        this -> numeroEdicion = numeroEdicion;
        this -> mesPubli = mesPubli;
    }

void Revista::mostrarInformacion()
{
    std::cout << "datos" << std::endl;
}