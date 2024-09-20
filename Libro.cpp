#include "Libro.h"
#include <string>

Libro::Libro(std::string Name, int isbn, std::string Autor, int lendedId, std::string fechaPublicacion, std::string resumen)
    : MaterialBibliografico(Name, isbn, Autor, lendedId)
    , fechaPublicacion{fechaPublicacion} 
    , resumen{resumen}{
	}

std::string Libro::ShowInfo() {
    return "ola soi bisente octavio " + resumen;
}
