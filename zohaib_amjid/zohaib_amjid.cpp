/******************************************************************************

Zohaib Amjid 3CIN 27/01/2024                             

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

int main() {
    int DIM;
    srand(time(NULL));
    int N;

    cout << "Inserisci il numero delle una città: ";
    cin >> N;

    string città[N];
    for (int i = 0; i < N; i++) {
        cout << "Inserisci il  nome delle citta " << i + 1 << ": ";
        cin >> città[i];
    }

    cout << endl;

    DIM = N;
    void distanzacittà(int distanza[DIM][DIM]) {
        int i, j;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    int distanza = rand() % 500 + 1;
                    distanzacittà[i][j] = distanza;
                }
            }

        }
        void Stampadistanzacittà(int distanza[DIM][DIM]) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i != j) {
                        cout << "La distanza fra la città di" << i + 1 << "e " << j + 1 << " è:";
                    }
                }

            }
        }

        ofstream file("nomi_città.txt");
        if (file.is_open()) {
            for (int i = 0; i < N; i++) {
                file << città[i] << endl;
            }

        }
        file.close();
        cout << "I nomi delle città sono stati salvati su un file." << endl;

    }
}