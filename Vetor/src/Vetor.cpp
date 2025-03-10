#include "Vetor.h"
#include <iostream>
using namespace std;

Vetor::Vetor(int in, int fi)
{
    inicio = in;
    fim = fi;
    tam = fi-in;
    vet = new int[tam];

    for (int j=0; i<tam; i++){
        vet[j] = 0;
    }
}

Vetor::~Vetor()
{
    delete[] vet;
}

void Vetor::setI(int i, int val)
{
    int indice = i-inicio;

    if (indice<tam || indice>tam){
        vet[indice] = val;
    } else {
        cout << "Indice invalido!";
    }
}

int Vetor::getI(int i)
{
    if (i<tam){
        return vet[i];
    } else {
        cout << "Indice invalido!";
        return -1;
    }
}

void Vetor::imprimeVet()
{
    for (int i=0; i<tam; i++){
        cout << "Indice " << i << " do vetor: " << vet[i] << endl;
    }
}
