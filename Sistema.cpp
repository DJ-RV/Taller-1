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
        lol = new Libro(datos[0], datos[1], datos[2], datos[4], datos[5]);
    } else if (datos[6] == "revista") {
        lol = new Revista(datos[0], datos[1], datos[2], datos[4], datos[5]);
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

void Sistema::cargarUsuarios(std::vector<std::string> datos) {
    User* usuario = nullptr;
    MatBiblio* material = nullptr;
    usuario = new User(datos[0], stoi(datos[1]));
    for (int i = 2; i < 7; i++) {
        if (datos[i] != "n") {
            material = buscarMatBiblioObj(datos[i]);
            usuario->prestarMaterial(material);
        }
    }
    usuarios.push_back(usuario);
}

void Sistema::prestarMaterial(std::string argumento, std::string nombreUsuario) {
    User* usuario = buscarUsuario(nombreUsuario);
    MatBiblio* material = buscarMatBiblioObj(argumento);
    usuario->prestarMaterial(material);
}

void Sistema::mostrarMaterialUsuarios(std::string argumento){
    User* usuario = buscarUsuario(argumento);
    usuario->mostrarMaterialesPrestados();
}

void Sistema::mostrarBiblioteca() {
    std::cout << "\n"; for (int i = 0; i < espacio; i++) { biblioteca[i] -> mostrarInformacion(); std::cout << "\n"; }
}

void Sistema::guardarDatos() {
    std::ofstream txtUser("UsuariosGuardados.txt");
    for (int i = 0; i < usuarios.size(); i++) {
        txtUser << usuarios[i]->getNombre() << ";" << usuarios[i]->getId() << ";";
        txtUser << usuarios[i]->mostrarIsbn();
    }
    txtUser.close();

    std::ofstream txtMaterial("BibliotecaGuardada.txt");
    for (int i = 0; i < espacio; i++) {
        txtMaterial << biblioteca[i]->getNombre() << ";" << biblioteca[i]->getIsbn() << ";" << biblioteca[i]->getAutor() << ";";
        if (biblioteca[i]->isPrestado() == true) {txtMaterial << "1";} else {txtMaterial << "0";} txtMaterial << ";";
        txtMaterial << biblioteca[i]->extraData();
        if (i != espacio - 1) {
            txtMaterial << "\n";
        }
    }
    txtMaterial.close();
}

void Sistema::deleteBiblioteca() {
    for (int i = 0; i < espacio; i++) {
        delete biblioteca[i];
    }
}

User* Sistema::buscarUsuario(std::string argumento) {
    for (int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i]->getNombre() == argumento) {
            return usuarios[i];
        }
    }
    return nullptr;
}

//usa nombre o isbn para devolver el puntero de un material
MatBiblio* Sistema::buscarMatBiblioObj(std::string argumento) { 
    for (int i = 0; i < espacio; i++) {
        if (argumento == biblioteca[i]->getNombre() || argumento == biblioteca[i]->getIsbn()) {
            return biblioteca[i];
        }
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