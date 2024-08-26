#ifndef INPUT_OUTPUT_CPP
#define INPUT_OUTPUT_CPP

#include "../inc/input_output.h"

/**
* @brief accepts struct that contains 3 coefficients: a, b, c
*/

void input(Coefficients *coefs)
{

    assert(coefs != NULL);

    printf("Ýòà ïðîãðàììà ðåøàåò óðàâíåíèå âèäà ax2+bx+c=0\n");
    printf("Ââåäèòå êîýôèöåíòû a,b,c\n\n");

    while (scanf("%lg %lg %lg", &coefs->a, &coefs->b, &coefs->c) != 3)            //
    {

        printf("ââåäèòå êîððåêòíûå ÷èñëà\n");

        buffer_clean();

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

#endif // INPUT_OUTPUT_CPP
