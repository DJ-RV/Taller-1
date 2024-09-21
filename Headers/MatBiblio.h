#pragma once
#ifndef MATBIBLIO_H
#define MATBIBLIO_H
#include <string>

class MatBiblio 
{
    protected:
        std::string nombre;
        int isbn;
        std::string autor;
        bool prestado;
    public:
        MatBiblio(std::string nombre, int isbn, std::string autor, bool prestado);
        virtual void mostrarInformacion() const = 0;
        std::string getNombre();
        int getIsbn();
        std::string getAutor();
        bool getPrestado();
        void setPrestado(bool prestado);
        virtual ~MatBiblio() = 0;
};

#endif