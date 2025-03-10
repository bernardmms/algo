#include <iostream>
using namespace std;

struct Elemento {
    int linha;
    int coluna;
    int valor;
};

class MatrizListra {
private:
    int m; // número de linhas
    int n; // número de colunas
    Elemento* elementos; // array dinâmico para armazenar elementos não nulos
    int capacidade; // capacidade atual do array
    int tamanho; // quantidade atual de elementos não nulos
    
    // Função auxiliar para verificar se a posição é válida
    bool posicaoValida(int i, int j) const {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    // Função auxiliar para verificar se a coluna é de índice ímpar
    bool colunaImpar(int j) const {
        return (j % 2 == 1);
    }
    
    // Função auxiliar para encontrar um elemento no array
    int encontrarElemento(int i, int j) const {
        for (int k = 0; k < tamanho; k++) {
            if (elementos[k].linha == i && elementos[k].coluna == j) {
                return k;
            }
        }
        return -1; // não encontrado
    }
    
    // Função para redimensionar o array quando necessário
    void redimensionar(int novaCapacidade) {
        Elemento* novoArray = new Elemento[novaCapacidade];
        
        // Copiar elementos existentes
        for (int i = 0; i < tamanho; i++) {
            novoArray[i] = elementos[i];
        }
        
        // Liberar array antigo
        delete[] elementos;
        
        // Atualizar ponteiro e capacidade
        elementos = novoArray;
        capacidade = novaCapacidade;
    }

public:
    // Construtor
    MatrizListra(int linhas, int colunas) {
        if (linhas < 1 || colunas < 2) {
            cerr << "Erro: Dimensões inválidas para a matriz." << endl;
            exit(1);
        }
        m = linhas;
        n = colunas;
        
        // Estimar capacidade inicial (metade das posições em colunas ímpares)
        capacidade = (m * (n / 2 + n % 2)) / 2 + 1;
        tamanho = 0;
        elementos = new Elemento[capacidade];
    }
    
    // Destrutor
    ~MatrizListra() {
        delete[] elementos;
    }
    
    // Verifica se a matriz é quadrada
    bool ehQuadrada() const {
        return (m == n);
    }
    
    // Acessa um elemento da matriz
    int get(int i, int j) const {
        if (!posicaoValida(i, j)) {
            cerr << "Erro: Tentativa de acessar posição inválida (" << i << ", " << j << ")." << endl;
            exit(1);
        }
        
        // Se for coluna par, retorna sempre 0
        if (!colunaImpar(j)) {
            return 0;
        }
        
        // Procura o elemento no array
        int indice = encontrarElemento(i, j);
        if (indice != -1) {
            return elementos[indice].valor;
        }
        
        // Se não encontrou, retorna 0
        return 0;
    }
    
    // Altera um elemento da matriz
    void set(int i, int j, int val) {
        if (!posicaoValida(i, j)) {
            cerr << "Erro: Tentativa de alterar posição inválida (" << i << ", " << j << ")." << endl;
            return;
        }
        
        // Não pode alterar elementos de colunas pares para valores diferentes de zero
        if (!colunaImpar(j) && val != 0) {
            cerr << "Erro: Não é possível atribuir valor diferente de zero a elementos de colunas de índice par." << endl;
            return;
        }
        
        // Se o valor for zero e a coluna for ímpar, verifica se precisa remover do array
        if (val == 0) {
            int indice = encontrarElemento(i, j);
            if (indice != -1) {
                // Remove o elemento do array (move o último elemento para esta posição)
                elementos[indice] = elementos[tamanho - 1];
                tamanho--;
            }
            return;
        }
        
        // Se chegou aqui, estamos atribuindo um valor não nulo a uma posição válida em uma coluna ímpar
        int indice = encontrarElemento(i, j);
        if (indice != -1) {
            // Elemento já existe, atualiza o valor
            elementos[indice].valor = val;
        } else {
            // Elemento não existe, adiciona ao array
            // Se necessário, redimensiona o array
            if (tamanho >= capacidade) {
                redimensionar(capacidade * 2);
            }
            
            elementos[tamanho].linha = i;
            elementos[tamanho].coluna = j;
            elementos[tamanho].valor = val;
            tamanho++;
        }
    }
    
    // Cria uma cópia da matriz atual
    MatrizListra* criaCopia() const {
        MatrizListra* copia = new MatrizListra(m, n);
        
        // Libera o array padrão criado pelo construtor
        delete[] copia->elementos;
        
        // Aloca novo array com capacidade adequada
        copia->capacidade = capacidade;
        copia->tamanho = tamanho;
        copia->elementos = new Elemento[capacidade];
        
        // Copia apenas os elementos não nulos
        for (int i = 0; i < tamanho; i++) {
            copia->elementos[i] = elementos[i];
        }
        
        return copia;
    }
    
    // Método auxiliar para imprimir a matriz (para testes)
    void imprimir() const {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};
