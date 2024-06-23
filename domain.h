#pragma once

#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> splitLine(const string& linie, char delimitator);

class Melodie {
private:
	int id;
	string titlu;
	string artist;
	string gen;
public:
	Melodie() {
		id = -1;
		titlu = "";
		artist = "";
		gen = "";
	}
	Melodie(int id, const string& titlu, const string& artist, const string& gen) {
		this->id = id;
		this->titlu = titlu;
		this->artist = artist;
		this->gen = gen;
	}

	Melodie& operator=(const Melodie& other) = default;

	//getters
	const int getId() const {
		return id;
	}
	const string& getTitlu() const {
		return titlu;
	}
	const string& getArtist() const {
		return artist;
	}
	const string& getGen() const {
		return gen;
	}

	//setters
	void setId(int id) {
		this->id = id;
	}
	void setTitlu(const string& titlu) {
		this->titlu = titlu;
	}
	void setArtist(const string& artist) {
		this->artist = artist;
	}
	void setGen(const string& gen) {
		this->gen = gen;
	}

	friend istream& operator>>(istream& input, Melodie& melodie);
	bool operator==(const Melodie& melodie) noexcept;
};

ostream& operator<<(ostream& output, const Melodie& melodie);