#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Structura pentru a reprezenta o tara
struct Country {
    string name;
    set<int> neighbors;
    int color;

    Country(string n) : name(n), color(-1) {}  // Initializam culoarea cu -1 (nedefinita)
};

// Functie pentru colorarea grafurilor
void colorCountries(vector<Country>& countries, const vector<string>& colors) {
    for (int i = 0; i < countries.size(); ++i) {
        set<int> usedColors;
        for (int neighbor : countries[i].neighbors) {
            if (countries[neighbor].color != -1) {
                usedColors.insert(countries[neighbor].color);
            }
        }
        for (int j = 0; j < colors.size(); ++j) {
            if (usedColors.find(j) == usedColors.end()) {
                countries[i].color = j;
                break;
            }
        }
    }
}

int main() {
    int N;
    cout << "Introduceti numarul de tari: ";
    cin >> N;

    vector<Country> countries;
    vector<string> colors;

    cout << "Introduceti numele tarilor:" << endl;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        countries.push_back(Country(name));
    }

    cout << "Introduceti vecinii pentru fiecare tară (indicele tarii):" << endl;
    for (int i = 0; i < N; ++i) {
        int numNeighbors;
        cin >> numNeighbors;
        for (int j = 0; j < numNeighbors; ++j) {
            int neighbor;
            cin >> neighbor;
            countries[i].neighbors.insert(neighbor);
            countries[neighbor].neighbors.insert(i);
        }
    }

    cout << "Introduceti culorile posibile:" << endl;
    int numColors;
    cin >> numColors;
    for (int i = 0; i < numColors; ++i) {
        string color;
        cin >> color;
        colors.push_back(color);
    }

    colorCountries(countries, colors);

    cout << "Culorile pentru fiecare tara:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << countries[i].name << " este colorata cu " << colors[countries[i].color] << endl;
    }

    return 0;
}
