/**
 * @file MatBiblio.h
 * @brief Definición de la clase base MatBiblio para los materiales de la biblioteca.
 * 
 * La clase MatBiblio proporciona la interfaz y atributos comunes para todos los 
 * tipos de materiales (libros, revistas, etc.) en la biblioteca.
 */

#pragma once
#ifndef MATBIBLIO_H
#define MATBIBLIO_H

#include <string>

/**
 * @class MatBiblio
 * @brief Clase abstracta que representa un material de biblioteca.
 * 
 * Esta clase define los atributos comunes y los métodos virtuales que deben 
 * ser implementados por las clases derivadas, como Libro y Revista.
 */
class MatBiblio {
protected:
    std::string nombre; ///< Nombre del material.
    std::string isbn;   ///< ISBN del material.
    std::string autor;  ///< Autor del material.
    bool prestado;      ///< Estado de préstamo del material.

public:
    /**
     * @brief Constructor de la clase MatBiblio.
     * 
     * @param nombre Nombre del material.
     * @param isbn ISBN del material.
     * @param autor Autor del material.
     */
    MatBiblio(std::string nombre, std::string isbn, std::string autor);

    /**
     * @brief Método virtual puro para mostrar información del material.
     * 
     * Este método debe ser implementado por las clases derivadas.
     */
    virtual void mostrarInformacion() const = 0;

    /**
     * @brief Método virtual puro que retorna información adicional del material.
     * 
     * Este método debe ser implementado por las clases derivadas.
     * @return Cadena con datos adicionales específicos del material.
     */
    virtual std::string extraData() const = 0;

    /**
     * @brief Obtiene el nombre del material.
     * @return Cadena con el nombre del material.
     */
    std::string getNombre();

    /**
     * @brief Obtiene el ISBN del material.
     * @return Cadena con el ISBN del material.
     */
    std::string getIsbn();

    /**
     * @brief Obtiene el autor del material.
     * @return Cadena con el autor del material.
     */
    std::string getAutor();

    /**
     * @brief Verifica si el material está prestado.
     * @return `true` si está prestado, `false` en caso contrario.
     */
    bool isPrestado();

    /**
     * @brief Establece el estado de préstamo del material.
     * @param prestado `true` para marcar como prestado, `false` para marcar como disponible.
     */
    void setPrestado(bool prestado);

    /**
     * @brief Destructor virtual de la clase MatBiblio.
     * 
     * Es virtual y puro para permitir la correcta eliminación de clases derivadas.
     */
    virtual ~MatBiblio() = 0;
};

#endif // MATBIBLIO_H