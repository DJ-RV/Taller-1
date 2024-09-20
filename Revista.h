#pragma once
#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"
#include <string>


class Revista: public MaterialBibliografico {
private:
    int numeroEdicion;
    int mesPublicacion;
public:
    Revista(std::string Name, int isbn, std::string Autor, int lendedId, int numeroEdicion, int mesPublicacion);
    std::string ShowInfo() override;
};

#endif