#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <TXLib.h>


#include "./input_output.h"
#include "./tests.h"

enum modes
{

    TEST_MODE    = 0,
    SOLVER_MODE  = 1,

};

void menu();

int  solver_or_test_mode();

#endif // MENU_H
