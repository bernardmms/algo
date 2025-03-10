#ifndef VETOR_H
#define VETOR_H


class Vetor
{
    public:
        Vetor(int in, int fi);
        virtual ~Vetor();

        void setI(int i, int val);
        int getI(int i);

        void imprimeVet();

    private:
        int inicio;
        int fim;
        int tam;
        int *vet;
};

#endif // VETOR_H
