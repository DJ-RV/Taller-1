#include "Revista.h"
#include <string>

Revista::Revista(std::string Name, int isbn, std::string Autor, int lendedId, int numeroEdicion, int mesPublicacion)
    : MaterialBibliografico(Name, isbn, Autor, lendedId)
    , numeroEdicion{numeroEdicion} 
    , mesPublicacion{mesPublicacion}{
	}

std::string Revista::ShowInfo() {
    return "ola soi una rebista ";
}