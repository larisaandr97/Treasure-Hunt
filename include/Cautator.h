#ifndef CAUTATOR_H
#define CAUTATOR_H
#include "Joc.h"
class Joc;
class Cautator
{
protected:
    int pozitie_curenta1; //indicele liniei
    int pozitie_curenta2; //indicele coloanei
    bool blocat;
public:
    Cautator(const Joc &J);
    Cautator(int pozitie1, int pozitie2, const Joc &J);
    Cautator();
    virtual ~Cautator(); //destructor
    bool is_blocat(); //returneaza valoarea variabilei blocat
    bool miscare_stanga(int &poz1, int& poz2, int &new_poz1, int  &new_poz2,const Joc &J);
    bool miscare_dreapta(int& poz1, int &poz2, int &new_poz1, int  &new_poz2,const Joc &J);
    bool miscare_sus(int &poz1, int &poz2, int &new_poz1, int  &new_poz2,const Joc &J);
    bool miscare_jos(int &poz1, int &poz2, int &new_poz1, int  &new_poz2,const Joc &J);
    bool miscare_stanga_sus(int &poz1, int& poz2, int &new_poz1, int  &new_poz2, const Joc &J);
    bool miscare_dreapta_sus(int &poz1, int& poz2, int &new_poz1, int & new_poz2,const Joc &J);
    bool miscare_stanga_jos(int &poz1, int& poz2, int &new_poz1, int & new_poz2,const Joc &J);
    bool miscare_dreapta_jos(int &poz1, int &poz2, int &new_poz1, int & new_poz2,const Joc &J);
    virtual bool desfasurare_runda (int i, int &poz1, int &poz2, int &new_poz1, int &new_poz2, Joc &J)=0;
};

class Cautator_1: public Cautator
{
public:
    Cautator_1(const Joc &J);
    virtual ~Cautator_1();
    Cautator_1(const Cautator_1 & C);
    Cautator_1(int pozitie1, int pozitie2, const Joc &J);
    bool desfasurare_runda ( int i,int &poz1, int &poz2, int &new_poz1, int &new_poz2, Joc &J);
};

class Cautator_2: public Cautator
{
public:
    Cautator_2(const Joc &J);
    virtual ~Cautator_2();
    Cautator_2(int pozitie1, int pozitie2, const Joc &J);
    bool desfasurare_runda ( int i,int &poz1, int &poz2, int &new_poz1, int &new_poz2, Joc &J);
};

class Cautator_3: public Cautator
{
public:
    Cautator_3(const Joc &J);
    virtual ~Cautator_3();
    Cautator_3(int pozitie1, int pozitie2, const Joc &J);
    bool desfasurare_runda (int i, int &poz1, int &poz2, int &new_poz1, int &new_poz2, Joc &J);
};

class Cautator_4: public Cautator
{
public:
    Cautator_4(const Joc &J);
    virtual ~Cautator_4();
    Cautator_4(int pozitie1, int pozitie2, const Joc &J);
    bool desfasurare_runda (int i, int &poz1, int &poz2, int &new_poz1, int &new_poz2,Joc &J);
};

#endif // CAUTATOR_H
