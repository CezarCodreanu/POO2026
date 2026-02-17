#include "header.h"

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

int main(int argc, char* argv[])
{
    char input[] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[6] = {Mul, Sum, 0, Dif, 0, Div};
    int S = 0, V;
    cout << strlen(input) << endl;
    Content x = {0, 0};
    int idx = -1;

    for (int i = 0; i < strlen(input); i++)
    {
        idx = -1;
        switch (input[i] - 42)
        {
            case INMULTIRE:
                idx = 0;
                x.p1 = 3;
                x.p2 = 2;
                break;
            case SUMA:
                idx = 1;
                x.p1 = 15;
                x.p2 = 5;
                break;
            case DIFERENTA:
                idx = 3;
                x.p1 = 12;
                x.p2 = 1;
                break;
            case IMPARTIRE:
                idx = 5;
                x.p1 = 4;
                x.p2 = 2;
                break;
        }

        if (idx != -1)
            S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);

    return 0;
}
