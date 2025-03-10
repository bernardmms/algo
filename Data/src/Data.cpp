#include "Data.h"
#include <iostream>
using namespace std;

void Data::daySetter()
{
    cout << "Qual é o dia? ";
    cin >> dia;
    cout << endl;

    if (dia < 1 || dia > 31){
        dia = 1;
    }
}

void Data::monthSetter()
{
    cout << "Qual é o mês? ";
    cin >> mes;
    cout << endl;

    if (mes < 1 || mes > 12){
        mes = 1;
    }
}

void Data::yearSetter()
{
    cout << "Qual é o ano? ";
    cin >> ano;
    cout << endl;

    if (ano < 1){
        ano = 1900;
    }
}

Data::Data()
{
    this->daySetter();
    this->monthSetter();
    this->yearSetter();
}

Data::~Data()
{
    //dtor
}

Data::Data(int d, int m, int a)
{
    // Validação dos parâmetros
    if (d < 1 || d > 31) {
        dia = 1;
    } else {
        dia = d;
    }

    if (m < 1 || m > 12) {
        mes = 1;
    } else {
        mes = m;
    }

    if (a < 1) {
        ano = 1900;
    } else {
        ano = a;
    }
}

int Data::dataToInt()
{
    int num;

    num = 365*(ano-1) + numDiasMes[mes-1] + dia;

    return num;
}

int Data::numDiasEntre2datas(Data d)
{
    int inicio = d.dataToInt();
    int fim = this->dataToInt();

    return fim - inicio;
}

void Data::imprimeData()
{
    cout << dia << "/" << mes << "/" << ano;
}
