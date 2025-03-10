#include "MatrizTri.h"
#include <iostream>

MatrizTri::MatrizTri(int ordem)
{
    n = ordem;
    mat = new float[n*(n+1)/2];
}

MatrizTri::~MatrizTri()
{
    delete[] mat;
}

int MatrizTri::getIndex(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < n)
    {
        if (j > i) return -1; // Evita acessar posições inválidas para matriz triangular inferior
        return i*(i+1)/2 + j;
    }
    return -1;
}

float MatrizTri::getInd(int i, int j)
{
    int k = getIndex(i, j);
    if (k != -1) {
        return mat[k];
    } else {
        std::cerr << "Erro: índice inválido em getInd()" << std::endl;
        exit(1);
    }
}

void MatrizTri::setInd(int i, int j, float val)
{
    int k = getIndex(i, j);
    if (k != -1) {
        mat[k] = val;
    } else {
        std::cerr << "Erro: índice inválido em setInd()" << std::endl;
        exit(1);
    }
}
