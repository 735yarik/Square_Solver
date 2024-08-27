#ifndef UTILS_CPP
#define UTILS_CPP

#include "../inc/utils.h"

/**
* @brief determines if number a zero
*
* @param [in] num number
*
* @return true if number is a zero and false if it's not
*/

bool is_zero(const double num)
{

    assert(isfinite(num));

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

bool is_equal(const double num1, const double num2)
{

    assert(isfinite(num1));
    assert(isfinite(num2));

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

#endif // UTILS_CPP

