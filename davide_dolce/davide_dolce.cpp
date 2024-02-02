/******************************************************************************

Davide Dolce
3cin
verifica 27/01/2024

*******************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));

    int n;
    printf("scegli il numero di citta:");
    scanf("%d", &n);
    string citta[n];
    int tabella[n][n];
    int scelta;
    int chilometraggio;
    for (int i = 0; i < n; i++) {
        cin >> citta[i];

    }
    printf("\n");
    printf("    0   ");
    for (int i = 0; i < n; i++) {
        cout << citta[i] << " ";

    }
    printf("\n");
    for (int i = 0; i < n; i++) {

        cout << citta[i] << "\n";
        printf("\n");
    }
    printf("tabella distanze:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) tabella[i][j] = 0;
            else
                tabella[i][j] = rand() % 100;

        }
    }

    for (int i = 0; i < n; i++) {
        //cout<<citta[i];
        for (int j = 0; j < n; j++) {
            cout << tabella[i][j] << "\t";

        }
        cout << endl;
    }
    printf("cosa vorresti fare?\n");
    printf("1) Stampare l'elenco delle città\n2) Stampare le distanze fra ogni coppia di città\n3) Scegliere due città e stampare la distanza fra di esse\n4) Trovare le due città più lontane fra loro\n5) Stabilire quanti chilometri è lungo il percorso che fa il giro di tutte le città");
    scanf("\n%d", &scelta);
    if (scelta == 1) {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": " << citta[i];
            printf("\n");

        }
    } else if (scelta == 2) {
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                cout << tabella[i][j] << "\t";

            }
            cout << endl;
        }
    } else if (scelta == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) tabella[i][j] = 0;
                else {
                    tabella[i][j] = rand() % 100;
                }
                chilometraggio = chilometraggio + tabella[i][j];
            }
        }

        printf("la distanza per attraversare tutte le citta e di %dkm", chilometraggio);
    }


    return 0;
}