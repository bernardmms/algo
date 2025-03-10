#include "Aluno.h"
#include <iostream>
#include <string>

using namespace std;

Aluno::Aluno(string name, int m, int i, int num)  // Correção: tipo de `num` igual ao do cabeçalho
{
    nome = name;
    matricula = m;
    idade = i;
    n = num;
    notas = new double[n];  // Correção: alocar corretamente

    for (int i = 0; i < n; i++){
        cout << "Insira a nota " << i + 1 << " do aluno: ";
        cin >> notas[i];
    }
}

Aluno::~Aluno()
{
    cout << "Destruindo aluno " << nome << endl;
    delete[] notas; // Evita vazamento de memória
}

double Aluno::calculaMedia() // Corrigido: método da classe
{
    double soma = 0.0;
    for (int i = 0; i < n; i++){
        soma += notas[i];
    }
    return soma / n;
}

void Aluno::foiAprovado()
{
    double media = this->calculaMedia(); // Chamada correta do método
    if (media >= 7.0){
        cout << "Aluno aprovado!" << endl;
    } else {
        cout << "Aluno reprovado!" << endl;
    }
}

void Aluno::imprimirAluno()
{
    double media = this->calculaMedia(); // Chamada correta

    cout << "Aluno:      " << nome << endl;
    cout << "Matricula:  " << matricula << endl;
    cout << "Idade:      " << idade << endl;
    cout << "Nota Média: " << media << endl;
    foiAprovado();
}
