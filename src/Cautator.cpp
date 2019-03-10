#include "Cautator.h"
#include <iostream>

using namespace std;

//constructor clasa Cautator
Cautator::Cautator(const Joc &J)
{

}

//destructor clasa Cautator
Cautator::~Cautator()
{

}

//constructor cu 3 parametri pentru clasa Cautator
Cautator :: Cautator(int pozitie1, int pozitie2, const Joc &J)
{
    pozitie_curenta1=pozitie1;
    pozitie_curenta2=pozitie2;

}

//returneaza valoarea booleana a variabilei blocat:0-daca respectivul cautator a ramas blocat si 1 in caz contrat
bool Cautator:: is_blocat()
{
    return blocat;
}

//verificare a posibilitatii miscarii in stanga si memorarea pozitiilor de dupa si inainte de deplasare
bool  Cautator:: miscare_stanga( int &poz1, int &poz2,int &new_poz1, int &new_poz2,const Joc &J)
{
    if(pozitie_curenta2-1<J.dimensiune_harta && pozitie_curenta2-1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1;
        new_poz2=pozitie_curenta2;
        return 1;
    }
    return 0;
}

//verificare a posibilitatii miscarii in dreapta si memorarea pozitiilor de dupa si inainte de deplasare
bool Cautator:: miscare_dreapta(int &poz1, int &poz2, int &new_poz1, int & new_poz2,const Joc &J)
{
    if(pozitie_curenta2+1<J.dimensiune_harta && pozitie_curenta2+1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1;
        new_poz2=pozitie_curenta2+1;
        return 1;
    }
    return 0;
}

//verificare a posibilitatii miscarii in sus si memorarea pozitiilor de dupa si inainte de deplasare
bool Cautator::miscare_sus(int &poz1, int &poz2,int &new_poz1, int & new_poz2,const Joc &J)
{
    if(pozitie_curenta1-1<J.dimensiune_harta && pozitie_curenta1-1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1-1;
        new_poz2=pozitie_curenta2;
        return 1;
    }
    return 0;
}

//verificare a posibilitatii miscarii in jos si memorarea pozitiilor de dupa si inainte de deplasare
bool Cautator:: miscare_jos(int &poz1, int &poz2,int &new_poz1, int & new_poz2,const Joc &J)
{
    if(pozitie_curenta1+1<J.dimensiune_harta && pozitie_curenta1+1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1+1;
        new_poz2=pozitie_curenta2;
        return 1;
    }
    return 0;
}

//verificare a posibilitatii miscarii in stanga sus si memorarea pozitiilor de dupa si inainte de deplasare
bool Cautator:: miscare_stanga_sus(int &poz1, int &poz2,int &new_poz1, int & new_poz2, const Joc &J )
{
    if(pozitie_curenta1-1<J.dimensiune_harta && pozitie_curenta1-1>=0 && pozitie_curenta2-1<J.dimensiune_harta && pozitie_curenta2-1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1-1;
        new_poz2=pozitie_curenta2-1;
        return 1;
    }
    return 0;
}

//verificare a posibilitatii miscarii in dreapta sus si memorarea pozitiilor de dupa si inainte de deplasare
bool Cautator:: miscare_dreapta_sus(int &poz1, int &poz2,int &new_poz1, int & new_poz2,const Joc &J)
{
    if(pozitie_curenta1-1<J.dimensiune_harta && pozitie_curenta1-1>=0 && pozitie_curenta2+1<J.dimensiune_harta && pozitie_curenta2+1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1-1;
        new_poz2=pozitie_curenta2+1;
        return 1;
    }
    return 0;
}

//verificare a posibilitatii miscarii in stanga jos si memorarea pozitiilor de dupa si inainte de deplasare
bool Cautator:: miscare_stanga_jos(int &poz1, int &poz2,int &new_poz1, int & new_poz2,const Joc &J)
{
    if(pozitie_curenta1+1<J.dimensiune_harta && pozitie_curenta1+1>=0 && pozitie_curenta2-1<J.dimensiune_harta && pozitie_curenta2-1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1+1;
        new_poz2=pozitie_curenta2-1;
        return 1;
    }
    return 0;
}

