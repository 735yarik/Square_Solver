///@file SquareSolver.cpp

#include <TXLib.h>

// TODO codestyle

// TODO read раздельную компиляцию перед понедельником делать
// TODO read разбиение на файлы перед понедельником делать
// TODO препроцессор                  2
// TODO аргументы командной строки делать   3
// TODO символьные строки

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
const int MAX_TESTS  = 4;

struct Coefficients                    /// struct contains coefficients a, b, c
{

    double a;                          /// a-coefficient
    double b;                          /// b-coefficient
    double c;                          /// c-coefficient

};

struct Roots                           /// struct contains roots and number of roots
{

    double x1;                         /// 1st root
    double x2;                         /// 2nd root

    int nRoots;                        /// number of roots

};

struct Test                            /// struct contains two other structs: Coefficients, Roots
{

    Coefficients coefs;                /// struct contains coefficients a, b, c
    Roots roots;                       /// struct contains roots and number of roots

};

void input(Coefficients *coefs);
void output(Roots roots);

void menu();
int  solver_or_test_mode();

void solver_mode();
void solver(Coefficients coefs, Roots *roots);
int  linear_solver(double b, double c, double *x1);
void square_solver(Coefficients coefs, Roots *roots);

void test_mode();
int  unit_test(Test test);
void  execute_tests();

void buffer_clean();
bool is_zero(double num);
bool is_equal(double num1, double num2);

/**
* @brief Solves a square equation ax2 + bx + c = 0
*
* @param [in] a a-coefficient
* @param [in] b b-coefficient
* @param [in] c c-coe fficient
* @param [out] x1 Pointer to the 1st root
* @param [out] x2 Pointer to the 2nd root
*
* @return Number of roots
*
* @note In case of infinite number of roots,
* returns SS_INF_ROOTS.
*/

int main()
{
    printf("%s", "\033[1;32m");

    menu();
}

/**
* @brief accepts struct that contains 3 coefficients: a, b, c
*/

void input(Coefficients *coefs)
{

    assert(coefs != NULL);

    printf("Эта программа решает уравнение вида ax2+bx+c=0\n");
    printf("Введите коэфиценты a,b,c\n\n");

    while (scanf("%lg %lg %lg", &coefs->a, &coefs->b, &coefs->c) != 3)            //
    {

        printf("введите корректные числа\n");

        buffer_clean();

    }

}

/**
* @brief solves equation using linear_solver or square_solver
*
* @param [in] coefs struct contains 3 coefficients
* @param [in] roots struct contains roots and number of roots
*/
                                                //*roots??
void solver(Coefficients coefs, Roots *roots)
{

    assert(roots != NULL);

    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    if (is_zero(coefs.a))
    {

        roots->nRoots = linear_solver(coefs.b, coefs.c, &(roots->x1));

        roots->x2 = roots->x1;

    }
    else
    {
        square_solver(coefs, roots);
    }

}

/**
* @brief solving square equation ax2+bx+c=0 only with a != 0
*
* @param [in] coefs struct contains 3 coefficients
* @param [in] roots struct contains roots and number of roots
*/

