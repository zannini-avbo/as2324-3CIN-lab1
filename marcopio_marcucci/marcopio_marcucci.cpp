/*
Marco Marcucci 3CIN 27/01/2024
*/

#include <iostream>
#include <ctime>
using namespace std;
const int DIM = 10;



void fillMatrix( char matrice[DIM][DIM], char carattere){
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
        matrice[i][j] = carattere;
        
        }
    }
}

int main()
{
    
    int risp = 0;
    int risp1 = 0;
    string citta[DIM];
    int distanzatradueCitta = 0;
    
    for(int i=0 ; i<10 ; i++){
        cout <<"Inserisci la città:";
        cin >> citta[i];
    
    }
    for(int i=0 ; i<10 ; i++){
        cout <<"Inserisci le due città di cui vuoi sapere la distanza tra loro:";
        cout <<"inserisci la prima:";
        cin >> risp;
        cout <<"inserisci la seconda:";
        cin >> risp1;
        cout << "scrivi la distanza tra le due città";
        cin >>distanzatradueCitta;
        if (risp==risp1)
            cout<<"la distanza è 0";
        else
            cout<<"la distanza tra le due città è"<< distanzatradueCitta<<endl;
        
    }
    
    for (int i = 0; i < 10; i++){
        cout << citta[i] << " "<< endl;;
    }

    fillMatrix(matrice,'!');
    for(int i=0;i<DIM;i++){
        for(int j=0; j<DIM; j++){
            printf(" %c ", matrice[i][j]);

    }
}

    return 0;
}
