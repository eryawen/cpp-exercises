//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"
#include <stdlib.h>

int factorial(int value) {
    if (value <= -13 || value >= 13) return 0;
    if (value == 0 || value == 1) return 1;
    return value * factorial(value - abs(value) / value);
}
