#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <vector>
#include "MatBiblio.h"
#include "Libro.h"
#include "Revista.h"
#include "User.h"

class Sistema 
{
    private:
    MatBiblio* biblioteca[100];
    // Patrón de diseño Singleton
    Sistema(); // Constructor privado
    Sistema(const Sistema&) = delete;            // Prohíbe la copia
    Sistema& operator=(const Sistema&) = delete; // Prohíbe la asignación

    public:
    static Sistema& getInstance();
    std::string testPalRV();
};

#endif