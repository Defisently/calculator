#include <stdio.h>
#include <string.h>
#include "calc_operations.h"
#include "io.h"
#include "math.h"

ERROR_CODES input(double *number1, double *number2, char *operation) {
  //fix unstop enter
    #define INPUT_NUM(num1, num2)                                            \
        do {                                                                 \
            printf("Input two numbers, then press enter: ");                 \
            if (scanf("%lf %lf", num1, num2) != 2) {                         \
                printf("You entered an invalid input. Please try again.\n"); \
                return INVALID_NUMBER_INPUT;                                 \
            }                                                                \
        } while (0)

    INPUT_NUM(number1, number2);

    #undef INPUT_NUM

    printf("Input an operation: * / + - or E to exit from the programm, then press enter: ");


    if (scanf(" %c", operation) != 1 || strchr("*/+-E", *operation) == NULL) {
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
