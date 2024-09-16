#pragma once
#include <iostream>

class MaterialBibliografico {
private:
    std::string Name;
    int isbn;
    std::string Autor;
    bool lended;
public:
    MaterialBibliografico(std::string Name, int isbn, std::string Autor, bool leaned);
    void ChangeStatus();
    void ShowInfo();
};


