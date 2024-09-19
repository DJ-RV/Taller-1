#pragma once
#include "MaterialBibliografico.h"
#include <iostream>


class Libro: public MaterialBibliografico {
private:
    std::string fechaPublicación;
    std::string resumen;
public:
    Libro(std::string Name, int isbn, std::string Autor, bool leaned, std::string fechaPublicación, std::string resumen);
    std::string ShowInfo() override;
};