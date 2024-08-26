#ifndef MENU_CPP
#define MENU_CPP

#include "../inc/menu.h"

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

#endif // MENU_CPP

