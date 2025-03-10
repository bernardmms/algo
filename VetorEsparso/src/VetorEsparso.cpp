#include "VetorEsparso.h"

VetorEsparso::VetorEsparso()
{
    c = cc;
    f = ff;
    maxima = naozeros;
    nnz = 0;
    tab = new Dupla[maxima];
}

VetorEsparso::~VetorEsparso()
{
    delete[] tab;
}

int VetorEsparso::detInd(int i)
{
    if( i >= c && i <= f)
    {
        for(int t = 0; t < nnz; t++)
        {
            if( tab[t].ind == i) return t;
        }
        return -1;
    }
    else
    {
        cout << "Indice invalido:" << endl;
        exit(1);
    }
}
