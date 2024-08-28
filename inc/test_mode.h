#ifndef TEST_MODE_H
#define TEST_MODE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <TXLib.h>

#include "./solver.h"

#define RESET "\033[0m"
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"

struct Test                            /// struct contains two other structs: Coefficients, Roots
{

    Coefficients coefs;                /// struct contains coefficients a, b, c
    Roots roots;                       /// struct contains roots and number of roots

};

void execute_tests();

int  unit_test(Test test);

#endif // TEST_MODE_H

