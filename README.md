# proiect-sincretic-MAP

## Nume
Algoritm de colorare a țărilor

## Detalii
Acest cod implementează un algoritm simplu de colorare a țărilor pe o hartă, astfel încât țările vecine să nu aibă aceeași culoare. Algoritmul utilizează o structură de date pentru a reprezenta o țară, unde se stochează numele țării, lista vecinilor și culoarea asignată.


__În cazul de față sunt date țările: România, Ungaria, Moldova, Ucraina, Bulgaria, Serbia și Slovacia, cărora le-au fost asignați toți vecinii lor reali.__

__Culorile displonibile date sunt: Roșu, Galben, Albastru.__

**Principalele componente ale codului sunt:**

  ```Structura tara```: Definește o structură pentru reprezentarea unei țări, cu câmpuri pentru nume, lista de vecini și culoare.
  
  ```Funcția coloreaza_tari```: Primește o listă de țări și un set de culori disponibile. Pentru fiecare țară, determină culorile disponibile eliminând culorile vecinilor. Apoi, atribuie țării prima culoare disponibilă.
  
  ```Funcția rezultat```: Afisează rezultatele colorării pentru fiecare țară.
  
  ```Funcția main```: Inițializează o listă de țări și vecinii acestora, precum și un set de culori disponibile. Apoi, apelurile la coloreaza_tari și rezultat aplică algoritmul de colorare și afișează rezultatele.
  
  În acest exemplu, se consideră că există trei culori disponibile (Roșu, Galben, Albastru), iar algoritmul încearcă să atribuie culori țărilor astfel încât vecinii să nu aibă aceeași culoare. În final, rezultatul este afișat în consolă, arătând numele țării și culoarea asignată.
  

## Exemplu rulare:
*ce apare in CMD*

## Vizualizare exemplu preimplementat
*photo*

## Livrabil
docker pull filipcojita/f-gcc-app:f-gcc-app

docker run -it filipcojita/f-gcc-app:f-gcc-app

## Explicații amănunțite
```
struct tara {
	string nume;
	set<string> vecini;
	string culoare;
};
```
Structura definește o țară (tara), având următoarele câmpuri:
+ nume: șir de caractere care reprezintă numele țării.
+ vecini: un set de șiruri de caractere care stochează numele țărilor vecine.
+ culoare: șir de caractere reprezentând culoarea asignată țării.

```
void coloreaza_tari(vector<tara>& tari, const set<string>& culori_disponibile) {
    for (tara& tara_curent : tari) {
        set<string> culoare_disponibila_tara = culori_disponibile;

        for (const string& vecin : tara_curent.vecini) {
            auto vecin_iter = find_if(tari.begin(), tari.end(), [vecin](const tara& c) { 
                    return c.nume == vecin; 
                    });

            if (vecin_iter != tari.end()) {
                culoare_disponibila_tara.erase(vecin_iter->culoare);
            }
        }

        if (!culoare_disponibila_tara.empty()) {
            tara_curent.culoare = *culoare_disponibila_tara.begin();
        }
    }
}

```
+ Funcția primește o listă de țări și un set de culori disponibile.
+ Pentru fiecare țară (tara_curent), se determină culorile disponibile eliminând culorile vecinilor.
+ Algoritmul parcurge vecinii fiecărei țări și elimină culorile acestora din setul culoare_disponibila_tara.
+ Se atribuie țării curente prima culoare disponibilă, dacă există vreuna.

```
void rezultat(const vector<tara>& tari) {
    for (const tara& tara : tari) {
        cout << "Tara: " << tara.nume << ", Culoare: " << tara.culoare << endl;
    }
}
```
+ Funcția primește o listă de țări și afișează rezultatele.
+ Pentru fiecare țară, se afișează numele și culoarea atribuită.

```
int main() {
    // Inițializare lista de tari și vecinii lor
    vector<tara> tari = {
        {"Romania", {"Ungaria", "Bulgaria", "Ucraina", "Moldova", "Serbia"}, ""},
        // ... alte țări și vecinii ...
    };

    // Inițializare set de culori posibile
    set<string> culori_disponibile = { "Rosu", "Galben", "Albastru" };

    // Apelarea functiilor pentru colorare și afișare rezultate
    coloreaza_tari(tari, culori_disponibile);
    rezultat(tari);

    return 0;
}
```
+ În funcția main, se inițializează lista de țări și vecinii lor, precum și un set de culori disponibile.
+ Se apelează funcțiile coloreaza_tari și rezultat pentru a aplica algoritmul de colorare și a afișa rezultatele.
+ Rezultatul este afișat în consolă, prezentând numele fiecărei țări și culoarea asignată conform algoritmului.

## Cod Sursa (main.cpp)
```
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
		{"Romania", {"Ungaria", "Bulgaria", "Ucraina", "Moldova", "Serbia"}, ""},
		{"Ungaria", {"Romania", "Austria", "Slovacia", "Slovenia", "Croatia", "Serbia"}, ""},
		{"Serbia", {"Romania", "Ungaria", "Croatia", "Bosnia", "Muntenegru","Kosovo", "Macedonia", "Bulgaria"}, ""},
		{"Moldova", {"Romania", "Ucraina"}, ""},
		{"Ucraina", {"Romania", "Ungaria", "Polonia", "Rusia","Slovacia", "Moldova", "Belarus"}, ""},
		{"Bulgaria", {"Romania", "Serbia", "Macedonia", "Grecia", "Turcia"}, ""},
		{"Slovacia", {"Ucraina", "Polonia", "Cehia", "Austria","Ungaria"}, ""}
	};

	// lista culori posibile
	set<string> culori_disponibile = { "Rosu", "Galben", "Albastru" };

	coloreaza_tari(tari, culori_disponibile);
	rezultat(tari);

	return 0;
}
```

## Concluzii
+ concluzie

## Autor
Creat de: **Cojiță Filip-Iosia**

## Bibliografie  
https://chat.openai.com/
