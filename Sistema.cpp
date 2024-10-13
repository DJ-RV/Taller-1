#include <string>
#include <vector>
#include "Sistema.h"
#include <fstream>


Sistema* Sistema::instancia = nullptr;

Sistema::Sistema() {}

Sistema* Sistema::getInstance() {
    if (instancia == nullptr) 
    {
        instancia = new Sistema();

        return instancia;
    }
    else
    {
        return instancia;
    }
}


bool Sistema::cargarMaterial(std::vector<std::string> datos) {
    MatBiblio* lol = nullptr;
    
    if(datos[6] == "libro") {
        lol = new Libro(datos[0], stoi(datos[1]), datos[2], datos[4], datos[5]);
    } else if (datos[6] == "revista") {
        lol = new Revista(datos[0], stoi(datos[1]), datos[2], datos[4], datos[5]);
    } else {
        return false;
    }

    if (espacio < 100) {
        this -> biblioteca[espacio] = lol;
        this -> espacio++;
        return true;
    } else {
        delete lol;
        return false;
    }
}

void Sistema::mostrarBiblioteca() {
    std::cout << "\n"; for (int i = 0; i < espacio; i++) { biblioteca[i] -> mostrarInformacion(); std::cout << "\n"; }
}

void Sistema::guardarDatos() {
    std::ofstream txtMaterial("BibliotecaGuardada.txt");
    for (int i = 0; i < espacio; i++) {
        txtMaterial << biblioteca[i]->getNombre() << ";" << biblioteca[i]->getIsbn() << ";" << biblioteca[i]->getAutor() << ";";
        if (biblioteca[i]->isPrestado() == true) {txtMaterial << "1";} else {txtMaterial << "0";} txtMaterial << ";";
        txtMaterial << biblioteca[i]->extraData();
        if (i != espacio - 1) {
            txtMaterial << "\n";
        }
    }
    
}

void Sistema::deleteBiblioteca() {
    for (int i = 0; i < espacio; i++) {
        delete biblioteca[i];
    }
}

void Sistema::buscarMatBiblio(std::string argumento, int tipo){
    int prints = 0;
    switch (tipo)
    {
    case 1:
        for (int i = 0; i < espacio; i++) {
            if (argumento == biblioteca[i]->getNombre()) {
                biblioteca[i]->mostrarInformacion();
                break;
            }
        }
        break;
    case 2:
        for (int i = 0; i < espacio; i++) {
            if (argumento == biblioteca[i]->getAutor()) {
                biblioteca[i]->mostrarInformacion();
                break;
            }
        }
        break;
    default:
        std::cout << "no se pudo encontrar material" << std::endl;
        break;
    }


}