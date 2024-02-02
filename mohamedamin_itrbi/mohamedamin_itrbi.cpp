/*
Itrbi Mohamed Amin 3cin 27/01/2024
Verifica informatica
*/
#include <iostream>
using namespace std;




int main()
{
    int distanza1 = 30 ;
    int distanza2 = 15 ;
    int lungpercorso = 90;
    string citta1[2];
    string citta2[2];
    for(int i = 0; i < 2; i++){
        cout<<"Inserisci le citta' che vuoi \n" ;
        cin>>citta1[i];
        cout<< citta1[i]  << " \n ";
        cout<< " Questa è la distanza in kilometri delle 2 citta più lontane: " << distanza1 ;
        
        for(int i = 0; i < 2; i++){
            cout<<"Inserisci le citta' che vuoi \n" ;
            cin>>citta2[i];
            cout<< citta2[i]  << " \n ";
            cout<< distanza2  << " Questa è la distanza in kilometri delle altre 2 citta " ;
        }
        for(int i = 0; i < 2; i++){
            cout<< " Questa è la lunghezza in kilometri del percorso di tutte le citta è "   << lungpercorso  ;
        }
        
        
        
    
        
        
        
        
        
        
    }
    

    return 0;
}







