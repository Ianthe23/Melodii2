#pragma once

#include "domain.h"
#include "exceptions.h"

using std::string;

class Validator {
private:
	static void valideazaId(int id);

	static void valideazaTitlu(const string& titlu);

	static void valideazaArtist(const string& artist);

	static void valideazaGen(const string& gen);

public:
	static void valideazaMelodia(const Melodie& melodie);
};


