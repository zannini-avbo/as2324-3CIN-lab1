/* 
* City Tour
* Verifica 27/01/2024 - Bisognin Luca
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int DIM = 3;

// funzione per stampare le città
void print_citta(string citta[], int DIM) {
    cout << endl << "ecco le tue città: " << endl;
    for (int i = 0; i < DIM; i++) {
        cout << "città" << i + 1 << ": " << ("%s", citta[i]) << endl;
    }
    cout << endl;
}

// funzione per scrivere la distanza tra 2 delle città scelte dll'utente
void max_dist_cities(int array_distances[], int DIM, string citta[]) {
    cout << endl << "distanza tra città maggiore: ";
    int max = array_distances[0];
    for (int i = 0; i < DIM * DIM; i++) {
        if (max < array_distances[i]) {
            max = array_distances[i];
        }
    }
    cout << max;
}

// funzione per creare e stampare la matrice con le distanze tra ogni città
int matrix_distances(int matrix[DIM][DIM], int DIM, string citta[]) {
    int array_distances[DIM * DIM], sum;
    cout << "distanza tra le città" << endl;
    cout << "        ";
    for (int i = 0; i < DIM; i++) {
        cout << setw(7) << citta[i];
    }

    cout << endl << "-----------------------------" << endl;

    for (int i = 0; i < DIM; i++) {
        cout << citta[i] << setw(2) << " |";
        for (int j = 0; j < DIM; j++) {
            if (i == j) {
                matrix[i][j] = 0;
                array_distances[i] = matrix[i][j];
            } else {
                int num_random = rand() % 100 + 1;

                // for-loop per controllare che non si generino stesse distanze
                for (int i = 0; i < DIM; i++) {
                    for (int j = 0; j < i; j++) {
                        if (num_random == matrix[i][j] && i != j) {
                            num_random = rand() % 100 + 1;
                            j = 0;
                        }
                    }
                }
                matrix[i][j] = num_random;
                array_distances[i] = num_random;
                if (i == 0) {
                    sum += num_random;
                }
            }
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    max_dist_cities(array_distances, DIM, citta);

    return sum;
}

void dist_two_cities(string citta[DIM]) {
    int distance = rand() % 100 + 1;
    string cities[2];
    cout << endl << "scegli due città tra quelle da te proposte" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "città " << i + 1 << ": ";
        cin >> cities[i];
    }
    cout << endl << "distanza " << citta[0] << " - " << citta[1] << ": " << distance;
}

void sum_distances(int sum) {
    cout << endl << endl << "i chilometri del percorso di tutte le città è: " << sum << endl;
}

int main() {
    int matrix[DIM][DIM];
    string citta[DIM];

    cout << "inserisci " << DIM << " città a tuo piacere." << endl;
    for (int i = 0; i < DIM; i++) {
        cout << "città " << i + 1 << ": ";
        cin >> citta[i];
    }

    print_citta(citta, DIM);
    int sum = matrix_distances(matrix, DIM, citta);
    dist_two_cities(citta);
    sum_distances(sum);

    return 0;
}