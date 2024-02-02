//Allegra Di Mattia 27/01/2024 3CIN - Verifica
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


int main()
{
    srand(time(NULL));
    int n=0;
    cout<<"Ciao, quante città vuoi includere nel tour?"<<endl;
    cin>>n;
    string city, v[n];
    int  distanza[n][n];
    
    for(int i=0; i<n; i++){
        cout<<"Dimmi il nome di una città: ";
        cin>>city;
        v[i]=city;
    }
    
    cout<<"Ecco l'elenco delle tue città:"<<endl;
    for(int i=0; i<n; i++){
        cout<<i+1<<")"<<v[i]<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i==j) distanza[i][j]=0;
            else distanza[j][i]=distanza[i][j]=rand()%100+1;
            cout<<"La distanza fra "<<v[i]<<" e "<<v[j]<<" è: "<<distanza[j][i]<<endl;
        }
    }
    
    

}