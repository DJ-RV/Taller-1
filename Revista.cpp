#include "Revista.h"

Revista::Revista(std::string Name, int isbn, std::string Autor, bool leaned, int numeroEdicion, int mesPublicacion)
    : MaterialBibliografico(Name, isbn, Autor, leaned)
    , numeroEdicion{numeroEdicion} 
    , mesPublicacion{mesPublicacion}{
	}

std::string Revista::ShowInfo() {
    return "ola soi una rebista ";
}