#include "Libro.h"

Libro::Libro(std::string Name, int isbn, std::string Autor, int lendedId, std::string fechaPublicación, std::string resumen)
    : MaterialBibliografico(Name, isbn, Autor, lendedId)
    , fechaPublicación{fechaPublicación} 
    , resumen{resumen}{
	}

std::string Libro::ShowInfo() {
    return "ola soi bisente octavio " + resumen;
}
