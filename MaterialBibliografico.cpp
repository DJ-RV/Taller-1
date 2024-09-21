#include "Headers/MaterialBibliografico.h"

MatBiblio::MatBiblio(std::string nombre, int isbn, std::string autor, bool prestado) 
{
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = prestado;
}

std::string MatBiblio::getNombre()
{
    return this -> nombre;
}

std::string MatBiblio::getAutor()
{
    return this -> autor;
}