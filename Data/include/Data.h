#ifndef DATA_H
#define DATA_H


class Data
{
    private:
        int dia, mes, ano;
        int numDiasMes [12] = {0,31,59,90,120,151,181,212,243,273,304,334};
        int dataToInt();

    public:
        Data(int d, int m, int a);
        Data();
        ~Data();

        void daySetter();
        void monthSetter();
        void yearSetter();

        void imprimeData();
        int numDiasEntre2datas(Data d);
};

#endif // DATA_H
