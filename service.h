#pragma once

#include "validator.h"
#include "repo.h"

#include <map>

using std::map;

class Service {
private:
	Repo& repo;
	Validator validator;

public:
	Service(Repo& r, Validator& v) : repo(r), validator(v) {

	};

	Service(Service& other) = delete;

	vector<Melodie>& getMelodii() {
		return this->repo.getAll();
	}

	void adauga(const string& titlu, const string& artist, const string& gen);
	void sterge(int id);

	map<string, int> frecvente_autor();
	map<string, int> frecvente_gen();
};