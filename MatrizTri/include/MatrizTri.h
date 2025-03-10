#ifndef MATRIZTRI_H
#define MATRIZTRI_H


class MatrizTri
{
    public:
        MatrizTriInf(int ordem);
        ∼MatrizTriInf();

        int getInd(int i, int j);
        void setInd(int i, int j, int val);

    private
        int n; // ordem da matriz triangular
        int *vet; // representacao linear

        bool verifica(int i, int j);
};

#endif // MATRIZTRI_H
