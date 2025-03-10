#include "Matriz2d.h"
#include <iostream>
using namespace std;

Matriz2d::Matriz2d(int i, int j)
{
    nl = i;
    nc = j;

    mat = new int*[nl]; //vetor de vetores

    for (int ind=0; ind < nl; ind++){
        mat[ind] = new int[nc];
    }

}

Matriz2d::~Matriz2d()
{
    for (int ind=0; ind < nl; ind++){
        delete[] mat[ind];
    }
}

bool Matriz2d::verifica(int i, int j)
{
    if(i >= 0 && i < nl && j >= 0 && j < nc)
        return true;
    else
        return false; // indice invalido
};

int Matriz2d::getI(int i, int j)
{
    if (verifica(i, j))
    {
        return mat[i][j];
    } else
    {
        cout << "Indice invalido!";
        exit(1);
    }
}

void Matriz2d::setI(int i, int j, int val)
{
    if (verifica(i, j))
        mat[i][j] = val;
    else
        cout << "Indice invalido!";
}
