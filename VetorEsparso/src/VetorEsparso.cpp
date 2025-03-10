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

float VetorEsparso::get(int i)
{
    int k = detInd(i);
    if(k != -1) return tab[k].val;
    else return 0;
}

void VetorEsparso::setInd(int i, float valor)
{
    int k = detInd(i);
    if(k != -1) tab[k].val = valor;
    else
    {
        if(nnz < max)
        {
            tab[nnz].ind = i;
            tab[nnz].val = valor;
            nnz++;
        }
        else cout << "Nao ha espaco no vetor!" << endl;
    }
}
