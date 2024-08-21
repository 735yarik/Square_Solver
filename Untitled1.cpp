#include <TXLib.h>

#include <stdio.h>
#include <math.h>

// TODO codestyle
// TODO git


// TODO читать про switch и все остальное     if  и определения функций
// TODO разбить на функции input solver output


const int INF_ROOTS = -1;

int main()
{
    printf("эта программа решает уравнение вида ax2+bx+c=0\n");      //
    printf("введите коэфиценты a,b,c\n");

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;

    int nRoots = 0;

    scanf("%lg %lg %lg", &a, &b, &c);

    discriminant = b*b-4*a*c

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                nRoots = INF_ROOTS;
            }
            else
            {
                nRoots = 0;
            }
        }
        else
        {
            nRoots = 1;

            x1 = (-c)/b;
        }
    }
    else
        if (discriminant > 0)
            {
            nRoots = 2;

            x1 = (-b + sqrt(discriminant))/(2*a);
            x2 = (-b - sqrt(discriminant))/(2*a);
            }
        else
            if (discriminant == 0)
            {
            nRoots = 1;

            x1=(-b) / (2*a);
            }

    switch(nRoots)
        {
        case 0: printf("EQUATION HAS NO ROOTS");
                break;

        case 1: printf("EQUATION HAS 1 ROOT:x = %lg" ,x1);
                break;

        case 2: printf("EQUATION HAS 2 ROOTS:x1 = %lg, x2 = %lg", x1, x2);
                break;

        case INF_ROOTS: printf("EQUATION HAS INF ROOTS");    // default
        }

    return 0;
}
