#include <string>
#include "Headers/MatBiblio.h"

MatBiblio::MatBiblio(std::string nombre, int isbn, std::string autor) {
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
}

std::string MatBiblio::getNombre() {
    return this -> nombre;
}

int MatBiblio::getIsbn() {
    return this -> isbn;
}

std::string MatBiblio::getAutor() {
    return this -> autor;
}

bool MatBiblio::isPrestado() {
    return this -> prestado;
}
void MatBiblio::setPrestado(bool prestado) {
    this -> prestado = prestado;
}

MatBiblio::~MatBiblio() {}