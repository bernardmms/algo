#ifndef MATRIZLIN_H
#define MATRIZLIN_H


class MatrizLin
{
    public:
        MatrizLin(int l, int c);
        virtual ~MatrizLin();

        int getInd(int i, int j);
        void setInd(int i, int j, int val);
        void imprimeMatriz();
        void transpoeMatriz();
        MatrizLin* geraTransposta();

        int getNumLinhas();
        int getNumColunas();


    private:
        int nl, nc;
        int *mat;

        int getIndex(int i, int j);
};

#endif // MATRIZLIN_H
