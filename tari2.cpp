#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

// Definirea structurii pentru o țară
struct Country {
	string name;
	set<string> neighbors;
	string color;
};

// Funcția pentru colorarea țărilor
void colorCountries(vector<Country>& countries, const set<string>& availableColors) {
	// Parcurgem fiecare țară în parte
	for (Country& country : countries) {
		// Verificăm culorile disponibile pentru țara curentă
		set<string> availableColorsForCountry = availableColors;

		// Iterăm prin vecinii țării și eliminăm culorile vecinilor
		for (const string& neighbor : country.neighbors) {
			auto neighborIt = find_if(countries.begin(), countries.end(),
				[neighbor](const Country& c) { return c.name == neighbor; });

			if (neighborIt != countries.end()) {
				availableColorsForCountry.erase(neighborIt->color);
			}
		}

		// Alegem prima culoare disponibilă pentru țara curentă
		if (!availableColorsForCountry.empty()) {
			country.color = *availableColorsForCountry.begin();
		}
	}
}

// Funcția pentru afișarea rezultatelor
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
		// Puteți adăuga mai multe țări și vecini după necesitate
	};

	// Lista de culori posibile
	set<string> availableColors = { "Red", "Green", "Blue" };

	// Apelăm funcția de colorare a țărilor
	colorCountries(countries, availableColors);

	// Afișăm rezultatele
	printResult(countries);

	return 0;
}
