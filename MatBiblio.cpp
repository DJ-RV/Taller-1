#include <string>
#include "MatBiblio.h"

MatBiblio::MatBiblio(std::string nombre, std::string isbn, std::string autor) {
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
}

std::string MatBiblio::getNombre() {
    return this -> nombre;
}

std::string MatBiblio::getIsbn() {
    return this -> isbn;
}

std::string MatBiblio::getAutor() {
    return this -> autor;
}

bool MatBiblio::isPrestado() {
    return this -> prestado;
}
void MatBiblio::setPrestado(bool status) {
    prestado = status;
}

MatBiblio::~MatBiblio() {}