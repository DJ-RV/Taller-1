/**
 * @file Libro.h
 * @brief Definición de la clase Libro, derivada de MatBiblio.
 * 
 * La clase Libro representa un libro en la biblioteca, incluyendo información 
 * específica como la fecha de publicación y el resumen.
 */

#pragma once
#ifndef LIBRO_H
#define LIBRO_H

#include "MatBiblio.h"

/**
 * @class Libro
 * @brief Clase que representa un libro, heredando de MatBiblio.
 * 
 * Esta clase contiene información adicional específica para libros, 
 * como la fecha de publicación y un resumen.
 */
class Libro : public MatBiblio {
private:
    std::string fechaPubli; ///< Fecha de publicación del libro.
    std::string resumen;     ///< Resumen del contenido del libro.

public:
    /**
     * @brief Constructor de la clase Libro.
     * 
     * @param nombre Nombre del libro.
     * @param isbn ISBN del libro.
     * @param autor Autor del libro.
     * @param fechaPubli Fecha de publicación del libro.
     * @param resumen Resumen del contenido del libro.
     */
    Libro(std::string nombre, std::string isbn, std::string autor, 
          std::string fechaPubli, std::string resumen);

    /**
     * @brief Muestra la información detallada del libro.
     * 
     * Sobrescribe el método virtual de la clase base MatBiblio.
     */
    void mostrarInformacion() const override;

    /**
     * @brief Devuelve información adicional específica del libro.
     * @return Cadena con los datos extra del libro.
     */
    std::string extraData() const override;

    /**
     * @brief Destructor de la clase Libro.
     */
    ~Libro() override;
};

#endif // LIBRO_H