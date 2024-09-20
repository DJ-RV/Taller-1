#pragma once
#ifndef LIBRO_H
#define LIBRO_H
#include "MaterialBibliografico.h"
#include <iostream>

class Libro: public MaterialBibliografico {
private:
    std::string fechaPublicacion;
    std::string resumen;
public:
    Libro(std::string Name, int isbn, std::string Autor, int lendedId, std::string fechaPublicacion, std::string resumen);
    std::string ShowInfo() override;
};

#endif 