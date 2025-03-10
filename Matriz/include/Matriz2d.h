#ifndef MATRIZ2D_H
#define MATRIZ2D_H


class Matriz2d
{
    public:
        Matriz2d(int i, int j);
        virtual ~Matriz2d();

        int getI(int i, int j);
        void setI(int i, int j, int val);

    private:
        int nl;
        int nc;
        int **mat;

        bool verifica(int i, int j);

};

#endif // MATRIZ2D_H
