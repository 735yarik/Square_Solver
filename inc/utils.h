#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <TXLib.h>

const double EPSILON = 1e-7;

void buffer_clean();

bool is_zero(const double num);

bool is_equal(const double num1, const double num2);

#endif // UTILS_H

