#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Sistema.h"
#include <climits>

using namespace std;


vector<string> split(const string& ding, char separador);
void leerArchivo(Sistema* sistema); //done
void menu(Sistema* sistema); //
void agregarMaterial(Sistema* sistema); //done
void mostrarInfo(Sistema* sistema); //done
void buscarMaterial(Sistema* sistema);
void prestarMaterial(Sistema* sistema);
void devolverMaterial(Sistema* sistema);
void gestionUsuarios(Sistema* sistema);


int main() {
    Sistema* sistema = Sistema::getInstance();
    leerArchivo(sistema);
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
        cout << "6) Salir" << endl;

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
                cout << "4" << endl;
                break;
            case 5:
                cout << "5" << endl;
                break;
            case 6:
                sistema->guardarDatos();
                sistema->deleteBiblioteca();
                cout << "Saliendo" << endl;
                break;
            default:
                cout << "Opcion invalida, por favor reingrese" << endl;
                break;
        }

    } while (opcion != 6);
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
void devolverMaterial(Sistema* sistema) {

}