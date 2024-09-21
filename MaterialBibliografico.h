#pragma once
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <string>

class MaterialBibliografico {
protected:
    std::string Name;
    int isbn;
    std::string Autor;
    int lendedId;
public:
    MaterialBibliografico(std::string Name, int isbn, std::string Autor, int lendedId);
    void ChangeStatus();
    virtual std::string ShowInfo();
    int getLendedId() {return lendedId;}
    void setLendedId(int nlendedId);
};

#endif