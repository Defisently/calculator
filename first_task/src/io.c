#include <stdio.h>
#include <string.h>
#include "../input/calc_operations.h"

double input (double *number1, double *number2, char *operation) {
    printf("Input first number, then press enter: ");
    if (scanf("%lf", number1) == 0) {
        printf("You entered an invalid symbol. Please try again.");
        return INVALID_NUMBER_INPUT;
    }
    printf("Input second number, then press enter: ");
    if (scanf("%lf", number2) == 0) {
        printf("You entered an invalid symbol. Please try again.");
        return INVALID_NUMBER_INPUT;
    }

    printf("Input an operation: * / + -, then press enter: ");
    if (scanf(" %c", operation) != 1 || strchr("*/+-", *operation) == NULL) {
        printf("You entered an invalid operation. Please try again.");
        return INVALID_OPERATION_INPUT;
    }
    return OK;
}

double output (double number1, double number2, char operation) {
    double res = 0.0;
    ERROR_CODES error;
    if (calculate(operation, number1, number2, &res, &error)) {
        printf("Result: %.3f\n", res);
    } else {
        printf("Operation returned false. Please try again.\n");
    }
    return 0;
}