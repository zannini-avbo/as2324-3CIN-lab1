/******************************************************************************
- BUTT ABDUL MOHID  - - 3 CIN -  - VERIFICA : City Tour -  - 27/01/2024
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int DIM = 3;
void riempiMatrice(int matrice[DIM][DIM]){
    for(int i=0;i<DIM;i++){
        for(int y=0;y<DIM;y++){
            matrice[i][y]=rand()%100 + 1;
        }
    }
}
void diagonaleMatrice(int matrice[DIM][DIM]){
    for(int i=0;i<DIM;i++){
        matrice[i][i]=0;
    }
}
void stampaMatrice(int matrice[DIM][DIM]){
    cout << endl;
    for(int i=0;i<DIM;i++){
        for(int y=0;y<DIM;y++){
            printf("%3d" , matrice[i][y]);
        }
        cout << endl;
    }
    cout << endl;
}
void stampaCittà(string vettore[DIM]){
    cout << "Adesso ti ristampo le città" << endl;
    for(int i=0;i<DIM;i++){
        cout << ": " << ("%s", vettore[i]) << endl;
    }
    cout << endl;
}
void sommaCittà(int matrice[DIM][DIM]){
    cout << endl;
    int somma = 0;
    for(int i=0;i<DIM;i++){
        somma += matrice[i][0];
    }
    printf("I chilometri per percorrere tutte le città è %d", somma);
}
void distanzaCittà(string vettore[DIM], int matrice[DIM][DIM]){
    cout << endl;
    for (int i=0; i<DIM; i++) {
            cout << "Distanza da " << vettore[i] << endl;
            for (int j=0; j<DIM; j++) {
                cout << vettore[j] << ": " << matrice[i][j] << endl;
            }
            cout << endl;
        }
}
void lonataneCittà(string vettore[DIM], int matrice[DIM][DIM]){
    cout << endl;
    int max = 0;
    for (int i=0; i<DIM; i++) {
            for (int j=0; j<DIM; j++) {
                if(matrice[i][j]>max){
                    max=matrice[i][j];
                    
                }
            }
    }
    printf("Il distanza massima tra due città è %d ", max);
}
void scegliCittà(string vettore[DIM], int matrice[DIM][DIM]){
    cout << endl;
    cout << "Scegli due città : " << endl;
    string città;
    string citta;
    cin >> città;
    cin >> citta;
}
int main()
{
    srand(time(NULL));
    string vet[DIM];
    cout<<"Inserisci 5 nomi di città " << endl;
    ofstream outputCittà("Città.txt");
    for(int i=0;i<DIM;i++){
        cout<<": ";
        getline(cin, vet[i]);
    }
    for(int i = 0;i<DIM;i++){
        outputCittà << vet[i] << endl;
    }
    outputCittà.close();
        
    int mat[DIM][DIM];
    riempiMatrice(mat);
    diagonaleMatrice(mat);
    stampaMatrice(mat);
    stampaCittà(vet);
    sommaCittà(mat);
    distanzaCittà(vet , mat);
    lonataneCittà(vet, mat);
    scegliCittà(vet, mat);

    return 0;
}

