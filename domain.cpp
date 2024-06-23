#include "domain.h"

vector<string> splitLine(const string& linie, char delimitator) {
	vector<string> atribute;
	stringstream stream(linie);
	string obiect;

	while (getline(stream, obiect, delimitator)) {
		atribute.push_back(obiect);
	}

	return atribute;
}

bool Melodie::operator==(const Melodie& melodie) noexcept {
	return this->id == melodie.id && this->titlu == melodie.titlu && this->artist == melodie.artist && this->gen == melodie.gen;
}
istream& operator>>(istream& input, Melodie& melodie) {
	string linie;
	getline(input, linie);

	if (linie.empty()) {
		return input;
	}

	vector<string> atribute = splitLine(linie, ',');
	melodie.setId(stoi(atribute[0]));
	melodie.setTitlu(atribute[1]);
	melodie.setArtist(atribute[2]);
	melodie.setGen(atribute[3]);

	return input;
}

ostream& operator<<(ostream& output, const Melodie& melodie) {
	output << melodie.getId() << "," << melodie.getTitlu() << "," << melodie.getArtist() << "," << melodie.getGen() << "\n";
	return output;
}