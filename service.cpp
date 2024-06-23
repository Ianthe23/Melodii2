#include "service.h"

void Service::adauga(const string& titlu, const string& artist, const string& gen) {
	Melodie melodie{ 0, titlu, artist, gen };
	validator.valideazaMelodia(melodie);

	repo.adaugaRepo(melodie);
}

void Service::sterge(int id) {
	for (const auto& m : getMelodii()) {
		if (m.getId() == id) {
			repo.stergeRepo(m);
		}
	}
}

map<string, int> Service::frecvente_autor() {
	map<string, int> frecv;
	for (auto& m : getMelodii()) {
		if (frecv.find(m.getArtist()) == frecv.end()) {
			frecv[m.getArtist()] = 1;
		}
		else {
			frecv[m.getArtist()]++;
		}
	}
	return frecv;
}

map<string, int> Service::frecvente_gen() {
	map<string, int> frecv;
	for (auto& m : getMelodii()) {
		if (frecv.find(m.getGen()) == frecv.end()) {
			frecv[m.getGen()] = 1;
		}
		else {
			frecv[m.getGen()]++;
		}
	}
	return frecv;
}