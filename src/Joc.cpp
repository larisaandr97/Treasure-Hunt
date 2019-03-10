#include "Joc.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Cautator.h"

using namespace std;

//constructor clasa Joc care primeste ca parametru dimensiunea matricei Map
Joc::Joc(int dimensiune)
{
    dimensiune_harta=dimensiune;
    int i,j;
    Map = new int*[dimensiune_harta];
    for(i=0; i<dimensiune_harta; i++)
        Map[i] = new int[dimensiune_harta];
    for(i=0; i<dimensiune_harta; i++)
        for(j=0; j<dimensiune_harta; j++)
            Map[i][j]=0;
    nr_comori_gasite=0;
    win=0;
    for(i=1; i<=4; i++)
        status[i]=0;
    for(i=1; i<=4; i++)
        castigator[i]=0;
    c[0]=new Cautator_1(0,0,*this);
    c[1]=new Cautator_2(0,dimensiune_harta-1,*this);
    c[2]=new Cautator_3(dimensiune_harta-1,dimensiune_harta-1,*this);
    c[3]=new Cautator_4(dimensiune_harta-1,0,*this);
    //pozitionarea cautatorilor
    Map[0][0]=1;
    Map[0][dimensiune_harta-1]=2;
    Map[dimensiune_harta-1][dimensiune_harta-1]=3;
    Map[dimensiune_harta-1][0]=4;
    //pozitionarea ranadom a comorilor
    srand(time(NULL)); //pentru a genera alte pozitii la fiecare rulare a programului
    int x=0;
    while(x<3)
    {
        i=rand()%dimensiune_harta;
        j=rand()%dimensiune_harta;
        if ((i!=0 || j!=0) && (i!=0 || j!=dimensiune_harta-1) && (i!=dimensiune_harta-1 || j==dimensiune_harta-1) && (i!=dimensiune_harta-1 || j==0) && Map[i][j]==0)
        {
            Map[i][j]=5;
            x=x+1;
        }
    }
}

//destructor clasa Joc
Joc::~Joc()
{
    int i;
    for(i=0; i<dimensiune_harta; i++)
        delete[] Map[i];
    delete[] Map;
}

//constructor de copiere clasa Joc
Joc::Joc(const Joc &J)
{
    int i,j;
    Map = new int*[dimensiune_harta];
    for(i=0; i<dimensiune_harta; i++)
        Map[i] = new int[dimensiune_harta];
    for(i=0; i<dimensiune_harta; i++)
        for(j=0; j<dimensiune_harta; j++)
            Map[i][j]=J.Map[i][j];
}

//functie care returneaza 1 daca jocul s-a terminat si 0 in caz contrar
bool Joc:: gameOver()
{
    if(nr_comori_gasite==3)  // s-a terminat daca am gasit toate comorile
    {
        cout<<"Jocul a luat sfarsit.";
        return 1;
    }
    else
    {
        int i, ok=0;
        for (i=0; i<=3; i++)
            if (c[i]->is_blocat()==1)
                ok++;
        if (ok+nr_comori_gasite==4) //daca fiecare cautator fie a gasit comoara, fie e blocat, jocul s-a terminat
        {
            cout<<"Jocul a luat sfarsit.";
            return 1;
        }
    }
    return 0;
}

// functie care afiseaza matricea Map
void Joc::afisare_harta()
{
    int i, j;
    for(i=0; i<dimensiune_harta; i++)
    {
        for(j=0; j<dimensiune_harta; j++)
            if(Map[i][j]==0)
                cout<<"-"<<" ";
            else  cout<<Map[i][j]<<" ";
        cout<<endl;
    }
}

//verifica daca pozitiile trimise ca parametru indica o zona de pe harta care nu a fost vizitata/marcata inainte sau pe care exista o comoara
bool Joc:: verificare_pozitie(int poz1, int poz2)
{
    if(Map[poz1][poz2]==0 || Map[poz1][poz2]==5)
        return 1;
    return 0;
}

//deplaseaza cautatorii pe harta
void Joc:: deplasare(Cautator *c, int i,  Joc & J, bool &win)
{
    int poz1, poz2, new_poz1, new_poz2,ok;
    if(J.castigator[i]==1)
    {
        cout<<"Cautatorul "<<i<<" a castigat"<<endl;
        return;
    }
    if(c->is_blocat()==1)
    {
        cout<<"Cautatorul "<<i<<" s-a blocat"<<endl;
        return;
    }
    if(J.status[i]!=0) //daca a iesit din joc cautatorul i
    {
        cout<<"Cautatorul "<<i<<" a gasit o comoara"<<endl;
        return;
    }
    ok=c->desfasurare_runda(i, poz1, poz2, new_poz1, new_poz2,J);
    if(ok==0) //daca cautatorul nu s-a putut deplasa
    {
        cout<<"Cautatorul "<<i<<" s-a blocat"<<endl;
        return;
    }
    if(ok!=0)
    {
        if(J.Map[new_poz1][new_poz2]==0)
        {
            if(poz1==new_poz1&&poz2>new_poz2)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta din stanga pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            if(poz1==new_poz1&& poz2<new_poz2)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta din dreapta pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            if(poz2==new_poz2 && poz1>new_poz1)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta de sus pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            if(poz2==new_poz2 && poz1<new_poz1)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta de jos pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            if(poz1>new_poz1 && poz2>new_poz2)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta din stanga sus pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            if(poz1>new_poz1 && poz2<new_poz2)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta din dreapta sus pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            if(poz1<new_poz1 && poz2>new_poz2)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta din stanga jos pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            if(poz1<new_poz1 && poz2<new_poz2)
                cout<<"Cautatorul "<<i<<" s-a deplasat in casuta din dreapta jos pe pozitia "<<"("<<new_poz1<<","<<new_poz2<<")"<<endl;
            J.Map[new_poz1][new_poz2]=i;
            return;
        }
        if( J.Map[new_poz1][new_poz2]==5) //daca a gasit comoara
        {
            if(J.win==0)
            {
                J.castigator[i]=1;
                J.win=1;
                cout<<"Cautatorul "<<i<<" a castigat"<<endl;
            }
            cout<<"Cautatorul "<<i<<" a gasit comoara pe casuta ("<<new_poz1<<","<<new_poz2<<")"<<endl;
            J.Map[new_poz1][new_poz2]=i;
            J.status[i]=1;
            J.nr_comori_gasite++;
            return;
        }
    }
}

//desfasurarea rundei pentru fiecare cautator
void Joc:: runda()
{
    int i;
    for(i=0; i<=3; i++)
        deplasare(c[i],i+1,*this,win);
}
