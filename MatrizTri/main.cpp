#include "MatrizTri.h"
#include <iostream>

int main() {
    int ordem = 4; // Define a ordem da matriz triangular inferior
    MatrizTri matriz(ordem);

    // Preenchendo a matriz triangular inferior
    std::cout << "Preenchendo a matriz..." << std::endl;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j <= i; j++) {
            float valor = (i + 1) * 10 + j; // Apenas um padrão para os valores
            matriz.setInd(i, j, valor);
            std::cout << "matriz[" << i << "][" << j << "] = " << valor << std::endl;
        }
    }

    std::cout << "\nValores armazenados na matriz:" << std::endl;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << matriz.getInd(i, j) << " ";
        }
        std::cout << std::endl;
    }

    // Teste de acesso inválido
    std::cout << "\nTentando acessar um índice inválido (2,3):" << std::endl;
    try {
        std::cout << matriz.getInd(2, 3) << std::endl; // Deve gerar um erro
    } catch (...) {
        std::cerr << "Erro capturado: acesso inválido." << std::endl;
    }

    return 0;
}
