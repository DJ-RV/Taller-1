#pragma once
#ifndef LIBRO_H
#define LIBRO_H
#include "MatBiblio.h"

class Libro : public MatBiblio
{
    private:
    std::string fechaPubli;
    std::string resumen;
    public:
    Libro(std::string nombre, int isbn, std::string autor, std::string fechaPubli, std::string resumen);
    void mostrarInformacion() const override;
    std::string extraData() const override;
    ~Libro() override;
};
#endif