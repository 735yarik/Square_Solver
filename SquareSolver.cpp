#include <TXLib.h>

// TODO codestyle

// TODO read doxygen
// TODO read раздельную компиляцию перед понедельником
// TODO read разбиение на файлы перед понедельником

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

const double EPSILON = 1e-7;

struct Coefficients
{

    double a;
    double b;
    double c;

};

/*struct test
{
    struct coef
    struct roots
}  */

struct Roots
{

    double x1;
    double x2;

    int nRoots;

};

void input(Coefficients *coefs);

void solver(Coefficients coefs, Roots *roots);
int  linear_solver(Coefficients coefs, double *x1, int *nRoots);
void square_solver(Coefficients coefs, Roots *roots);

void output(int nRoots, double x1, double x2);

void buffer_clean();
bool is_zero(double num);
bool is_equal(double num1, double num2);
int  unit_test(Coefficients coefs, Roots exp);
int  execute_tests();
int  solver_or_test_mode();
void test_mode();
void solver_mode();
void menu();

int main()
{
    menu();
}

void input(Coefficients *coefs)
{

    assert(coefs != NULL);

    printf("Эта программа решает уравнение вида ax2+bx+c=0\n");
    printf("Введите коэфиценты a,b,c\n");

    while (scanf("%lg %lg %lg", &coefs->a, &coefs->b, &coefs->c) != 3)            //
    {

        printf("введите корректные числа\n");

        buffer_clean();

    }

}

void solver(Coefficients coefs, Roots *roots)
{

    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    if (is_zero(coefs.a))
    {

        linear_solver(coefs, &(roots->x1), &(roots->nRoots));

        roots->x2 = roots->x1;

    }
    else
    {
        square_solver(coefs, roots);
    }

}

void square_solver(Coefficients coefs, Roots *roots)
{

    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    if (is_zero(coefs.c))
    {

        roots->x1 = roots->x2 = (-coefs.b) / (2 * coefs.a);

        roots->nRoots = TWO_ROOTS;

    }
    else
    {

        double discriminant = coefs.b * coefs.b - 4 * coefs.a * coefs.c;

        if (discriminant > EPSILON)
        {

            roots->x1 = (- coefs.b - sqrt(discriminant)) / (2 * coefs.a);
            roots->x2 = (- coefs.b + sqrt(discriminant)) / (2 * coefs.a);

            roots->nRoots = TWO_ROOTS;

        }
        else
        {

            if (is_zero(discriminant))
            {

                roots->x1 = (-coefs.b) / (2 * coefs.a);
                roots->x2 = (-coefs.b) / (2 * coefs.a);

                roots->nRoots = ONE_ROOT;

            }
            else
            {

                roots->x1 = roots->x2 = 0;

                roots->nRoots = ZERO_ROOTS;

            }

        }

    }

}

int linear_solver(Coefficients coefs, double *x1, int *nRoots)       // bc only
{

    assert(x1 != NULL);
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    if (is_zero(coefs.b))
    {

        if (is_zero(coefs.c))
        {

            *x1 = 0;

            *nRoots = INF_ROOTS;

        }
        else
        {

            *x1 = 0;

            *nRoots = ZERO_ROOTS;

        }

    }
    else
    {

        *x1 = - coefs.c / coefs.b;

        *nRoots = ONE_ROOT;

    }

}

void output(int nRoots, double x1, double x2)
{

    switch(nRoots)
        {
        case ZERO_ROOTS:
            printf("\nEQUATION HAS NO ROOTS\n");
            break;

        case ONE_ROOT:
            printf("\nEQUATION HAS 1 ROOT:  x = %lg\n" ,x1);
            break;

        case TWO_ROOTS:
            printf("\nEQUATION HAS 2 ROOTS:x1 = %lg, x2 = %lg\n", x1, x2);
            break;

        case INF_ROOTS:
            printf("\nEQUATION HAS INF ROOTS\n");
            break;

        default:
            printf("\nERROR IN ROOTS NUMBER\n");
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

int unit_test(Coefficients coefs, Roots exp)
{

    Roots roots = {NAN, NAN, 0};

    solver(coefs, &roots);

    if (

        is_equal(roots.nRoots, exp.nRoots) &&
        is_equal(roots.x1, exp.x1) &&
        is_equal(roots.x2, exp.x2)

        )
    {
        printf("test is passed\n\n");
        return 1;
    }
    else
    {

        printf(

              "test is not passed\n"
              "expected values: x1 = %lg, x2 = %lg, Roots number = %d\n"
              "real values:     x1 = %lg, x2 = %lg, Roots number = %d\n\n",
               exp.x1, exp.x2, exp.nRoots, roots.x1, roots.x2, roots.nRoots

             );
        return 0;

    }

    return 0;

}

int execute_tests()
{

    Coefficients coef1 = {1,  1,  1};
    Coefficients coef2 = {0,  6, 12};
    Coefficients coef3 = {1, -3,  2};
    Coefficients coef4 = {0,  0,  0};

    Roots roots1 = { 0,  0, ZERO_ROOTS};
    Roots roots2 = {-2, -2, ONE_ROOT};
    Roots roots3 = { 1,  2, TWO_ROOTS};
    Roots roots4 = { 0,  0, INF_ROOTS};

    unit_test(coef1, roots1);
    unit_test(coef2, roots2);
    unit_test(coef3, roots3);
    unit_test(coef4, roots4);

    return 0;

}

int solver_or_test_mode()
{

    int ch1, ch2;
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

    Coefficients coefs = {};
    Roots roots = {};

    input(&coefs);
    solver(coefs, &roots);
    output(roots.nRoots, roots.x1, roots.x2);

}

void menu()
{

    int mode = solver_or_test_mode();

    switch(mode)
        {
        case TEST_MODE:

            printf("\nTEST_MODE\n\n");
            test_mode();
            break;

        case SOLVER_MODE:

            printf("\nSOLVER_MODE\n\n");
            solver_mode();
            break;

        default:
            printf("default case\n");
        }

}


