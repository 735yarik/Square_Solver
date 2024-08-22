#include <TXLib.h>

#include <stdio.h>
#include <math.h>
#include <assert.h>

// TODO codestyle

// TODO read assert, doxygen

enum roots_values
{

    INF_ROOTS  = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2

};

enum modes
{

    TEST_MODE    = 0,
    SOLVER_MODE  = 1,

};

const double EPSILON   = 1e-10;

struct Coef
{

    double a;
    double b;
    double c;

};

struct test_roots
{

    double x1_exp;
    double x2_exp;

    int nRoots_exp;

};

void input(Coef *abc);

int  solver(double a, double b, double c, double *x1, double *x2);
int  linear_solver(double b, double c, double *x1, double *x2);
int  square_solver(double a, double b, double c, double *x1, double *x2);

void output(int nRoots, double x1, double x2);

void buffer_clean();
bool is_zero(double num);
bool is_equal(double num1, double num2);
int  unit_test(Coef coef_values, test_roots roots_values);
int  execute_tests();
int  solver_or_test_mode();
void test_mode();
void solver_mode();

int main()
{

    int mode = solver_or_test_mode();

    switch(mode)
        {
        case TEST_MODE:

            printf("TEST_MODE\n");
            test_mode();
            break;

        case SOLVER_MODE:

            printf("SOLVER_MODE\n");
            solver_mode();
            break;

        }

}

void input(Coef *abc) //struct Coef abc
{

    assert(abc->a != NULL);
    assert(abc->b != NULL);
    assert(abc->c != NULL);

    //

    printf("Эта программа решает уравнение вида ax2+bx+c=0\n");
    printf("Введите коэфиценты a,b,c\n");

    while (scanf("%lg %lg %lg", abc->a, abc->b, abc->c) != 3)
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
        linear_solver(b, c, x1, x2);
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

        *x1 = (-b) / (2 * a);
        *x2 = 0;

        return TWO_ROOTS;

    }
    else
    {

        double discriminant = b * b - 4 * a * c;

        if (discriminant > EPSILON)
        {

            *x1 = (- b - sqrt(discriminant)) / (2 * a);
            *x2 = (- b + sqrt(discriminant)) / (2 * a);

            return TWO_ROOTS;

        }
        else
        {

            if (is_zero(discriminant))
            {

                *x1 = (-b) / (2 * a);
                *x2 = (-b) / (2 * a);

                return ONE_ROOT;

            }
            else
            {

                *x1 = *x2 = 0;

                return ZERO_ROOTS;

            }

        }

    }
}

int linear_solver(double b, double c, double *x1, double *x2)
{

    assert(x1 != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (is_zero(b))
    {

        if (is_zero(c))
        {

            *x1 = *x2 = 0;

            return INF_ROOTS;

        }
        else
        {

            *x1 = *x2 = 0;

            return ZERO_ROOTS;

        }

    }
    else
    {

        *x1 = *x2 = - c / b;

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

    if (fabs(num) < EPSILON)
        return true;
    return false;

}

bool is_equal(double num1, double num2)
{
    return is_zero(num1 - num2);
}

void buffer_clean()
{

    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {}

}

int unit_test(Coef coef_values, test_roots roots_values)
{

    double x1 = NAN;
    double x2 = NAN;

    if (

        is_equal(solver(coef_values.a, coef_values.b, coef_values.c, &x1, &x2), roots_values.nRoots_exp) &&
        is_equal(x1, roots_values.x1_exp) &&
        is_equal(x2, roots_values.x2_exp)

        )
    {
        printf("test is passed\n");
        return 1;
    }
    else
    {

        printf(

              "test is not passed\n"
              "expected values: x1 = %lg, x2 = %lg, Roots number = %d\n",
               roots_values.x1_exp, roots_values.x2_exp, roots_values.nRoots_exp

             );
        return 0;

    }

}

int execute_tests()
{

    Coef  test_coef1 = {1,  1,  1};
    Coef  test_coef2 = {0,  6, 12};
    Coef  test_coef3 = {1, -3,  2};
    Coef  test_coef4 = {0,  0,  0};

    test_roots test_roots1 = { 0,  0, ZERO_ROOTS};
    test_roots test_roots2 = {-2, -2, ONE_ROOT};
    test_roots test_roots3 = { 1,  2, TWO_ROOTS};
    test_roots test_roots4 = { 0,  0, INF_ROOTS};

    unit_test(test_coef1, test_roots1);
    unit_test(test_coef2, test_roots2);
    unit_test(test_coef3, test_roots3);
    unit_test(test_coef4, test_roots4);

    return 0;

}

int solver_or_test_mode()
{

    char ch1, ch2;
    bool flag;

    printf("Какой режим программы Вы хотите использовать?\n"
           "Напишите Т, чтобы использовать режим тестирования программы\n"
           "Напишите S, чтобы использовать режим решения квадратных уравнений\n");

    do
    {

        flag = false;

        ch1 = getchar();
        ch2 = getchar();

        if (ch1 == 'T' && ch2 == '\n')
        {
            return TEST_MODE;
        }
        else if (ch1 == 'S' && ch2 == '\n')
            {
                return SOLVER_MODE;
            }

            else
            {

                if (ch2 != '\n')
                {
                    buffer_clean();
                }

                printf("Введите корректный ответ\n");
                flag = true;

            }

    } while(flag);

}

void test_mode()
{
    execute_tests();
}

void solver_mode()
{

    Coef  abc = {NAN,  NAN,  NAN};

    double a   = NAN;
    double b   = NAN;
    double c   = NAN;

    double x1  = NAN;
    double x2  = NAN;

    int nRoots = 0;

    input(Coef &abc);
    nRoots = solver(a, b, c, &x1, &x2);
    output(nRoots, x1, x2);

}
