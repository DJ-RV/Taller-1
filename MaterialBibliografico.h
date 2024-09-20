#pragma once
#include <iostream>

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

    int GetLendedId() {return lendedId;}
    void SetLendedId(int nlendedId);
};


