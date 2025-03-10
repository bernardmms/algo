#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H

typedef struct
{
    int lin;
    int col;
    float val;
}

class MatrizEsparsa
{
private:
    int c1, f1; // limites do indice de linha
    int c2, f2; // limites do indice de coluna
    int max; // capacidade maxima do vetor
    int nnz; // numero de nao-zeros (triplas)
    Tripla *tab; // vetor de registros
    int detInd(int i, int j);
    void remove(int k);
    void insere(int i, int j, float valor);
public:
    MatrizEsparsa(int i1,int i2,int j1,int j2,int n);
    ~MatrizEsparsa();
    float get(int i, int j);
    void set(int i, int j, float valor);
};

#endif // MATRIZESPARSA_H
