#ifndef MATRIZTRISUP_H
#define MATRIZTRISUP_H

class MatrizTriSup
{
    public:
        MatrizTriSup(int ordem);
        ~MatrizTriSup();

        float getInd(int i, int j);
        void setInd(int i, int j, float val);

    private:
        int n; // Ordem da matriz triangular
        float *mat; // Representação linear

        int getIndex(int i, int j); // Calcula o índice no array linear
};

#endif // MATRIZTRISUP_H