void square_solver(Coefficients coefs, Roots *roots)
{

    assert(roots != NULL);

    assert(isfinite(coefs.a));
    assert(isfinite(coefs.b));
    assert(isfinite(coefs.c));

    if (is_zero(coefs.c))
    {

        roots->x1 = (-coefs.b) / (coefs.a);
        roots->x2 = 0;

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

/**
* @brief Solves linear equation bx+c=0
* @param [in]  b   b-coefficient
* @param [in]  c   c-coefficient
* @param [in] *x1  root??
*
* @return Number of roots
*
* @note   In case of infinite number of roots returns INF_ROOTS
*/
int linear_solver(double b, double c, double *x1)
{

    assert(x1 != NULL);
    assert(isfinite(b));
    assert(isfinite(c));

    if (is_zero(b))
    {

        if (is_zero(c))
        {

            *x1 = 0;

            return INF_ROOTS;

        }
        else
        {

            *x1 = 0;

            return ZERO_ROOTS;

        }

    }
    else
    {

        *x1 = - c / b;

        return ONE_ROOT;

    }

}

/**
* @brief This function prints how many roots equation has and roots themselves
*
* @param [in] roots struct with roots and number of roots
*/
void output(Roots roots)
{

    switch(roots.nRoots)
        {
        case ZERO_ROOTS:

            printf("\nEQUATION HAS NO ROOTS\n");
            break;

        case ONE_ROOT:

            printf("\nEQUATION HAS 1 ROOT:  x = %lg\n" ,roots.x1);
            break;

        case TWO_ROOTS:

            printf("\nEQUATION HAS 2 ROOTS:x1 = %lg, x2 = %lg\n", roots.x1, roots.x2);
            break;

        case INF_ROOTS:

            printf("\nEQUATION HAS INF ROOTS\n");
            break;

        default:
            printf("\nERROR IN ROOTS NUMBER\n");
        }

}

/**
* @brief determines if number a zero
*
* @param [in] num number
*
* @return true if number is a zero and false if it's not
*/

bool is_zero(double num)
{

    if (fabs(num) < EPSILON)
        return true;
    return false;

}

/**
* @brief determines if two numbers equal
*
* @param [in] num1 1st number
* @param [in] num2 2nd number
*
* @return true if number is a zero and false if it's not
*/

bool is_equal(double num1, double num2)
{
    return is_zero(num1 - num2);
}

/**
* @brief cleans buffer
*/

void buffer_clean()
{

    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {}

}

/**
* @brief comparing expected roots and roots given by solver
*
* @param [in] test struct with 2 structs: 1st with coefficients and 2nd with expected roots
*
* @return returns 1 if test is passed and 0 if it's not
*/

int unit_test(Test test)
{

    Roots roots = {NAN, NAN, 0};

    solver(test.coefs, &roots);

    if (

        is_equal(roots.nRoots, (test.roots).nRoots) &&
        is_equal(roots.x1, (test.roots).x1) &&
        is_equal(roots.x2, (test.roots).x2)

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
               (test.roots).x1, (test.roots).x2, (test.roots).nRoots, roots.x1, roots.x2, roots.nRoots

             );
        return 0;

    }

}

/**
* @brief executing sires of tests
*/

void execute_tests()
{

    int counter = 0;

    Coefficients coef1 = {1,  1,  1};                //simplify??
    Coefficients coef2 = {0,  6, 12};
    Coefficients coef3 = {1, -3,  2};
    Coefficients coef4 = {0,  0,  0};

    Roots roots1 = { 0,  0, ZERO_ROOTS};
    Roots roots2 = {-2, -2, ONE_ROOT};
    Roots roots3 = { 1,  2, TWO_ROOTS};
    Roots roots4 = { 0,  0, INF_ROOTS};

    Test test1 = {};
    Test test2 = {};
    Test test3 = {};
    Test test4 = {};

    Test tests[MAX_TESTS] = {

                            test1 = {coef1, roots1},
                            test2 = {coef2, roots2},
                            test3 = {coef3, roots3},
                            test4 = {coef4, roots4}

                            };

    for (counter = 0; counter < MAX_TESTS; counter++)
    {
        unit_test(tests[counter]);
    }

}

/**
* @brief asks user which mode to use
*
* @return TEST_MODE or SOLVER_MODE
*/

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

    return -1;

}

/**
* @brief starting test mode
*/

void test_mode()
{
    execute_tests();
}

/**
* @brief starting solver mode
*/

void solver_mode()
{

    Coefficients coefs = {};
    Roots roots = {};

    input(&coefs);
    solver(coefs, &roots);          //
    output(roots);

}

/**
* @brief calling test_mode or solver_mode func
*/

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
