#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

// definire structura tara
struct tara {
	string nume;
	set<string> vecini;
	string culoare;
};

// functie pt colorare tari
void coloreaza_tari(vector<tara>& tari, const set<string>& culori_disponibile) {
	// parcurgem fiecare tara in parte
	for (tara& tara_curent : tari) {
		// verific culorile disponibile pentru tara curenta
		set<string> culoare_disponibila_tara = culori_disponibile;

		// itereaza prin vecinii tarii si elimina culorile vecinilor
		for (const string& vecin : tara_curent.vecini) {
			auto vecin_iter = find_if(tari.begin(), tari.end(), [vecin](const tara& c) { 
					return c.nume == vecin; 
					});

			if (vecin_iter != tari.end()) {
				culoare_disponibila_tara.erase(vecin_iter->culoare);
			}
		}

		// alege prima culoare disponibila pentru tara curenta
		if (!culoare_disponibila_tara.empty()) {
			tara_curent.culoare = *culoare_disponibila_tara.begin();
		}
	}
}

// functie pt afisarea rezultatelor
void rezultat(const vector<tara>& tari) {
	for (const tara& tara : tari) {
		cout << "Tara: " << tara.nume << ", Culoare: " << tara.culoare << endl;
	}
}

int main() {
	//lista tari si vecini
	vector<tara> tari = {
		{"Romania", {"Ungaria", "Bulgaria", "Ucraina"}, ""},
		{"Ungaria", {"Romania", "Austria"}, ""},
		{"Serbia", {"Romania", "Ungaria", "Croatia"}, ""},
		{"Moldova", {"Romania", "Ucraina"}, ""},
		{"Ucraina", {"Romania", "Ungaria", "Polonia", "Rusia"}, ""}
	};

	// lista culori posibile
	set<string> culori_disponibile = { "Rosu", "Galben", "Albastru" };

	coloreaza_tari(tari, culori_disponibile);
	rezultat(tari);

	return 0;
}
