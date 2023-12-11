//- dlt diacrt
//+ trnsl to rou

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

// Definirea structurii pentru o tara
struct Country {
	string name;
	set<string> neighbors;
	string color;
};

// Functia pentru colorarea tarilor
void colorCountries(vector<Country>& countries, const set<string>& availableColors) {
	// Parcurgem fiecare tara in parte
	for (Country& country : countries) {
		// Verificam culorile disponibile pentru tara curenta
		set<string> availableColorsForCountry = availableColors;

		// Iteram prin vecinii tarii si eliminăm culorile vecinilor
		for (const string& neighbor : country.neighbors) {
			auto neighborIt = find_if(countries.begin(), countries.end(),
				[neighbor](const Country& c) { return c.name == neighbor; });

			if (neighborIt != countries.end()) {
				availableColorsForCountry.erase(neighborIt->color);
			}
		}

		// Alegem prima culoare disponibila pentru tara curenta
		if (!availableColorsForCountry.empty()) {
			country.color = *availableColorsForCountry.begin();
		}
	}
}

// Functia pentru afisarea rezultatelor
void printResult(const vector<Country>& countries) {
	for (const Country& country : countries) {
		cout << "Tara: " << country.name << ", Culoare: " << country.color << endl;
	}
}

int main() {
	// Lista de țări și vecinii lor
	vector<Country> countries = {
		{"A", {"B", "C", "D"}, ""},
		{"B", {"A", "C"}, ""},
		{"C", {"A", "B", "D"}, ""},
		{"D", {"A", "C"}, ""}
		// Puteti adauga mai multe tari si vecini după necesitate
	};

	// Lista de culori posibile
	set<string> availableColors = { "Red", "Green", "Blue" };

	// Apelam functia de colorare a tarilor
	colorCountries(countries, availableColors);

	// Afisam rezultatele
	printResult(countries);

	return 0;
}
