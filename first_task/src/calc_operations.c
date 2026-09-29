#include "../input/calc_operations.h"

#include <stdbool.h>
#include <stddef.h>

double sum(double number1, double number2) {
    return number1 + number2;
}

double multiply(double number1, double number2) {
    return number1 * number2;
}

double divide(double number1, double number2) {
    return number1 / number2;
}

double subtract (double number1, double number2) {
    return number1 - number2;
}

bool calculate(char operation, double number1, double number2, double *out_result, ERROR_CODES *error) {
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
