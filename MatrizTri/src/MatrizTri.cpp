#include "MatrizTri.h"
#include <iostream>
using namespace std;

MatrizTri::MatrizTri(int ordem)
{
    n = ordem;

    mat = new int[n];
}

MatrizTri::~MatrizTri()
{
    delete[] mat;
}

int MatrizTri::getIndex(int i, int j)
{
    if(i >= 0 && i < nl && j >= 0 && j < nc)
        return i*nc + j;
    else
        return -1;
}

int MatrizTri::getInd(int i, int j)
{
    int k = getIndex(i, j);

    if (k != -1) {
        return mat[k];
    } else {
        cout << "Erro: get" << endl;
        exit(1);
    }
}

void MatrizTri::setInd(int i, int j, int val)
{
    int k = getIndex(i, j);

    if (k != -1) {
        mat[k] = val;
    } else {
        cout << "Erro: indice invalido" << endl;
        exit(1);
    }
}
