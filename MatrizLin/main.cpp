#include <iostream>
#include "MatrizLin.h"

using namespace std;

int* prodMatVetor(MatrizLin *m, int *v)
{
    int nl = m->getNumLinhas(); // Método para obter o número de linhas
    int nc = m->getNumColunas(); // Método para obter o número de colunas

    // Criar o vetor resultado dinamicamente
    int* resultado = new int[nl];

    // Multiplicação da matriz pelo vetor
    for (int i = 0; i < nl; i++)
    {
        resultado[i] = 0; // Inicializa o resultado da linha i
        for (int j = 0; j < nc; j++)
        {
            resultado[i] += m->getInd(i, j) * v[j];
        }
    }

    return resultado;
}

int main()
{
    int m = 7, n = 11;
    MatrizLin mat(m, n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            int val = j + n*i;
            mat.setInd(i, j, val);
        }

    mat.imprimeMatriz();

    MatrizLin matriz(3, 3);

    // Preenchendo a matriz com valores exemplo
    matriz.setInd(0, 0, 1); matriz.setInd(0, 1, 2); matriz.setInd(0, 2, 3);
    matriz.setInd(1, 0, 4); matriz.setInd(1, 1, 5); matriz.setInd(1, 2, 6);
    matriz.setInd(2, 0, 7); matriz.setInd(2, 1, 8); matriz.setInd(2, 2, 9);

    // Criando um vetor de exemplo
    int vetor[3] = {1, 2, 3};

    // Calculando o produto da matriz pelo vetor
    int* resultado = prodMatVetor(&matriz, vetor);

    // Imprimindo o resultado
    cout << "Resultado da multiplicação matriz x vetor:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << resultado[i] << " ";
    }
    cout << endl;

    // Liberando a memória alocada
    delete[] resultado;

    return 0;
}
