/**
 * @file User.h
 * @brief Definición de la clase User para representar a un usuario de la biblioteca.
 * 
 * La clase User contiene información sobre un usuario, incluyendo su nombre,
 * ID y los materiales que ha prestado.
 */

#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include "MatBiblio.h"

/**
 * @class User
 * @brief Clase que representa un usuario de la biblioteca.
 * 
 * Esta clase almacena información del usuario, incluyendo su nombre, 
 * ID y un registro de los materiales que ha prestado.
 */
class User {
private:
    std::string nombre;              ///< Nombre del usuario.
    int id;                          ///< ID del usuario.
    MatBiblio* materialesPrestados[5]; ///< Array de materiales prestados por el usuario.

public:
    /**
     * @brief Constructor de la clase User.
     * 
     * @param nombre Nombre del usuario.
     * @param id ID del usuario.
     */
    User(std::string nombre, int id);

    /**
     * @brief Presta un material al usuario.
     * 
     * @param material Puntero al material que se va a prestar.
     */
    void prestarMaterial(MatBiblio* material);

    /**
     * @brief Devuelve un material prestado por el usuario.
     * 
     * @param material Puntero al material que se va a devolver.
     */
    void devolverMaterial(MatBiblio* material);

    /**
     * @brief Muestra todos los materiales que el usuario tiene prestados.
     */
    void mostrarMaterialesPrestados();

    /**
     * @brief Muestra el ISBN de los materiales prestados.
     * @return Cadena con los ISBN de los materiales prestados.
     */
    std::string mostrarIsbn();

    /**
     * @brief Obtiene el ID del usuario.
     * @return ID del usuario.
     */
    int getId() { return id; }

    /**
     * @brief Obtiene el nombre del usuario.
     * @return Nombre del usuario.
     */
    std::string getNombre() { return nombre; }

    /**
     * @brief Establece el ID del usuario.
     * 
     * @param id Nuevo ID del usuario.
     */
    void setId(int id);

    /**
     * @brief Establece el nombre del usuario.
     * 
     * @param nombre Nuevo nombre del usuario.
     */
    void setNombre(std::string nombre);

    /**
     * @brief Devuelve todos los materiales prestados al usuario.
     */
    void devolverMaterialesPrestados();

    /**
     * @brief Destructor de la clase User.
     */
    ~User();
};

#endif // USER_H