#include "MaterialBibliografico.h"
#include <string>

MaterialBibliografico::MaterialBibliografico
    (std::string Name, int isbn, std::string Autor, int lendedId)
		: Name{Name}
        , isbn{isbn}
		, Autor{Autor}
		, lendedId{lendedId} {
	}

void MaterialBibliografico::setLendedId(int nlendedId) {
    lendedId = nlendedId;
}