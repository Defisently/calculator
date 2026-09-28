#include <stdio.h>
#include <string.h>
#include "calc_operations.h"


int input (int *number1, int *number2, char *operation) {
    printf("Input first number, then press enter: ");
    if (scanf("%d\n", number1) == 0) {
        printf("You entered an invalid symbol. Please try again.");
        return INVALID_NUMBER_INPUT;
    }
    printf("Input second number, then press enter: ");
    if (scanf("%d", number2) == 0) {
        printf("You entered an invalid symbol. Please try again.");
        return INVALID_NUMBER_INPUT;
    }

    printf("Input an operation: * / + -, then press enter: ");
    if (scanf(" %c", operation) != 1 || strchr("*/+-", *operation) == NULL) {
        printf("You entered an invalid operation. Please try again.");
        return INVALID_OPERATION_INPUT;
    }
    return 1;
}

int output (int number1, int number2, char operation) {
    int res = 0;
    ERROR_CODES error;
    if (calculate(operation, number1, number2, &res, &error)) {
        printf("Result: %d\n", res);
    } else {
        printf("Operation returned false. Please try again.\n");
    }
    return 0;
}