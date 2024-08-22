#include <TXLib.h>

#include <stdio.h>
#include <math.h>
#include <assert.h>

// TODO codestyle
// TODO doxygen

enum roots_values
{

    INF_ROOTS  = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2

};

const float EPSILON   = 1e-10;

void input(double *a, double *b, double *c);
int solver(double a, double b, double c, double *x1, double *x2);
int linear_solver(double b, double c, double *x1);
int square_solver(double a, double b, double c, double *x1, double *x2);
void output(int nRoots, double x1, double x2);
void buffer_clean();
bool is_zero(double num);
int test(double a, double b, double c, double x1_exp, double x2_exp, int nRoots_exp);

int main()
{

    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;

/*    struct test_data
    {
        double a;
        double b;
        double c;
        double x1_exp;
        double x2_exp;
        in nRoots_exp;
    }

    test_data test1 = {1, 6, 9, -3, NAN, ONE_ROOT};
    test_data test2 = {0, 6, 12, -2, NAN, ONE_ROOT};
    test_data test3 = {0, 0, 0, NAN, NAN, INF_ROOTS};
    test_data test4 = {1, -3, 2, 1, 2, TWO_ROOTS};

                                                    */

    int nRoots = NAN;

    input(&a, &b, &c);
    nRoots = solver(a, b, c, &x1, &x2);
    output(nRoots, x1, x2);
    test(1, 6, 9, -3, NAN, ONE_ROOT);
    test(0, 6, 12, -2, NAN, ONE_ROOT);
    test(0, 0, 0, NAN, NAN, INF_ROOTS);
    test(1, -3, 2, 1, 2, TWO_ROOTS);

}

void input(double *a, double *b, double *c)
{

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Ёта программа решает уравнение вида ax2+bx+c=0\n");
    printf("¬ведите коэфиценты a,b,c\n");

    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {

        printf("введите корректные числа\n");

        buffer_clean();

    }

}

int solver(double a, double b, double c, double *x1, double *x2)
{

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (is_zero(a))
    {
        linear_solver(b, c, x1);
    }
    else
    {
        square_solver(a, b, c, x1, x2);
    }

}

int square_solver(double a, double b, double c, double *x1, double *x2)
{

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (c == 0)
    {

        linear_solver(a, b, x1);
        *x2 = 0;
        return TWO_ROOTS;

    }
    else
    {

        double discriminant = b * b - 4 * a * c;

        if (discriminant > EPSILON)
        {

            *x1 = (- b + sqrt(discriminant)) / (2 * a);
            *x2 = (- b - sqrt(discriminant)) / (2 * a);

            return TWO_ROOTS;

        }
        else
        {

            if (is_zero(discriminant))
            {

                *x1 = (-b) / (2 * a);

                return ONE_ROOT;

            }
            else
            {                                           //codestyle?
                return ZERO_ROOTS;                      //
            }                                           //

        }

    }
}

int linear_solver(double b, double c, double *x1)
{

    assert(x1 != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (is_zero(b))
    {

        if (is_zero(c))
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

        *x1 = - c / b;

        return ONE_ROOT;

    }

}

void output(int nRoots, double x1, double x2)
{

    switch(nRoots)
        {
        case ZERO_ROOTS:
            printf("EQUATION HAS NO ROOTS\n");
            break;

        case ONE_ROOT:
            printf("EQUATION HAS 1 ROOT:x = %lg\n" ,x1);
            break;

        case TWO_ROOTS:
            printf("EQUATION HAS 2 ROOTS:x1 = %lg, x2 = %lg\n", x1, x2);
            break;

        case INF_ROOTS:
            printf("EQUATION HAS INF ROOTS\n");
            break;

        default:
            printf("ERROR IN ROOTS NUMBER\n");
        }

}

bool is_zero(double num)
{

    if (fabs(num) <= EPSILON)
        return true;
    return false;

}

void buffer_clean()
{
    while (getchar() != '\n')
    {}
}

int test(double a, double b, double c, double x1_exp, double x2_exp, int nRoots_exp)
{
    double x1;
    double x2;

    if (

        solver(a, b, c, &x1, &x2) == nRoots_exp &&
        (x1 == x1_exp || (~isfinite(x1) && ~isfinite(x1_exp))) &&
        (x2 == x2_exp || (~isfinite(x2) && ~isfinite(x2_exp)))

        )
    {
        printf("test is passed\n");
    }
    else
    {

        printf(

              "test is not passed\n"
              "expected values: x1 = %lg, x2 = %lg, Roots number = %d",
               x1_exp, x2_exp, nRoots_exp

             );

    }

}


