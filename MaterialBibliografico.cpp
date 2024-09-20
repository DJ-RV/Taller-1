#include "MaterialBibliografico.h"
#include <string>

MaterialBibliografico::MaterialBibliografico
    (std::string Name, int isbn, std::string Autor, int lendedId)
		: Name{Name}
        , isbn{isbn}
		, Autor{Autor}
		, lendedId{lendedId} {
	}

void MaterialBibliografico::SetLendedId(int nlendedId) {
    lendedId = nlendedId;
}