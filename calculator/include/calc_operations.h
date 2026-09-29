#include <stdbool.h>

#ifndef CALC_OPERATIONS_H
#define CALC_OPERATIONS_H



typedef enum {
    OK = 1,
    DIVISION_BY_ZERO = 0,
    INVALID_OPERATION_INPUT = 0,
    INVALID_NUMBER_INPUT = 0,
    SYSTEM_ERROR = 0,
    NOT_EQUAL = 0,
    INVALID_INPUT = 0,
} ERROR_CODES;

double sum(double number1, double number2);
double subtract(double number1, double number2);
double multiply(double number1, double number2);
double divide(double number1, double number2);
bool calculate(char operation, double number1, double number2, double *out_result, ERROR_CODES *error);

#endif