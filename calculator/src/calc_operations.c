#include "calc_operations.h" 
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

bool check_equal(double num1, double num2) {
    return fabs(num1 - num2) < 1e-9;
}

double sum(double number1, double number2) {
    return number1 + number2;
}

double multiply(double number1, double number2) {
    return number1 * number2;
}

ERROR_CODES divide(double number1, double number2, double *out_result) {
    SOFT_ASSERT(out_result == NULL, "System error", return SYSTEM_ERROR);

    if (check_equal(number2, 0.0)) {
        *out_result = NAN;
        return DIVISION_BY_ZERO;
    }
    *out_result = number1 / number2;
    return SUCCESS;
}

double subtract (double number1, double number2) {
    return number1 - number2;
}

ERROR_CODES calculate(char operation, double number1, double number2, double *out_result) {

    SOFT_ASSERT(out_result == NULL, "System error", return SYSTEM_ERROR);


    if (operation == '+') {
        *out_result = sum(number1, number2);
        return SUCCESS;

    } else if (operation == '-') {
        *out_result = subtract(number1, number2);
        return SUCCESS;

    } else if (operation == '*') {
        *out_result = multiply(number1, number2);
        return SUCCESS;

    } else if (operation == '/') {
    
        double divide_res = NAN;

        if (divide(number1, number2, &divide_res) == DIVISION_BY_ZERO) {
            return DIVISION_BY_ZERO;

        } else {
            *out_result = divide_res;
            return SUCCESS;
        }

    }
    return SYSTEM_ERROR;
}
