#include <iostream>
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
        vector<string> datos = split(linea, ',');
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

int main() {

    MaterialBibliografico* biblioteca[100];
    leerArchivo(Biblioteca);
    string ce = "EL,VICARIO,JOSE,LUIS,WEA";
    char sep = ',';
    vector<string> drb = split(ce, sep);
    for (const std::string& parte : drb) {
        cout << parte << endl;
    }
    return 0;
}