#ifndef TEST_MODE_CPP
#define TEST_MODE_CPP

#include "../inc/test_mode.h"

/**
* @brief executing sires of tests
*/

void execute_tests()
{

    Coefficients coef1 = {1,  1,  1};
    Coefficients coef2 = {0,  6, 12};
    Coefficients coef3 = {1, -3,  2};
    Coefficients coef4 = {0,  0,  0};

    Roots roots1 = { 1,  0, ZERO_ROOTS};
    Roots roots2 = {-2, -2, ONE_ROOT};
    Roots roots3 = { 1,  2, TWO_ROOTS};
    Roots roots4 = { 0,  0, INF_ROOTS};

    Test tests[] = {

                   {coef1, roots1},
                   {coef2, roots2},
                   {coef3, roots3},
                   {coef4, roots4}

                   };

    size_t tests_size = sizeof(tests) / sizeof(Test);

    for (size_t counter = 0; counter < tests_size; counter++)
    {
        unit_test(tests[counter]);
    }

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

        roots.nRoots == (test.roots).nRoots &&
        is_equal(roots.x1, (test.roots).x1) &&
        is_equal(roots.x2, (test.roots).x2)

        )

    {

        printf("%stest is passed\n\n\%s", GREEN, RESET);

        return 1;

    }
    else
    {

        printf(

                "%stest is not passed\n"
                "expected values: x1 = %lg, x2 = %lg, Roots number = %d\n"
                "real values:     x1 = %lg, x2 = %lg, Roots number = %d\n\n%s",
                RED, (test.roots).x1, (test.roots).x2, (test.roots).nRoots, roots.x1, roots.x2, roots.nRoots, RESET

             );

        return 0;

    }

}

#endif // TEST_MODE_CPP
