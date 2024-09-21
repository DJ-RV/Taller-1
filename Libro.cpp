#include "Headers/Libro.h"

Libro::Libro(std::string nombre, int isbn, std::string autor, bool prestado, std::string fechaPubli, std::string resumen)
    : MatBiblio(nombre, isbn, autor, prestado)
{
    
}