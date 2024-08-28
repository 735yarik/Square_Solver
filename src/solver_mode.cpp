#ifndef SOLVER_MODE_CPP
#define SOLVER_MODE_CPP

#include "../inc/input_output.h"
#include "../inc/solver.h"

/**
* @brief starting solver mode
*/

void solver_mode()
{

    Coefficients coefs = {};
    Roots roots = {};

    input(&coefs);
    solver(coefs, &roots);
    output(roots);

}

/**
* @brief solves equation using linear_solver or square_solver
*
* @param [in] coefs struct contains 3 coefficients
* @param [in] roots struct contains roots and number of roots
*/

void solver(const Coefficients coefs, Roots *roots)
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

void square_solver(const Coefficients coefs, Roots *roots)
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
* @param [in] x1  root
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

        if (is_zero(c))
        {
            *x1 = 0;
        }
        else
        {
            *x1 = - c / b;
        }

        return ONE_ROOT;

    }

}

#endif // SOLVER_MODE_CPP
