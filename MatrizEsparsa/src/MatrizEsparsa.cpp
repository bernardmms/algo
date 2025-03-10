#include "MatrizEsparsa.h"

MatrizEsparsa::MatrizEsparsa(int a1, int b1, int a2, int b2, int n)
{
    c1 = a1;
    f1 = b1;
    c2 = a2;
    f2 = b2;
    int folga = ((f1-c1+1)*(f2-c2+1)) * 0.1;
    max = n + folga;
    nnz = 0;
    tab = new Tripla[max];
// inicializa tab com triplas de folga
    for(int i = 0; i < max; i++)
    {
        tab[i].lin = f1 + 1;
        tab[i].col = f2 + 1;
        tab[i].val = 0.0;
    }
}

MatrizEsparsa::~MatrizEsparsa()
{
    //dtor
}

int MatrizEsparsa::detInd(int i, int j)
{
    if(i >= c1 && i <= f1 && j >= c2 && j <= f2)
    {
        int k = -1;
        for(int t = 0; t < nnz; t++)
        {
            if(tab[t].lin == i && tab[t].col == j)
            {
                k = t;
                break;
            }
        }
        return k;
    }
    else
    {
        cout << "Indice invalido!" << endl;
        exit(1);
    }
}

float MatrizEsparsa::get(int i, int j)
{
    int k = detInd(i, j);
    if(k != -1) return tab[k].val;
    else return 0;
}
void MatrizEsparsa::set(int i, int j, float valor)
{
    int k = detInd(i, j);
    if(k != -1)
    {
        if(valor == 0.0)
            remove(k);
        else
            tab[k].val = valor;
    }
    else if (valor != 0.0)
        insere(i, j, valor);
}

void MatrizEsparsa::remove(int k)
{
    int t;
// remove a tripla da posicao k de tab
    for(t = k; t < nnz-1; t++)
    {
// desloca triplas de (k+1) a nnz p/ esq
        tab[t].lin = tab[t+1].lin;
        tab[t].col = tab[t+1].col;
        tab[t].val = tab[t+1].val;
    }
// inclui uma tripla de folga
    tab[nnz].lin = f1+1;
    tab[nnz].col = f2+1;
    tab[nnz].val = 0.0;
    nnz--;
}

void MatrizEsparsa::insere(int i, int j, float valor)
{
    if(nnz < max)
    {
        int t = 0;
// inserir o indice na ordem correta
        while(t < nnz)
        {
            if(tab[t].lin > i) break;
            if(tab[t].lin == i && tab[t].col > j) break;
            t++;
        }
        for(int m = nnz; m > t; m--)
        {
//desloca para direita ate t para abrir espaco
            tab[m].lin = tab[m-1].lin;
            tab[m].col = tab[m-1].col;
            tab[m].val = tab[m-1].val;
        }
// insere tripla na posicao t
        tab[t].lin = i;
        tab[t].col = j;
        tab[t].val = valor;
        nnz++;
    }
    else
        cout << "Nao ha espaco!" << endl;
}
