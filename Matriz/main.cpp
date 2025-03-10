#include "Matriz2d.h"
#include <iostream>
using namespace std;

int main() {
    const int tamanho = 5;
    Matriz2d matriz(tamanho, tamanho);

    // (a) Ler 25 valores e preencher a matriz linha por linha
    cout << "Digite 25 valores inteiros para preencher a matriz 5x5:" << endl;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int valor;
            cin >> valor;
            matriz.setI(i, j, valor);
        }
    }

    // (b) Imprimir a 4ª coluna (índice 3)
    cout << "\n4ª coluna da matriz:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << matriz.getI(i, 3) << " ";
    }
    cout << endl;

    // (c) Modificar um valor da matriz
    int linha, coluna, novoValor;
    cout << "\nDigite o índice da linha, o índice da coluna e o novo valor:" << endl;
    cin >> linha >> coluna >> novoValor;
    matriz.setI(linha, coluna, novoValor);

    // (d) Imprimir a matriz transposta
    cout << "\nMatriz transposta:" << endl;
    for (int j = 0; j < tamanho; j++) {
        for (int i = 0; i < tamanho; i++) {
            cout << matriz.getI(i, j) << " ";
        }
        cout << endl;
    }

    // (e) Determinar o maior valor da diagonal secundária
    int maiorValor = matriz.getI(0, tamanho - 1);
    for (int i = 1; i < tamanho; i++) {
        if (matriz.getI(i, tamanho - 1 - i) > maiorValor) {
            maiorValor = matriz.getI(i, tamanho - 1 - i);
        }
    }
    cout << "\nMaior valor da diagonal secundária: " << maiorValor << endl;

    return 0;
}
