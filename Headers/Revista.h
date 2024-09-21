#pragma once
#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"

class Revista : public MatBiblio
{
    private:
    int numeroEdicion;
    int mesPubli;
    public:
    Revista(std::string nombre, int isbn, std::string autor, bool prestado, int numeroEdicion, int mesPubli);
    void mostrarInformacion() override;
};
#endif