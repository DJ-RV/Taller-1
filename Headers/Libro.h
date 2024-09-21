#pragma once
#include "MaterialBibliografico.h"

class Libro : public MatBiblio
{
    private:
    std::string fechaPubli;
    std::string resumen;
    public:
    Libro(std::string nombre, int isbn, std::string autor, bool prestado, std::string fechaPubli, std::string resumen);
    void mostrarInformacion() override;
};