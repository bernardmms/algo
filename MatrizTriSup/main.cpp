#include "MatrizTriSup.h"
#include <iostream>

int main() {
    int ordem = 4; // Define a ordem da matriz triangular superior
    MatrizTriSup matriz(ordem);

    // Preenchendo a matriz triangular superior
    std::cout << "Preenchendo a matriz..." << std::endl;
    for (int i = 0; i < ordem; i++) {
        for (int j = i; j < ordem; j++) {
            float valor = (i + 1) * 10 + j; // Apenas um padrão para os valores
            matriz.setInd(i, j, valor);
            std::cout << "matriz[" << i << "][" << j << "] = " << valor << std::endl;
        }
    }

    std::cout << "\nValores armazenados na matriz:" << std::endl;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            if (i <= j)
                std::cout << matriz.getInd(i, j) << " ";
            else
                std::cout << "  -  "; // Espaço para manter a matriz alinhada
        }
        std::cout << std::endl;
    }

    // Teste de acesso inválido
    std::cout << "\nTentando acessar um índice inválido (3,1):" << std::endl;
    try {
        std::cout << matriz.getInd(3, 1) << std::endl; // Deve gerar um erro
    } catch (...) {
        std::cerr << "Erro capturado: acesso inválido." << std::endl;
    }

    return 0;
}
