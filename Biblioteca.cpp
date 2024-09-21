#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Headers/Sistema.h"

using namespace std;

vector<string> split(const string& ding, char separador);
void leerArchivo();
void menu();

int main() {
    Sistema& sistema = Sistema::getInstance();
    cout << sistema.testPalRV() << endl;
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

void leerArchivo() {

}

void menu() {

}