//verificare a posibilitatii miscarii in dreapta jos si memorarea pozitiilor de dupa si inainte de deplasare
bool Cautator:: miscare_dreapta_jos(int &poz1, int &poz2,int &new_poz1, int & new_poz2, const Joc &J)
{
    if(pozitie_curenta1+1<J.dimensiune_harta && pozitie_curenta1+1>=0 && pozitie_curenta2+1<J.dimensiune_harta && pozitie_curenta2+1>=0)
    {
        poz1=pozitie_curenta1;
        poz2=pozitie_curenta2;
        new_poz1=pozitie_curenta1+1;
        new_poz2=pozitie_curenta2+1;
        return 1;
    }
    return 0;
}

//constructor clasa Cautator_1
Cautator_1:: Cautator_1 (const Joc &J):Cautator(J)
{
    blocat=0;
}

//destructor clasa Cautator_1
Cautator_1::~Cautator_1()
{

}

//constructor clasa Cautator_1 cu 3 parametri
Cautator_1 :: Cautator_1(int pozitie1, int pozitie2, const Joc &J):Cautator(J)
{
    pozitie_curenta1=pozitie1;
    pozitie_curenta2=pozitie2;
    blocat=0;

}

//deplaseaza cautatorul 1 pe harta si ii actualizeaza pozitia
bool Cautator_1:: desfasurare_runda (int i,int &poz1, int &poz2, int &new_poz1, int &new_poz2,  Joc &J)
{
    if(miscare_dreapta_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga_sus(poz1, poz2, new_poz1, new_poz2, J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1 ;
        }
    blocat=1;
    return 0;
}

//constructor clasa Cautator_2
Cautator_2:: Cautator_2 (const Joc &J):Cautator(J)
{
    blocat=0;

}

//destructor clasa Cautator_2
Cautator_2::~Cautator_2()
{

}

//constructor pentru clasa Cautator_2 cu 3 parametri
Cautator_2 :: Cautator_2(int pozitie1, int pozitie2, const Joc &J):Cautator(J)
{
    pozitie_curenta1=pozitie1;
    pozitie_curenta2=pozitie2;
    blocat=0;
}

//deplaseaza cautatorul 2 pe harta si ii actualizeaza pozitia
bool Cautator_2:: desfasurare_runda (int i,int &poz1, int &poz2, int &new_poz1, int &new_poz2,  Joc&J)
{
    if(miscare_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1 ;
        }
    if(miscare_dreapta_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    blocat=1;
    return 0;
}

//constructor clasa Cautator_3
Cautator_3:: Cautator_3 (const Joc &J):Cautator(J)
{
    blocat=0;
}

//destructor clasa Cautator_3
Cautator_3::~Cautator_3()
{

}

//constructor clasa Cautator_3 cu 3 parametri
Cautator_3 :: Cautator_3(int pozitie1, int pozitie2, const Joc &J):Cautator(J)
{
    pozitie_curenta1=pozitie1;
    pozitie_curenta2=pozitie2;
    blocat=0;
}

//deplaseaza cautatorul 1 pe harta si ii actualizeaza pozitia
bool Cautator_3:: desfasurare_runda (int i,int &poz1, int &poz2, int &new_poz1, int &new_poz2, Joc &J)
{
    if(miscare_stanga_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1 ;
        }
    if(miscare_stanga(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    blocat=1;
    return 0;
}

//constructor clasa Cautator_4
Cautator_4:: Cautator_4 (const Joc &J):Cautator(J)
{
    blocat=0;
}

//destructor clasa Cautator_4
Cautator_4::~Cautator_4()
{

}

//constructor clasa Cautator_4 cu 3 parametri
Cautator_4 :: Cautator_4(int pozitie1, int pozitie2, const Joc &J):Cautator(J)
{
    pozitie_curenta1=pozitie1;
    pozitie_curenta2=pozitie2;
    blocat=0;
}

//deplaseaza cautatorul 1 pe harta si ii actualizeaza pozitia
bool Cautator_4:: desfasurare_runda (int i,int &poz1, int &poz2, int &new_poz1, int &new_poz2, Joc &J)
{
    if(miscare_dreapta(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1 ;
        }
    if(miscare_stanga(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta_sus(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_stanga_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    if(miscare_dreapta_jos(poz1, poz2, new_poz1, new_poz2,J)!=0)
        if(J.verificare_pozitie(new_poz1, new_poz2)!=0)
        {
            pozitie_curenta1=new_poz1;
            pozitie_curenta2=new_poz2;
            return 1;
        }
    blocat=1;
    return 0;
}
