#ifndef TEST_MODE_CPP
#define TEST_MODE_CPP

#include "../inc/tests.h"

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

#endif // TEST_MODE_CPP
