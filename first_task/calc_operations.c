#include "calc_operations.h"

#include <stdbool.h>
#include <stddef.h>

int sum(int number1, int number2) {
    return number1 + number2;
}

int multiply(int number1, int number2) {
    return number1 * number2;
}

int divide(int number1, int number2) {
    return number1 / number2;
}

int subtract (int number1, int number2) {
    return number1 - number2;
}

bool calculate(char operation, int number1, int number2, int *out_result, ERROR_CODES *error) {
    *error = OK;
    if (out_result == NULL) {
        *error = SYSTEM_ERROR;
        return false;
    }
    if (operation == '+') {
        *out_result = sum(number1, number2);
        return true;
    }
    else if (operation == '-') {
        *out_result = subtract(number1, number2);
        return true;
    }
    else if (operation == '*') {
        *out_result = multiply(number1, number2);
        return true;

    }
    else if (operation == '/' && number2 == 0) {
        *error = DIVISION_BY_ZERO;
        return false;
    }
    *error = SYSTEM_ERROR;
    return false;
}
