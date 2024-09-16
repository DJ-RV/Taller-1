#include "MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico
    (std::string Name, int isbn, std::string Autor, bool lended)
		: Name{Name}
        , isbn{isbn}
		, Autor{Autor}
		, lended{lended} {
	}

void MaterialBibliografico::ChangeStatus()
	{
  		if (lended == 1) { lended = 0; }
        else if (lended == 0) { lended = 1; }
	}