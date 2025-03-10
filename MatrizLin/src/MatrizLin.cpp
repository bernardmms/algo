#include "MatrizLin.h"
#include <iostream>
using namespace std;

MatrizLin::MatrizLin(int l, int c)
{
    nl = l;
    nc = c;

    mat = new int[nl*nc];

    for (int i = 0; i < nl * nc; i++) {
        mat[i] = 0; // Inicializa todos os elementos com zero
    }
}

MatrizLin::~MatrizLin()
{
    delete[] mat;
}

int MatrizLin::getIndex(int i, int j)
{
    if(i >= 0 && i < nl && j >= 0 && j < nc)
        return i*nc + j;
    else
        return -1;
}

int MatrizLin::getInd(int i, int j)
{
    int k = getIndex(i, j);

    if (k != -1) {
        return mat[k];
    } else {
        cout << "Erro: get" << endl;
        exit(1);
    }
}

void MatrizLin::setInd(int i, int j, int val)
{
    int k = getIndex(i, j);

    if (k != -1) {
        mat[k] = val;
    } else {
        cout << "Erro: indice invalido" << endl;
        exit(1);
    }
}

void MatrizLin::imprimeMatriz()
{
    for (int i=0;i<nl*nc;i++)
    {
        if (i%nc == 0)
            cout << endl;
        cout << mat[i] << " ";
    }
    cout << endl;
}

void MatrizLin::transpoeMatriz()
{
    // Criar uma nova matriz para armazenar a transposta
    int *transposta = new int[nc * nl];

    // Preencher a matriz transposta trocando linhas por colunas
    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            int indiceOriginal = getIndex(i, j);
            int indiceTransposto = j * nl + i; // Troca i e j
            transposta[indiceTransposto] = mat[indiceOriginal];
        }
    }

    // Deletar a matriz original e substituir pela transposta
    delete[] mat;
    mat = transposta;

    // Atualizar os valores de linhas e colunas
    int temp = nl;
    nl = nc;
    nc = temp;
}

MatrizLin* MatrizLin::geraTransposta()
{
    // Criar uma nova matriz com dimensões invertidas
    MatrizLin* transposta = new MatrizLin(nc, nl);

    // Preencher a nova matriz com os valores transpostos
    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            transposta->setInd(j, i, getInd(i, j)); // Troca i e j
        }
    }

    // Retorna o ponteiro para a nova matriz transposta
    return transposta;
}

int MatrizLin::getNumLinhas()
{
    return nl;
}

int MatrizLin::getNumColunas()
{
    return nc;
}
