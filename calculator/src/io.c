#include <stdio.h>
#include <string.h>
#include "calc_operations.h"
#include "io.h"
#include "math.h"

ERROR_CODES input(double *number1, double *number2, char *operation) {

    #define INPUT_NUM(num)                                                   \
        do {                                                                 \
            printf("Input number, then press enter: ");                      \
            if (scanf("%lf", (num)) != 1) {                                  \
                printf("You entered an invalid input. Please try again.\n"); \
                return INVALID_NUMBER_INPUT;                                 \
            }                                                                \
        } while (0)

    INPUT_NUM(number1);
    INPUT_NUM(number2);

    #undef INPUT_NUM

    printf("Input an operation: * / + -, then press enter: ");
    if (scanf(" %c", operation) != 1 || strchr("*/+-", *operation) == NULL) {
        printf("You entered an invalid operation. Please try again.");
        return INVALID_OPERATION_INPUT;
    }
    return SUCCESS;
}

int output(double number1, double number2, char operation) {
    double res = NAN;
    int error = calculate(number1, number2, operation, &res);
    return error;
}