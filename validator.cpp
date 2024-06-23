#include "validator.h"

void Validator::valideazaId(int id) {
	if (id < 0) {
		throw ValidatorException("Id invalid!\n");
	}
}

void Validator::valideazaTitlu(const string& titlu) {
	if (titlu.empty()) {
		throw ValidatorException("Titlu invalid!\n");
	}
}

void Validator::valideazaArtist(const string& artist) {
	if (artist.empty()) {
		throw ValidatorException("Artist invalid!\n");
	}
}

void Validator::valideazaGen(const string& gen) {
	if (gen != "pop" && gen != "rock" && gen != "folk" && gen != "disco") {
		throw ValidatorException("Gen invalid!");
	}
}

void Validator::valideazaMelodia(const Melodie& melodie) {
	const int id = melodie.getId();
	const string& titlu = melodie.getTitlu();
	const string& artist = melodie.getArtist();
	const string& gen = melodie.getGen();
	string exceptii;

	try {
		valideazaId(id);
	}
	catch (ValidatorException& mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	try {
		valideazaTitlu(titlu);
	}
	catch (ValidatorException& mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	try {
		valideazaArtist(artist);
	}
	catch (ValidatorException& mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	try {
		valideazaGen(gen);
	}
	catch (ValidatorException& mesaj) {
		exceptii += mesaj.get_mesaj();
	}

	if (!exceptii.empty()) {
		throw ValidatorException(exceptii);
	}
}