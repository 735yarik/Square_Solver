#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <TXLib.h>

#include "./utils.h"

enum roots_values
{

    INF_ROOTS  = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2

};

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

void solver_mode();

void solver(Coefficients coefs, Roots *roots);

int  linear_solver(double b, double c, double *x1);

void square_solver(Coefficients coefs, Roots *roots);

#endif // SOLVER_MODE_H
