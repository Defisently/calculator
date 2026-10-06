#include <stdbool.h>
#include <stdio.h>

#ifndef CALC_OPERATIONS_H
#define CALC_OPERATIONS_H

#define SOFT_ASSERT(to_check, print, go_out)      \
  do {                                            \
      if (to_check) {                             \
        printf(print "\n");                       \
        go_out;                                   \
  }                                               \
  } while (0)


typedef enum {
    SUCCESS                 = 0,
    DIVISION_BY_ZERO        = 1,
    INVALID_OPERATION_INPUT = 2,
    INVALID_NUMBER_INPUT    = 3,
    SYSTEM_ERROR            = 4,
    NOT_EQUAL               = 5,
    INVALID_INPUT           = 6,
    FILE_NOT_OPENED         = 7,
    FILE_SIZE_ERROR         = 8,
    NOT_ENOUGH_MEMORY       = 9, 
} ERROR_CODES;

bool check_equal(double num1, double num2);
double sum(double number1, double number2);
double subtract(double number1, double number2);
double multiply(double number1, double number2);
ERROR_CODES divide(double number1, double number2, double *out_result);
ERROR_CODES calculate(char operation, double number1, double number2, double *out_result);

#endif
