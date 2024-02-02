/******************************************************************************

        MARCO GUARINONI
        27/11/23 3CIN
    City Tour C (27/1)
        
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NUMERO_CITTA=4;

int inserisci_Citta(char N[4][20], int l){
    printf("Scrivi %d città: \n", l);
    for(int i=0; i<l; i++){
    printf("città %d: ", i + 1);
    scanf("%s", N[i] );
    }
}

void generaDistanzeCasuali(int distanze[NUMERO_CITTA][NUMERO_CITTA]) {
    srand(time(NULL)); 

    
    for (int i = 0; i < NUMERO_CITTA; i++) {
        for (int j = i + 1; j < NUMERO_CITTA; j++) {
            int distanza = rand() % 100 + 1; 
            distanze[i][j] = distanza;
            distanze[j][i] = distanza; 
        }
    }
}

void stampaDistanze(int distanze[NUMERO_CITTA][NUMERO_CITTA]) {
    printf("\nDistanze tra le città:\n");
    for (int i = 0; i < NUMERO_CITTA; i++) {
        for (int j = 0; j < NUMERO_CITTA; j++) {
            printf("%d\t", distanze[i][j]);
        }
        printf("\n");
    }
}

int distanzaTraCitta(int distanze[NUMERO_CITTA][NUMERO_CITTA], int citta1, int citta2) {
    return distanze[citta1][citta2];
}


int main()
{
    char N[4][20];
    int num_citta = 4; 
    inserisci_Citta(N, num_citta);
    

     printf("\nLe città inserite sono:\n");
    for (int i = 0; i < num_citta; i++) {
        printf("%s\n", N[i]);
    }
    
    //inizializzaDistanze(distanze);
    generaDistanzeCasuali(distanze);
    stampaDistanze(distanze);
    
    int distanze[NUMERO_CITTA][NUMERO_CITTA];
    
    printf("\nDistanze fra ogni coppia di città:\n");
    for (int i = 0; i < NUMERO_CITTA; i++) {
        for (int j = i + 1; j < NUMERO_CITTA; j++) {
            printf("Distanza tra %s e %s: %d\n", N[i], N[j], distanzaTraCitta(distanze, i, j));
        }
    }

    
    int citta1, citta2;
    printf("\nInserisci il numero delle due città (da 1 a %d): ", NUMERO_CITTA);
    scanf("%d %d", &citta1, &citta2);
    printf("Distanza tra %s e %s: %d\n", N[citta1 - 1], N[citta2 - 1], distanzaTraCitta(distanze, citta1 - 1, citta2 - 1));

    return 0;
}
