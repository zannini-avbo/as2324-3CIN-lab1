/*Alessandro Montanari
27/01/2024*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxLcitta = 20;

void matriceNomiDistanze(char nomeCitta[][20], int distanza[][5], int nomi) {
    for (int i = 0; i < nomi; i++) {
        for (int j = 0; j < nomi; j++) {
            if (i == 0 && j == 0) {
                printf("%10s", "Citta");
            } else if (i == 0) {
                printf("%10s", nomeCitta[j - 1]);
            } else if (j == 0) {
                printf("%10s", nomeCitta[i - 1]);
            } else {
                printf("%10d", distanza[i][j]);
            }
        }
        printf("\n");
    }
}

void stampaDistanzaTraCitta(char nomeCitta[][20], int distanza[][5], int nomi) {
    char citta1[20], citta2[20];
    int indiceCitta1 = -1, indiceCitta2 = -1;

    printf("Inserisci il nome della prima citta: ");
    scanf("%s", citta1);
    printf("Inserisci il nome della seconda citta: ");
    scanf("%s", citta2);

    for (int i = 0; i < nomi; i++) {
        if (nomeCitta[i][0] == citta1[0] && nomeCitta[i][1] == citta1[1]) {
            indiceCitta1 = i;
        }
        if (nomeCitta[i][0] == citta2[0] && nomeCitta[i][1] == citta2[1]) {
            indiceCitta2 = i;
        }
    }

    if (indiceCitta1 == -1 || indiceCitta2 == -1) {
        printf("Una o entrambe le citta non sono presenti.\n");
        return;
    }

    printf("Distanza tra %s e %s: %d chilometri\n", citta1, citta2, distanza[indiceCitta1][indiceCitta2]);
}

void stampaCittaPiuLontane(char nomeCitta[][20], int distanza[][5], int nomi) {
    int maxDistanza = -1;
    int indiceCitta1 = -1, indiceCitta2 = -1;

    for (int i = 1; i < nomi; i++) {
        for (int j = 1; j < nomi; j++) {
            if (distanza[i][j] > maxDistanza) {
                maxDistanza = distanza[i][j];
                indiceCitta1 = i;
                indiceCitta2 = j;
            }
        }
    }

    printf("Le due citta piu lontane sono: %s e %s, distanza: %d chilometri\n", nomeCitta[indiceCitta1 - 1], nomeCitta[indiceCitta2 - 1], maxDistanza);
}

int main() {
    srand(time(NULL));

    int nomi = 5;

    char nomeCitta[5][20];
    printf("Inserisci i nomi delle citta:\n");
    for (int i = 0; i < nomi; i++) {
        printf("Città %d: ", i + 1);
        scanf("%s", nomeCitta[i]);
    }

    int distanza[5][5];
    for (int i = 0; i < nomi; i++) {
        for (int j = 0; j < nomi; j++) {
            if (i == 0 || j == 0) {
                distanza[i][j] = -1;
            } else {
                distanza[i][j] = rand() % 100 + 1;
            }
        }
    }

    matriceNomiDistanze(nomeCitta, distanza, nomi);
    stampaDistanzaTraCitta(nomeCitta, distanza, nomi);
    stampaCittaPiuLontane(nomeCitta, distanza, nomi);

    return 0;
}
