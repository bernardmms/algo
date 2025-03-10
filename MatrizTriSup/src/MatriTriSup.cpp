#include "MatrizTriSup.h"
#include <iostream>

MatrizTriSup::MatrizTriSup(int ordem)
{
    n = ordem;
    mat = new float[n * (n + 1) / 2];
}

MatrizTriSup::~MatrizTriSup()
{
    delete[] mat;
}

int MatrizTriSup::getIndex(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
    {
        if (i > j) return -1; // Evita acessar posições inválidas para matriz triangular superior
        return j * (j + 1) / 2 + i; // Fórmula para armazenar a parte superior
    }
    return -1;
}

float MatrizTriSup::getInd(int i, int j)
{
    int k = getIndex(i, j);
    if (k != -1)
    {
        return mat[k];
    }
    else
    {
        std::cerr << "Erro: índice inválido em getInd()" << std::endl;
        exit(1);
    }
}

void MatrizTriSup::setInd(int i, int j, float val)
{
    int k = getIndex(i, j);
    if (k != -1)
    {
        mat[k] = val;
    }
    else
    {
        std::cerr << "Erro: índice inválido em setInd()" << std::endl;
        exit(1);
    }
}
