#include "../input/calc_operations.h"

#include <stdbool.h>
#include <stddef.h>


bool check_equal(double num1, double num2) {
    const double EPSILON = 1e-6;
    if (num1 >= num2) {
        if ((num1 - num2) < EPSILON) {
            return true;
        } else {
            return false;
        }
    } else {
        if ((num2 - num1) < EPSILON) {
            return true;
        } else {
            return false;
        }
    }
}
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
    else if (operation == '/' && check_equal(0.0, number2)) {
        *error = DIVISION_BY_ZERO;
        return false;
    }
    return false;
}
