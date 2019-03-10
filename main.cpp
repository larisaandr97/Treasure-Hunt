#include <iostream>
#include "Joc.h"
#include "Cautator.h"
using namespace std;

int main()
{
    int comanda,dimensiune;
    cout<<"Bine ati venit!"<<endl;
    cout<<"Dupa fiecare runda, harta jocului va fi afisata pe ecran, conform urmatoarei legende:"<<endl;
    cout<<"-pozitiile cautatorilor vor fi marcate cu numere de la 1 la 4"<<endl;
    cout<<"-comorile se afla pe pozitiile marcate cu numarul 5"<<endl;
    cout<<"Introduceti dimensiunea hartii:";
    cin>>dimensiune;
    Joc J(dimensiune);
    J.afisare_harta(); //afisez harta initiala
    while(J.gameOver()==0)
    {
        cout<<"Doriti sa continuati? Tastati 1 pentru DA sau 0 pentru NU.";
        cin>>comanda;
        if(comanda==0)
        {
            J.afisare_harta(); //afisez harta finala
            cout<<"Ati decis sa opriti desfasurarea jocului."<<endl;
            return 0;
        }
        else
        {
            J.runda();
            J.afisare_harta();
        }
    }
    return 0;
}
