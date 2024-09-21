#include "Headers/MaterialBibliografico.h"


MatBiblio::MatBiblio(std::string nombre, int isbn, std::string autor, bool prestado) 
{
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = prestado;
}

void MatBiblio::mostrarInformacion()
{
    std::cout << "datos" << std::endl;
}

std::string MatBiblio::getNombre()
{
    return this -> nombre;
}

std::string MatBiblio::getAutor()
{
    return this -> autor;
}