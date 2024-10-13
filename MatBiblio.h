#pragma once
#ifndef MATBIBLIO_H
#define MATBIBLIO_H
#include <string>

class MatBiblio 
{
    protected:
        std::string nombre;
        std::string isbn;
        std::string autor;
        bool prestado;
    public:
        MatBiblio(std::string nombre, std::string isbn, std::string autor);
        virtual void mostrarInformacion() const = 0;
        virtual std::string extraData() const = 0;
        std::string getNombre();
        std::string getIsbn();
        std::string getAutor();
        bool isPrestado();
        void setPrestado(bool prestado);
        virtual ~MatBiblio() = 0;
};

#endif