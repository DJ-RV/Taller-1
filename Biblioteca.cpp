#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Sistema.h"

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
                sistema->mostrarBiblioteca();
                break;
            case 3:
                cout << "3" << endl;
                break;
            case 4:
                cout << "4" << endl;
                break;
            case 5:
                cout << "5" << endl;
                break;
            case 6:
            
                sistema->deleteBiblioteca();
                cout << "Saliendo" << endl;
                break;
            default:
                cout << "Opcion invalida, por favor reingrese" << endl;
        }
    } while (opcion != 6);
}

void agregarMaterial(Sistema* sistema) {
    string linea;
    vector<string> datos;
    int opcion;
    bool carga;
    do {
        cout << "Qué tipo de material desea agregar a la biblioteca?" << endl;
        cout << "1) Libro" << endl;
        cout << "2) Revista" << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese las especificaciones del material según el siguiente formato: 'Nombre,ISBN,Autor,FechaPublicacion,Resumen'" << endl;
                cin >> linea;
                datos = split(linea, ',');
                datos.push_back("libro");
                carga = sistema->cargarMaterial(datos);
                if (carga) {
                    cout << "Material añadido exitosamente" << endl;
                } else {
                    cout << "No se pudo agregar el material" << endl;
                }
                break;
            case 2:
                cout << "Ingrese las especificaciones del material según el siguiente formato: 'Nombre,ISBN,Autor,NumeroEdicion,MesPublicacion'" << endl;
                cin >> linea;
                datos = split(linea, ',');
                datos.push_back("revista");
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

}
void buscarMaterial(Sistema* sistema) {

}
void devolverMaterial(Sistema* sistema) {

}