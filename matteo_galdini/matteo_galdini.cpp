/* Verifica Informatica 27/01/2023 (City Tour C++)
GALDINI MATTEO 3CIN
*/

#include <iostream>
#include <fstream>

using namespace std;

const int len = 5;

void stampaCitta (string array[], int N){
    for (int i=0; i<N; i++){
        cout<<array[i]<<" ";
    }
}

int main(){
    
    // Dichiarazione variabili
    int N=0;
    string prima_scelta;
    string seconda_scelta;
    int percorso_totale = 0;
    int distance=0;
    int distanza_massima = 0;
    string prima_citta;
    string seconda_citta;
    int end = 1;
    
    // Assegnazione valore a N
    cout<<"How many city will i have to consider? ";
    cin>>N;
    
    // Dichiarazione funzione random
    srand(time(NULL));
    
    // Dichiarazione e riempimento vettore in base al numero N inserito
    string citta [N];
    for (int i=0; i<N; i++){
        cout<<" - ";
        cin>>citta[i];
    }
    
    // Dichiarazione matrice
    int distanze [N][N];
    
    // for per generare casualmente le distaze
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            if (i==j){
                distanze[i][j]=0;
            }
            else{
                distance = rand()%100 + 1;
                distanze[i][j] = distance;
                distanze[j][i] = distance;
            }
        }
    }
    
    // menu che permette all'utente di scegliere cosa visualizzare
    while (end != 0){
        cout<<"Digita 1 per stampare l'elenco delle città"<<endl<<"Digita 2 per stampare le distanze fra ogni coppia di città"<<endl<<"Digita 3 per scegliere due città e stampare la distanza fra di esse"<<endl<<"Digita 4 per trovare le due città più lontane fra loro"<<endl<<"Digita 5 per stabilire quanti chilometri è lungo il percorso che fa il giro di tutte le città"<<endl<<"Digita 0 per uscire"<<endl;
        cout<<": ";
        cin>>end;
        
        // Stampa elenco città
        if (end == 1){
            stampaCitta(citta, N);
        }
        
        // Stampa distanza tra ogni coppia di città
        if (end == 2){
            stampaCitta(citta, N);
            cout<<endl;
            for (int i = 0; i<N; i++){
                cout<<citta[i];
                for (int j = 0; j<N; j++){
                    cout<<" "<<distanze[i][j];  
                }
            cout<<endl;
            } 
        }
        
        
        // Stampa la distanza tra due città scelte dall'utente
        if (end == 3){
            cout<<endl;
            cout<<"Di quali due città vuoi inserire le distanze? (inserisci i nomi esattamente come me li hai scritti prima): ";
            cin>>prima_scelta;
            cin>>seconda_scelta;
            for (int i=0; i<N; i++){
                if (citta[i] == prima_scelta){
                    for (int j=0; j<N; j++){
                        if (citta[j] == seconda_scelta){
                            cout<<"La distanza tra "<<prima_scelta<<" e "<<seconda_scelta<<" è di "<<distanze[i][j]<<"km";
                            cout<<endl;
                        }
                    }
                }
            }
            
        }
        
        // Stampa le due città più lontane tra loro
        if (end == 4){
            for (int i = 0; i<N; i++){
                for (int j = 1; j<N; j++){
                    if (distanze[i][j] > distanza_massima){
                        distanza_massima = distanze[i][j];
                        prima_citta = citta[i];
                        seconda_citta = citta[j];
                    }
                }
            }
            cout<<"La distanza massima è di "<<distanza_massima<<"km ed è tra le seguenti città: "<<prima_citta<<", "<<seconda_citta;
        }
        
        // Stampa la distanza totale
        if (end == 5){
            for (int i=0; i<N - 1; i++){
                percorso_totale = percorso_totale + distanze [i][i + 1];
            }
            cout<<"La distanza totale tra le città è: "<<percorso_totale<<"km";
            
        }
        
        cout<<endl;
    }
    
    // Fine codice
    return 0;
}



