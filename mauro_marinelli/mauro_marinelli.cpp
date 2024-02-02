/******************************************************************************
Verifica Mauro Marinelli 27/01/24
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int m = 3;

void Tour(int distanze[m][m]) {
    int Gne = 0;
    Gne = distanze[0][1] + distanze[1][2] + distanze[0][2];
    cout << "il tour è lungo ->" << Gne;
}

void Max(int distanze[m][m]) {
    int ma = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (distanze[i][j] > ma) {
                ma = distanze[i][j];
            }
        }
    }
    cout << "il massimo è " << ma << endl;
}

void ElencoCitta(string Città[]) {
    cout << endl << "le tue citta sono :" << endl;
    for (int i = 0; i < 3; i++) {
        cout << Città[i] << " il numero -> " << i + 1 << endl;
    }
}

void DistanzaCitta(int distanze[m][m]) {
    int x;
    int y;
    cout << "che distanza vuoi sapere?" << endl;
    cout << "prima citta : ";
    cin >> y;
    y = y - 1;
    cout << "secondo citta : ";
    cin >> x;
    x = x - 1;
    cout << "la tua distanza è " << distanze[x][y] << endl;
}

int main() {
    srand(time(NULL));

    string Città[m];
    int distanze[m][m];
    cout << "Dammi il nome di 3 città " << endl;
    for (int i = 0; i < m; i++) {
        cout << "citta numero " << i + 1 << endl;
        cin >> Città[i];
    }
    for (int i = 0; i < m; i++) {
        cout << " " << endl;
        for (int j = 0; j < m; j++) {
            distanze[i][j] = rand() % 10;
            if (j == i) {
                distanze[i][j] = 0;
            }
            cout << distanze[i][j];
        }
    }
    string risp;
    bool a = true;
    while (a = true) { // <-- doveva essere a == true (confronto) non a = true (assegnazione)
        cout << endl << "cosa vuoi fare?" << endl << "ecco una lista di cosa puoi fare" << endl << "Elenco" << endl
             << "Distanza" << endl << "Fine" << endl << "Max" << endl << "Tour" << endl;
        cin >> risp;
        if (risp == "Elenco") {
            ElencoCitta(Città);
        }
        if (risp == "Distanza") {
            DistanzaCitta(distanze);
        }
        if (risp == "Fine") {
            break;
        }
        if (risp == "Max") {
            Max(distanze);
        }
        if (risp == "Tour") {
            Tour(distanze);
        }
    }
    return 0;
}





