/**
 * @file Revista.h
 * @brief Definición de la clase Revista, derivada de MatBiblio.
 * 
 * La clase Revista representa una revista en la biblioteca, almacenando información 
 * específica como el número de edición y el mes de publicación.
 */

#pragma once
#ifndef REVISTA_H
#define REVISTA_H

#include "MatBiblio.h"

/**
 * @class Revista
 * @brief Clase que representa una revista, heredando de MatBiblio.
 * 
 * Esta clase contiene información adicional específica para revistas, 
 * como el número de edición y el mes de publicación.
 */
class Revista : public MatBiblio {
private:
    std::string numeroEdicion; ///< Número de edición de la revista.
    std::string mesPubli;      ///< Mes de publicación de la revista.

public:
    /**
     * @brief Constructor de la clase Revista.
     * 
     * @param nombre Nombre de la revista.
     * @param isbn ISBN de la revista.
     * @param autor Autor o editor de la revista.
     * @param numeroEdicion Número de la edición.
     * @param mesPubli Mes de publicación.
     */
    Revista(std::string nombre, std::string isbn, std::string autor, 
            std::string numeroEdicion, std::string mesPubli);

    /**
     * @brief Muestra la información detallada de la revista.
     * 
     * Sobrescribe el método virtual de la clase base MatBiblio.
     */
    void mostrarInformacion() const override;

    /**
     * @brief Devuelve información adicional específica de la revista.
     * @return Cadena con los datos extra de la revista.
     */
    std::string extraData() const override;

    /**
     * @brief Destructor de la clase Revista.
     */
    ~Revista() override;
};

#endif // REVISTA_H