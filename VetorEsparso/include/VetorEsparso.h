#ifndef VETORESPARSO_H
#define VETORESPARSO_H


struct Dupla
{
    int ind;
    float val;
};

class VetorEsparso
{
    public:
        VetorEsparso(int cc, int ff, int naozeros);
        virtual ~VetorEsparso();
        float get(int i);
        void setInd(int i);

    private:
        int c, f;
        int maxima;
        int nnz;
        Dupla *tab;
        int detInd(int i);
};

#endif // VETORESPARSO_H
