#include <stdbool.h>

#ifndef CALC_OPERATIONS_H
#define CALC_OPERATIONS_H



// FIXME[dkay]: make enum constants' values different...
typedef enum {
    OK                      = 0,
    DIVISION_BY_ZERO        = 1,
    INVALID_OPERATION_INPUT = 2,
    INVALID_NUMBER_INPUT    = 3,
    SYSTEM_ERROR            = 4,
    NOT_EQUAL               = 5,
    INVALID_INPUT           = 6,
} ERROR_CODES;

double sum(double number1, double number2);
double subtract(double number1, double number2);
double multiply(double number1, double number2);
double divide(double number1, double number2);
bool calculate(char operation, double number1, double number2, double *out_result, ERROR_CODES *error);

#endif
