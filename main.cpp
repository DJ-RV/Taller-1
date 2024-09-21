#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "MaterialBibliografico.cpp"
#include "Libro.cpp"
#include "Revista.cpp"

using namespace std;

vector<string> split(const string& ding, char separador) {
    vector<string> resultado;
    stringstream ss(ding);
    string item;

    while (getline(ss, item, separador)) {
        resultado.push_back(item);
    }
    
    return resultado;
}

void leerArchivo(MaterialBibliografico* biblioteca[]) {

    ifstream arch("BibliotecaGuardada.txt");

    if (!arch.is_open()) {
        cout << "No habemos archivo" << endl;
        return;
    }

    int espacio = 0;
    string linea;

    while (getline(arch, linea) && espacio < 100) {
        MaterialBibliografico* lol = nullptr;
        vector<string> datos = split(linea, ';');
        if(datos[6] == "libro") {
            lol = new Libro(datos[0], stoi(datos[1]), datos[2], stoi(datos[3]), datos[4], datos[5]);
        } else {
            lol = new Revista(datos[0], stoi(datos[1]), datos[2], stoi(datos[3]), stoi(datos[4]), stoi(datos[5]));
        }
        biblioteca[espacio] = lol;
        espacio++;
    }

    arch.close();
}

void write() {

}

void agregarMaterial(int espacio) {
    if (espacio < 100) {
        int opcion;
        MaterialBibliografico* octavio;
        cout << "Elige tipo de material" << endl;
        cout << "1) Libro" << endl;
        cout << "2) Revista" << endl;
        cin >> opcion;
        switch(opcion) {
        case 1:
            string name;
            int isbn;
            string autor;
            int lendedId;
            string fechaPublicacion;
            string resumen;
            cout << "Indique nombre del libro" << endl;
            cin >> name;
            cout << "Indique ISBN" << endl;
            cin >> isbn;
            cout << "Indique autor del libro" << endl;
            cin >> autor;
            cout << "Indique ID del libro" << endl;
            cin >> lendedId;
            cout << "Indique fecha de publicacion" << endl;
            cin >> fechaPublicacion;
            cout << "Indique resumen" << endl;
            cin >> resumen;

            octavio = new Libro(name, isbn, autor, lendedId, fechaPublicacion, resumen);
            cout << "Libro agregado exitosamente" << endl;
        case 2:
            string name;
            int isbn;
            string autor;
            int lendedId;
            int numeroEdicion;
            int mesPublicacion;
            cout << "Indique nombre de la revista" << endl;
            cin >> name;
            cout << "Indique ISBN" << endl;
            cin >> isbn;
            cout << "Indique autor de la revista" << endl;
            cin >> autor;
            cout << "Indique ID de la revista" << endl;
            cin >> lendedId;
            cout << "Indique numero de edicion" << endl;
            cin >> fechaPublicacion;
            cout << "Indique mes de publicacion" << endl;
            cin >> resumen;

            octavio = new Revista(name, isbn, autor, lendedId, numeroEdicion, mesPublicacion);
            cout << "Revista agregada exitosamente" << endl;
        default:
            cout << "Opcion invalida, por favor reingrese" << endl;
        }   
    } else {
        cout << "No se puede añadir material debido a la falta de espacio" << endl;
    }
}

void mostrarInfo() {

}

void buscarMaterial() {

}

void prestarMaterial() {

}

void devolverMaterial() {

}

void menu() {
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
                agregarMaterial();
                break;
            case 2:
                mostrarInfo();
                break;
            case 3:
                buscarMaterial();
                break;
            case 4:
                prestarMaterial();
                break;
            case 5:
                devolverMaterial();
                break;
            case 6:
                write();
                break;
            default:
                cout << "Opcion invalida, por favor reingrese" << endl;
        }
    } while (opcion != 6);
}

int main() {
    MaterialBibliografico* biblioteca[100];
    leerArchivo(biblioteca);
    menu();
    // string ce = "EL,VICARIO,JOSE,LUIS,WEA";
    // char sep = ',';
    // vector<string> drb = split(ce, sep);
    // for (const std::string& parte : drb) {
        // cout << parte << endl;
    // }
    delete[] biblioteca;
    return 0;
}