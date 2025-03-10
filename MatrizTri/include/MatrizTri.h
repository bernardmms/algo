#ifndef MATRIZTRI_H
#define MATRIZTRI_H

class MatrizTri
{
    public:
        MatrizTri(int ordem);
        ~MatrizTri(); // Corrigido o til no destrutor

        float getInd(int i, int j);
        void setInd(int i, int j, float val); // Ajustado para float

    private:
        int n; // Ordem da matriz triangular
        float *mat; // Representação linear

        int getIndex(int i, int j); // Método necessário
};

#endif // MATRIZTRI_H
