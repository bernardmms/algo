#include <iostream>
#include "Data.h"
using namespace std;

int main() {
    cout << "=============================================" << endl;
    cout << "      PROGRAMA DE TESTE DA CLASSE DATA       " << endl;
    cout << "=============================================" << endl;

    // Teste 1: Criação de uma data com o construtor padrão (entrada do usuário)
    cout << "\nTESTE 1: Criando uma data com o construtor padrão" << endl;
    cout << "Por favor, insira os dados para a primeira data:" << endl;
    Data data1;

    cout << "Data 1: ";
    data1.imprimeData();
    cout << endl;

    // Teste 2: Criação de uma data com o construtor parametrizado
    cout << "\nTESTE 2: Criando uma data com parâmetros específicos (15/6/2023)" << endl;
    Data data2(15, 6, 2023);

    cout << "Data 2: ";
    data2.imprimeData();
    cout << endl;

    // Teste 3: Modificando uma data existente
    cout << "\nTESTE 3: Modificando a Data 2" << endl;
    cout << "Por favor, insira novos valores para a Data 2:" << endl;
    data2.daySetter();
    data2.monthSetter();
    data2.yearSetter();

    cout << "Data 2 modificada: ";
    data2.imprimeData();
    cout << endl;

    // Teste 4: Calcular o número de dias entre duas datas
    cout << "\nTESTE 4: Calculando o número de dias entre as datas" << endl;
    int diasEntre = data2.numDiasEntre2datas(data1);

    cout << "Número de dias entre ";
    data1.imprimeData();
    cout << " e ";
    data2.imprimeData();
    cout << ": " << diasEntre << " dias" << endl;

    // Teste 5: Verificação dos limites das datas (valores inválidos)
    cout << "\nTESTE 5: Verificando limites (criando data com valores inválidos)" << endl;
    Data dataInvalida(32, 13, -1);

    cout << "Data com valores inválidos (deve ser normalizada): ";
    dataInvalida.imprimeData();
    cout << endl;

    cout << "\n=============================================" << endl;
    cout << "      FIM DO PROGRAMA DE TESTE               " << endl;
    cout << "=============================================" << endl;

    return 0;
}
