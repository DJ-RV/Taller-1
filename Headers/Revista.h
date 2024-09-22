#pragma once
#ifndef REVISTA_H
#define REVISTA_H
#include "MatBiblio.h"

class Revista : public MatBiblio
{
    private:
    int numeroEdicion;
    int mesPubli;
    public:
    Revista(std::string nombre, int isbn, std::string autor, int numeroEdicion, int mesPubli);
    void mostrarInformacion() const override;
    ~Revista() override;
};
#endif