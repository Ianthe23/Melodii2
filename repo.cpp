#include "repo.h"

#include <cstdlib>
#include <ctime>

void Repo::loadFile() {
	ifstream f(path);
	Melodie melodie{};

	while (f >> melodie) {
		melodii.push_back(melodie);
	}
	f.close();
}

void Repo::saveFile() {
	ofstream g(path);

	for (const auto& melodie : melodii) {
		g << melodie;
	}

	g.close();
}

void Repo::adaugaRepo(Melodie& melodie) {
	srand(time(0));
	int id = rand() % 10000;
	for (const auto& m : melodii) {
		if (m.getId() == id) {
			throw RepoException("Id-ul acesta deja exista!\n");
		}
	}
	melodie.setId(id);
	melodii.push_back(melodie);
	saveFile();
}

void Repo::stergeRepo(const Melodie& melodie) {
	auto it = find(melodii.begin(), melodii.end(), melodie);
	if (it != melodii.end()) {
		melodii.erase(it);
		saveFile();
	}
	else {
		throw RepoException("Melodia nu exista!\n");
	}


}