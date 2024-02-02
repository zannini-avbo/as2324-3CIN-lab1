/******************************************************************************
Dondi Alessandro
27/01/2024 3CIN
verifica informatica
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    //inserire nella prima riga di file di input il numero di città
    //nelle righe sottostanti immettere le diversè citta distanziate da uno spazio o da un a capo
    //sotto le città le funzioalita del menu;

    // FIXME: dovevi usare ad esempio std::ifstream
    // qui stai sovrascrivendo stdin e dopo perdi la possibilità di utilizzare "cin >>"
    // chiedi per ulteriori chiarimenti
    freopen("input.txt", "r", stdin); // Open a file, replacing an existing stream with it.
    int DIM = 0;
    cin >> DIM;
    string città[DIM];
    for (int i = 0; i < DIM; i++) {
        cin >> città[i];
    }
    int distanze[DIM];
    for (int i = 0; i < DIM; i++) {
        distanze[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < DIM; i++) {
        cout << "distanza della città numero #" << i + 1 << ": " << distanze[i] << endl;
    }
    cout << endl << "Matrice delle distanze delle città: " << endl << endl;
    int m[DIM][DIM];
    int k = 0, valore = 0;
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            valore = distanze[i] - distanze[j];
            if (valore <= 0) {
                valore = distanze[j] - distanze[i];
                m[i][j] = valore;
            }
            m[i][j] = valore;
            cout << "\t" << m[i][j];
        }
        cout << endl;
    }
    // IMPOSSIBILE CHIUDERE IL FILE
//    fclose(stdin);

    cout << "scegliere dal menù che funzionalità vorrebbe usare: " << endl << endl;
    int idx = 0;
    int scelta = 5;
    while (idx == 0) {
        cout << "ecco le funzionalità disponibili: " << endl;
        cout << "1) Stampare elenco delle città" << "\n" << "2) Stampare le distanze fra ogni coppia di città" << "\n"
             << "3) Scegliere due città e stampare la distanza fra di esse." << "\n"
             << "4) Trovare le due città più lontane fra loro." << "\n"
             << "5) Stabilire quanti chilometri è lungo il percorso che fa il giro di tutte le città" << endl;
//        cin>>scelta;
        int m[DIM][DIM];
        int min;
        switch (scelta) {
            case 0:
                cout << "opzione non valida";
                break;
            case 1:
                for (int i = 0; i < DIM; i++) {
                    cout << "\ncittà numero #" << i + 1 << ": " << città[i] << endl;
                }
                cout << endl;
                break;
            case 2:
                cout << "ecco la distanza tra ogni coppia di città" << endl;
                int k;
                for (int i = 0; i < DIM; i++) {
                    for (int j = 0; j < DIM; j++) {
                        valore = distanze[i] - distanze[j];
                        if (valore <= 0) {
                            valore = distanze[j] - distanze[i];
                            m[i][j] = valore;
                        }
                        m[i][j] = valore;
                        if (i == k) {
                            cout << città[i] << " - " << città[i] << m[i][j] << endl;
                            k++;
                        } else {
                            cout << città[i] << " - " << città[i + 1] << m[i][j] << endl;
                        }
                    }
                    cout << endl;
                }
                break;
            case 3:
                cout << "scegli le due città" << endl;
                for (int i = 0; i < DIM; i++) cout << i << ")" << città[i] << endl;
                break;
            case 4:
                min = distanze[0];
                for (int i = 0; i < DIM; i++) {
                    if (distanze[i] > distanze[i + 1]) min = distanze[i + 1];
                }
                break;
            case 5:
                int max = 0;
                for (int i = 0; i < DIM; i++) {
                    max += distanze[i];
                }
                cout << "Il viaggio totale è lungo" << max << "km" << endl; // dovevi dividere per 2
                break;
        }
        cout << "vuoi continuare?:  --> [si] [no]";
        string risp;
        cin >> risp;
        if (risp != "si" || risp != "no") {
            cout << "risposta non valida, riprovare";
            cin >> risp;
        }
        if (risp == "no") idx = 1;
        idx = 1;
    }

    return 0;
}