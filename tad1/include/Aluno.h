#ifndef ALUNO_H
#define ALUNO_H
#include <string>
using namespace std;

class Aluno
{
    public:
        Aluno(string name, int m, int i, int n);  // Correção: `n` agora é int
        virtual ~Aluno();

        double calculaMedia();
        void imprimirAluno();
        void foiAprovado();

    private:
        string nome;
        int matricula;
        int idade;
        int n;
        double *notas;
};

#endif
