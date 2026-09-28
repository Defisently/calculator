#include <stdbool.h>

#ifndef CALC_OPERATIONS_H
#define CALC_OPERATIONS_H



typedef enum {
    OK = 1,
    DIVISION_BY_ZERO = 0,
    INVALID_OPERATION_INPUT = 0,
    INVALID_NUMBER_INPUT = 0,
    SYSTEM_ERROR = 0
} ERROR_CODES;

int sum(int number1, int number2);
int subtract(int number1, int number2);
int multiply(int number1, int number2);
int divide(int number1, int number2);
bool calculate(char operation, int number1, int number2, int *out_result, ERROR_CODES *error);

#endif