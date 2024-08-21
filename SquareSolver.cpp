#include <TXLib.h>

#include <stdio.h>
#include <math.h>

// TODO codestyle
// TODO git

// epsilon - 1e-10;
// abs(value) < eps   bool


// TODO читать про switch и все остальное     if  и определени€ функций
// TODO разбить на функции input solver output
                     // TODO rename file

const int INF_ROOTS = -1;
const int ZERO_ROOTS = 0;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const float EPSILON = 1e-10;

int input(double *a, double *b, double *c);
int solver(double a, double b, double c, double *x1, double *x2);
int output(int nRoots, double x1, double x2);
bool comparator(double num);

int main()
{

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;

    int nRoots = 0;

    input(&a, &b, &c);
    nRoots = solver(a, b, c, &x1, &x2);
    output(nRoots, x1, x2);
}

int input(double *a, double *b, double *c)
{
    printf("Ёта программа решает уравнение вида ax2+bx+c=0\n");      //
    printf("¬ведите коэфиценты a,b,c\n");

    int nRoots = 0;//

    scanf("%lg %lg %lg", a, b, c);

    return 0; // void
}

int solver(double a, double b, double c, double *x1, double *x2)
{
                                        // codestyle 2 + 3
    int nRoots = 0;

    if (comparator(a))
    {
        if (comparator(b))
        {
            if (comparator(c))
            {
                return INF_ROOTS;
            }
            else
            {
                return ZERO_ROOTS;
            }
        }
        else
        {
            *x1 = (-c) / b;

            return ONE_ROOT;
        }
    }
    else
    {
        double discriminant = b*b - 4*a*c;
        if (discriminant > EPSILON)   // zero?
        {

            *x1 = (- b + sqrt(discriminant)) / (2*a);
            *x2 = (- b - sqrt(discriminant)) / (2*a);

            return TWO_ROOTS;
            }
        else
            if (comparator(discriminant))
            {

                *x1=(-b) / (2*a);

                return ONE_ROOT;
            }
            else
                return ZERO_ROOTS;
    }

}

int output(int nRoots, double x1, double x2)
{
    switch(nRoots)
        {
        case ZERO_ROOTS:
            printf("EQUATION HAS NO ROOTS");
            break;

        case ONE_ROOT: printf("EQUATION HAS 1 ROOT:x = %lg" ,x1);
                break;

        case TWO_ROOTS: printf("EQUATION HAS 2 ROOTS:x1 = %lg, x2 = %lg", x1, x2);
                break;

        case INF_ROOTS: printf("EQUATION HAS INF ROOTS");    // default
        }

    return 0;    //
}

bool comparator(double num)
{
    if (fabs(num) < EPSILON)
        return true;
    else
        return false;
}
