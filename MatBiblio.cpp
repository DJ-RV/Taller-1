#include <string>
#include "Headers/MatBiblio.h"

MatBiblio::MatBiblio(std::string nombre, int isbn, std::string autor, bool prestado) {
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = prestado;
}

void MatBiblio::setPrestado(bool prestado) {
    this -> prestado = prestado;
}

MatBiblio::~MatBiblio() {}