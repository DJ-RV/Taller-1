/**
 * @file Sistema.h
 * @brief Definición de la clase Sistema que gestiona los materiales y usuarios de la biblioteca.
 * 
 * La clase Sistema implementa el patrón Singleton para asegurar que solo haya una instancia del sistema
 * en ejecución. Permite la gestión de libros, revistas y usuarios, así como la administración de préstamos y devoluciones.
 */

#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>
#include "MatBiblio.h"
#include "Libro.h"
#include "Revista.h"
#include "User.h"

/**
 * @class Sistema
 * @brief Clase que representa el sistema de gestión de la biblioteca.
 * 
 * Gestiona los materiales disponibles y los usuarios registrados, permitiendo
 * realizar préstamos, devoluciones, y consultas sobre el estado de la biblioteca.
 */
class Sistema {
private:
    MatBiblio* biblioteca[100];  ///< Array que almacena los materiales de la biblioteca.
    std::vector<User*> usuarios; ///< Vector que almacena los usuarios registrados.
    static Sistema* instancia;   ///< Instancia única del sistema (patrón Singleton).
    int espacio = 0;             ///< Espacio disponible en la biblioteca.

    /**
     * @brief Constructor privado para implementar el patrón Singleton.
     */
    Sistema();

public:
    /**
     * @brief Obtiene la instancia única del sistema.
     * @return Puntero a la instancia única del sistema.
     */
    static Sistema* getInstance();

    /**
     * @brief Carga un material en la biblioteca a partir de datos proporcionados.
     * @param datos Vector de cadenas con la información del material.
     * @return `true` si el material se carga exitosamente, `false` si no hay espacio.
     */
    bool cargarMaterial(std::vector<std::string> datos);

    /**
     * @brief Carga un usuario en el sistema a partir de datos proporcionados.
     * @param datos Vector de cadenas con la información del usuario.
     */
    void cargarUsuarios(std::vector<std::string> datos);

    /**
     * @brief Registra el préstamo de un material a un usuario.
     * @param argumento Nombre o ISBN del material a prestar.
     * @param nombreUsuario Nombre del usuario al que se presta el material.
     */
    void prestarMaterial(std::string argumento, std::string nombreUsuario);

    /**
     * @brief Muestra la información de todos los materiales en la biblioteca.
     */
    void mostrarBiblioteca();

    /**
     * @brief Guarda los datos de la biblioteca y los usuarios en archivos.
     */
    void guardarDatos();

    /**
     * @brief Libera la memoria ocupada por los materiales en la biblioteca.
     */
    void deleteBiblioteca();

    /**
     * @brief Muestra los materiales prestados por un usuario específico.
     * @param argumento Nombre del usuario cuyos materiales se desean ver.
     */
    void mostrarMaterialUsuarios(std::string argumento);

    /**
     * @brief Busca un usuario por su nombre.
     * @param argumento Nombre del usuario a buscar.
     * @return Puntero al usuario encontrado, o `nullptr` si no se encuentra.
     */
    User* buscarUsuario(std::string argumento);

    /**
     * @brief Busca un material en la biblioteca y devuelve su puntero.
     * @param argumento Nombre o ISBN del material a buscar.
     * @return Puntero al material encontrado, o `nullptr` si no se encuentra.
     */
    MatBiblio* buscarMatBiblioObj(std::string argumento);

    /**
     * @brief Realiza una búsqueda de materiales por nombre o autor.
     * @param argumento Criterio de búsqueda.
     * @param tipo Tipo de búsqueda: 1 para nombre, 2 para autor.
     */
    void buscarMatBiblio(std::string argumento, int tipo);

    /**
     * @brief Registra la devolución de un material por parte de un usuario.
     * @param argumento Nombre o ISBN del material a devolver.
     * @param nombreUsuario Nombre del usuario que devuelve el material.
     */
    void devolverMaterial(std::string argumento, std::string nombreUsuario);

    /**
     * @brief Crea un nuevo usuario en el sistema.
     * @param nombre Nombre del nuevo usuario.
     * @param id ID del nuevo usuario.
     */
    void crearUsuario(std::string nombre, int id);

    /**
     * @brief Elimina un usuario del sistema.
     * @param nombre Nombre del usuario a eliminar.
     */
    void eliminarUsuario(std::string nombre);
};

#endif // SISTEMA_H