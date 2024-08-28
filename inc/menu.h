#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <TXLib.h>

#include "./input_output.h"
#include "./test_mode.h"

const int ERROR_CODE = -1;

enum modes
{

    TEST_MODE    = 0,
    SOLVER_MODE  = 1,

};

void menu();

int  solver_or_test_mode();

#endif // MENU_H
