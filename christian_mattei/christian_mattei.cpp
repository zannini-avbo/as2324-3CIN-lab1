/******************************************************************************

*******************************************************************************/
#include <iostream>

using namespace std;

const int DIM = 3;

int main() {
    srand(time(NULL));
    string citta[DIM];
    int x;
    int y;

    for (int i = 0; i < DIM; i++) {
        cout << "Inserisci il nome: ";
        cin >> citta[i];
    }

    for (int i = 0; i < DIM; i++) {
        cout << citta[i] << endl;
    };

    int matrice[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrice[i][j];
        }
    }

    int distanzaMassima;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                matrice[i][j] = rand() % 100 + 1;
            } else {
                matrice[i][j] = distanzaMassima;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < DIM; i++) {
        cout << i << " " << citta[i] << endl;
    }

    cout << "Selezione una cella: ";

    cin >> x;
    cin >> y;
    cout << matrice[x][y] << endl;

    return 0;
}


