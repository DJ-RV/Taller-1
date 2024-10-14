#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Sistema.h"
#include <climits>

using namespace std;


vector<string> split(const string& ding, char separador); //done
void leerArchivo(Sistema* sistema); //done
void leerArchivoUsuarios(Sistema* sistema); //done
void menu(Sistema* sistema); //done
void agregarMaterial(Sistema* sistema); //done
void mostrarInfo(Sistema* sistema); //done
void buscarMaterial(Sistema* sistema); //done
void prestarMaterial(Sistema* sistema); //done
void devolverMaterial(Sistema* sistema); // done
void gestionUsuarios(Sistema* sistema); // in process
void crearUsuario(Sistema* sistema); // done
void buscarUsuario(Sistema* sistema); // done
void eliminarUsuario(Sistema* sistema); // done


int main() {
    Sistema* sistema = Sistema::getInstance();
    leerArchivo(sistema);
    leerArchivoUsuarios(sistema);
    menu(sistema);
    return 0;
}

vector<string> split(const string& ding, char separador) {
    vector<string> resultado;
    stringstream ss(ding);
    string item;

    while (getline(ss, item, separador)) {
        resultado.push_back(item);
    }
    
    return resultado;
}

void leerArchivo(Sistema* sistema) {
    ifstream arch("BibliotecaGuardada.txt");

    if (!arch.is_open()) {
        cout << "Archivo no encontrado" << endl;
        return;
    }

    int espacio = 0;
    string linea;

    while (getline(arch, linea) && espacio < 100) {
        vector<string> datos = split(linea, ';');
        bool carga = sistema->cargarMaterial(datos);
        if (carga == false) {
            cout << "No se pueden cargar más datos" << endl;
        }
    }

    arch.close();
}

void leerArchivoUsuarios(Sistema* sistema) {
    ifstream uArch("UsuariosGuardados.txt");

    if (!uArch.is_open()) {
        cout << "Archivo no encontrado" << endl;
        return;
    }

    string linea;

    while(getline(uArch, linea)) {
        vector<string> datos = split(linea, ';');
        sistema ->cargarUsuarios(datos);
    }
}

void menu(Sistema* sistema) {
    int opcion;
    do {

        cout << "=====================" << endl;
        cout << "      BIBLIOTECA     " << endl;
        cout << "=====================" << endl;
        cout << "1) Agregar Material" << endl;
        cout << "2) Mostrar informacion de los materiales" << endl;
        cout << "3) Buscar Material" << endl;
        cout << "4) Prestar Material" << endl;
        cout << "5) Devolver Material" << endl;
        cout << "6) Gestionar Usuarios" << endl;
        cout << "7) Salir" << endl;

        cin >> opcion;
 
        switch(opcion) {
            case 1:
                agregarMaterial(sistema);
                break;
            case 2:
                mostrarInfo(sistema);
                break;
            case 3:
                buscarMaterial(sistema);
                break;
            case 4:
                prestarMaterial(sistema);
                break;
            case 5:
                devolverMaterial(sistema);
                break;
            case 6:
                gestionUsuarios(sistema);
                break;
            case 7:
                cout << "Guardando datos..." << endl;
                sistema->guardarDatos();
                cout << "Liberando memoria..." << endl;
                sistema->deleteBiblioteca();
                cout << "Cierre exitoso." << endl;
                break;
            default:
                cout << "Opcion invalida, por favor reingrese" << endl;
                break;
        }

    } while (opcion != 7);
}


void agregarMaterial(Sistema* sistema) {
    string linea;
    vector<string> datos;
    int opcion = 0;
    bool carga;
    do {
        cout << "Qué tipo de material desea agregar a la biblioteca?" << endl;
        cout << "1) Libro" << endl;
        cout << "2) Revista" << endl;

        cin.clear();
        cin >> opcion;
        cin.ignore(INT_MAX, '\n');

        switch(opcion) {
            case 1:
                cout << "Ingrese las especificaciones del material según el siguiente formato: 'Nombre;ISBN;Autor;FechaPublicacion;Resumen'" << endl;
                cout << "Ingrese la fecha en formato: 00-00-0000" << endl;
                getline(cin, linea);
                datos = split(linea, ';');
                datos.push_back("libro");
                datos[6] = datos[5], datos[5] = datos[4], datos[4] = datos[3], datos[3] = "0";
                carga = sistema->cargarMaterial(datos);
                if (carga) {
                    cout << "Material añadido exitosamente" << endl;
                } else {
                    cout << "No se pudo agregar el material" << endl;
                }
                break;
            case 2:
                cout << "Ingrese las especificaciones del material según el siguiente formato: 'Nombre;ISBN;Autor;NumeroEdicion;MesPublicacion'" << endl;
                getline(cin, linea);
                datos = split(linea, ';');
                datos.push_back("revista");
                datos.push_back("placeholder");
                datos[6] = datos[5], datos[5] = datos[4], datos[4] = datos[3], datos[3] = "0";
                carga = sistema->cargarMaterial(datos);
                if (carga) {
                    cout << "Material añadido exitosamente" << endl;
                } else {
                    cout << "No se pudo agregar el material" << endl;
                }
                break;
            default:
                cout << "Opcion invalida, por favor reingrese" << endl;
        }
    } while (opcion > 2 || opcion < 1);
}

