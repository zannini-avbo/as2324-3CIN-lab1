#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

void stampaCitta(int distanze[5][5], string citta[5]);
void stampaDistanze(int distanze[5][5], string citta[5]);
void stampaDistanzecitta(int distanze[5][5], string citta[5]);
void stampaCittalontane(int distanze[5][5], string citta[5]);
void stampaKM(int distanze[5][5], string citta[5]);

int main() {

    srand(time(NULL));

    ifstream file("citta.txt");
    if (!file) {
        cout << "File non esiste" << endl;
        cout << endl;
        return 1;
    }

    string citta[5];
    int distanze[5][5];

    for (int i = 0; i < 5; i++) {
        file >> citta[i];
    }

    int scelta;
    do {
        cout << "0. Esci" << endl;
        cout << "1. Stampare l'elenco delle città." << endl;
        cout << "2. Stampare le distanze fra ogni coppia di città." << endl;
        cout << "3. Scegliere due città e stampare la distanza fra di esse." << endl;
        cout << "4. Trovare le due città più lontane fra loro." << endl;
        cout << "5. Stabilire quanti chilometri è lungo il percorso che fa il giro di tutte le città." << endl;
        cout << "Scelta[0-5]: ";
        scanf("%d", &scelta);
        cout << endl;

        switch (scelta) {
            case 0:
                cout << "Arrivederci" << endl;
                break;
            case 1:
                stampaCitta(distanze, citta);
                break;
            case 2:
                stampaDistanze(distanze, citta);
                break;
            case 3:
                stampaDistanzecitta(distanze, citta);
                break;
            case 4:
                stampaCittalontane(distanze, citta);
                break;
            case 5:
                stampaKM(distanze, citta);
                break;
            default:
                cout << "Scelta non valida" << endl;
                break;
        }
    } while (scelta != 0);

    file.close();

    return 0;
}

void stampaCitta(int distanze[5][5], string citta[5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Citta " << i + 1 << ": ";
        cout << citta[i] << endl;
    }
    cout << "\n\n";
}

void stampaDistanze(int distanze[5][5], string citta[5]) {
    for (int i = 0; i < 5; i++) {
        cout << "Distanze da " << citta[i] << ":" << endl;
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                distanze[i][j] = 0;
            } else {
                distanze[i][j] = rand() % 100;
            }
            if (i != j) { 
                cout << citta[j] << ": " << distanze[i][j] << endl;
            } else {
                continue;
            }
        }
        cout << endl;
    }
}

void stampaDistanzecitta(int distanze[5][5], string citta[5]) {
    string citta1, citta2;
    int i = 0, j = 0;
    cout << "Inserisci la prima citta: ";
    cin >> citta1;
    cout << "Inserisci la seconda citta: ";
    cin >> citta2;
    cout << endl;


    bool trovato = false;
    while (i < 5 && !trovato) {
        if (citta1 == citta[i]) {
            trovato = true;
        } else {
            i++;
        }
    }

    trovato = false;
    while (j < 5 && !trovato) {
        if (citta2 == citta[j]) {
            trovato = true;
        } else {
            j++;
        }
    }

    if (i < 5 && j < 5) {
        cout << "La distanza tra " << citta1 << " e " << citta2 << " e': " << distanze[i][j] << "km" << endl;
    } else {
        cout << "Citta non trovata" << endl;
    }
    cout << endl;
}

void stampaCittalontane(int distanze[5][5], string citta[5]) {
    int max = 0;
    int city1 = 0;
    int city2 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (distanze[i][j] > max) {
                max = distanze[i][j];
                city1 = i;
                city2 = j;
            }
        }
    }
    cout << "Le due citta piu' lontane sono " << citta[city1] << " e " << citta[city2] << endl;
    cout << endl;

    
}

void stampaKM(int distanze[5][5], string citta[5]) {
    int somma = 0;
    for (int i = 0; i < 5; i++) {
        somma += distanze[i][i + 1]; // @NOTE: non tiene conto del fatto che la matrice fosse simmetrica
    }
    cout << "Il percorso che fa il giro di tutte le citta e' lungo " << somma << " km" << endl;
    cout << "\n\n";
}