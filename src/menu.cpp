#ifndef MENU_CPP
#define MENU_CPP

#include "../inc/menu.h"

/**
* @brief calling test_mode or solver_mode func
*/

void menu()
{

    int mode = solver_or_test_mode();

    switch (mode)
    {
        case TEST_MODE:

            printf("\nTEST_MODE\n\n");
            execute_tests();
            break;

        case SOLVER_MODE:

            printf("\nSOLVER_MODE\n\n");
            solver_mode();
            break;

        default:
            printf("default case\n");
    }

}

/**
* @brief asks user which mode to use
*
* @return TEST_MODE or SOLVER_MODE
*/

int solver_or_test_mode()
{

    int ch1 = 0;
    int ch2 = 0;

    printf("Which mode do you want to use?\n"
           "Enter Ò to use test mode\n"
           "Enter S to use solver mode\n");

    while (true)
    {

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

            printf("\nEnter correct mode\n");

        }
    }

    return ERROR_CODE;

}

#endif // MENU_CPP

