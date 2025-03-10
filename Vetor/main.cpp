#include "Vetor.h"
#include <iostream>
using namespace std;

int main() {
    int tamanho = 5;
    Vetor v(tamanho);

    // Testando setI e getI
    for (int i = 0; i < tamanho; i++) {
        v.setI(i, (i + 1) * 10);
    }

    cout << "Valores do vetor:" << endl;
    v.imprimeVet();

    // Testando acesso individual
    cout << "\nTestando getI:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "v[" << i << "] = " << v.getI(i) << endl;
    }

    return 0;
}
