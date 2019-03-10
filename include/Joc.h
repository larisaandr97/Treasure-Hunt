#ifndef JOC_H
#define JOC_H
#include "Cautator.h"
class Cautator;
class Joc
{
protected:
    Cautator *c[4];
    int **Map;
    int dimensiune_harta;
    bool win; //variabila care devine 1 cand primul cautator a gasit o comoara si a castigat jocul
    int nr_comori_gasite; //variabila incrementata de fiecare data cand o comoara este gasita
    bool status[4]; //0, daca nu a gasit comoara, 1 in caz contrar
    bool castigator[4];//vector de tip bool care indica daca cautatorul i a castigat jocul
    friend class Cautator;
    friend class Cautator_1;
    friend class Cautator_2;
    friend class Cautator_3;
    friend class Cautator_4;
public:
    Joc(int dimensiune); //constructor pentru Joc care are ca parametru dimensiunea matricii Map
    virtual  ~Joc();
    Joc(const Joc &J);
    bool gameOver();
    void afisare_harta();
    bool verificare_pozitie(int poz1, int poz2);
    void runda();
    void deplasare(Cautator *c, int i,Joc &J, bool &win);
};

#endif // JOC_H
