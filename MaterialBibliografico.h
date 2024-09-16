#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <iostream>

class MaterialBibliografico
{
private:
    std::string Name;
    int isbn;
    std::string Autor;
    int lended;
public:
    MaterialBibliografico();
    void ChangeStatus();
    void ShowInfo();
};

#endif