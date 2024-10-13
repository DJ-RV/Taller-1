#pragma once
#ifndef REVISTA_H
#define REVISTA_H
#include "MatBiblio.h"

class Revista : public MatBiblio
{
    private:
    std::string numeroEdicion;
    std::string mesPubli;
    public:
    Revista(std::string nombre, int isbn, std::string autor, std::string numeroEdicion, std::string mesPubli);
    void mostrarInformacion() const override;
    std::string extraData() const override;
    ~Revista() override;
};
#endif