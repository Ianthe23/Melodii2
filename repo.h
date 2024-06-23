#pragma once

#include "domain.h"
#include "exceptions.h"

#include <fstream>

class Repo {
private:
	vector<Melodie> melodii;
	string path;
	void loadFile();
	void saveFile();
public:
	Repo(const string& p) : path(p) {
		loadFile();
	}

	Repo(Repo& other) = delete;

	void adaugaRepo(Melodie& melodie);
	void stergeRepo(const Melodie& melodie);

	vector<Melodie>& getAll() {
		return melodii;
	}
};