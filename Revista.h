#pragma once
#include "MaterialBibliografico.h"
#include <iostream>


class Revista: public MaterialBibliografico {
private:
    int numeroEdicion;
    int mesPublicacion;
public:
    Revista(std::string Name, int isbn, std::string Autor, bool leaned, int numeroEdicion, int mesPublicacion);
    std::string ShowInfo() override;
};