void mostrarInfo(Sistema* sistema) {
    sistema->mostrarBiblioteca();
}

void buscarMaterial(Sistema* sistema) {
    int respuesta = 0;
    string argumento;
    while (respuesta > 2 || respuesta < 1 ) {
        argumento = "";
        respuesta = 0;
        cout << "Por que medio desea buscar:\n1) Nombre\n2) Autor" << endl;
        cin >> respuesta;
        cin.ignore(INT_MAX, '\n');
        switch(respuesta)
        {
            case 1:
                cout << "Ingrese el nombre del material" << endl;
                getline(cin, argumento);
                sistema->buscarMatBiblio(argumento, respuesta);
                break;
            case 2:
                cout << "Ingrese el autor del material" << endl;
                getline(cin, argumento);
                sistema->buscarMatBiblio(argumento, respuesta);
                break;
            default:
                cout << "Opcion invalida, por favor reingrese" << endl;
                break;
        }
    } 
}

void gestionUsuarios(Sistema* sistema) {
    int opcion = 0;
    do {
        cout << "Qué desea hacer?" << endl;
        cout << "1) Crear Usuario" << endl;
        cout << "2) Buscar Usuario" << endl;
        cout << "3) Eliminar Usuario" << endl;
        
        cin.clear();
        cin >> opcion;
        cin.ignore(INT_MAX, '\n');

        switch(opcion) {
            case 1:
                crearUsuario(sistema);
                break;
            case 2:
                buscarUsuario(sistema);
                break;
            case 3:
                eliminarUsuario(sistema);
                break;
            default:
                cout << "Opcion invalida, por favor reingrese" << endl;
                break;
        }
    } while (opcion < 0 || opcion > 3);
}


void prestarMaterial(Sistema* sistema) {
    string argumento;
    string nombreUsuario;
    cout << "indique el nombre del material a prestar" << endl;
    cin.ignore(INT_MAX, '\n');
    getline(cin, argumento);
    cout << "indique el nombre de a quien se le prestara el material" << endl;
    getline(cin, nombreUsuario);
    sistema->prestarMaterial(argumento, nombreUsuario);
}

void devolverMaterial(Sistema* sistema) {
    string argumento;
    string nombreUsuario;
    cout << "Indique el nombre del usuario que devolverá material" << endl;
    getline(cin, nombreUsuario);
    cout << "indique el nombre o ISBN del material a devolver" << endl;
    cin.ignore(INT_MAX, '\n');
    getline(cin, argumento);
    sistema->devolverMaterial(argumento, nombreUsuario);
}

void crearUsuario(Sistema* sistema) {
    string nombre;
    int id;
    cout << "Ingrese nombre del usuario" << endl;
    getline(cin, nombre);
    cout << "Ingrese ID del usuario" << endl;
    cin >> id;
    sistema->crearUsuario(nombre, id);
}

void buscarUsuario(Sistema* sistema) {
    string nombre;
    cout << "Ingrese el nombre del usuario a buscar" << "\n";
    getline(cin, nombre);
    User* user = sistema->buscarUsuario(nombre);
    if (user == nullptr) {
        cout << "Usuario no encontrado" << endl;
    } else {
        cout << user->getNombre() << " id: " << user->getId() << endl;
        user->mostrarMaterialesPrestados(); 
    }
}

void eliminarUsuario(Sistema* sistema) {
    string nombre;
    cout << "Ingrese nombre del usuario a eliminar" << endl;
    getline(cin, nombre);
    sistema->eliminarUsuario(nombre);
}