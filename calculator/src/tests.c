#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "calc_operations.h"
#include <math.h>

struct testcase {
    double num1, num2;
    double calc_res, true_result;
    double curr;
    int multiplier;
};

struct checking_operators {
    bool has_digit;
    bool first_number;
    bool second_number;
    bool is_number1_negative;
    bool is_number3_negative;
    bool first_zero;
    bool point;

};

void init_testcase(struct testcase *self){
  self->num1 = NAN;
  self->num2 = NAN;
  self->calc_res = NAN;
  self->true_result = NAN;
  self->curr = 0.0;
  self->multiplier = 1;
}

// #ifdef  / else / endif
//
ERROR_CODES read_and_check(char *input) {
    struct testcase x;
    init_testcase(&x);
    struct checking_operators y = {false, false, false,
        false, false, false};
    char operation = '\0';
    ERROR_CODES error = SUCCESS;

    if (input == NULL) {
        return INVALID_INPUT;
    }

    for (int i = 0; i < 60 && input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            continue;
        } else if (input[i] == '.') {
            y.point = true;
        } else if (input[i] == '-' && y.is_number3_negative == false && y.second_number == true) {
            y.is_number3_negative = true;
        } else if (input[i] == '-' && y.is_number1_negative == false && y.first_number == false && !y.has_digit) {
            y.is_number1_negative = true;
        } else if (strchr("+-*/", input[i]) != NULL) {
            operation = input[i];
            if (y.has_digit && y.first_number == false) {
                if (y.is_number1_negative == false) {
                    x.num1 = x.curr / x.multiplier;
                } else {
                    x.num1 = -1 * (x.curr / x.multiplier);
                }
                y.point = false;
                x.multiplier = 1;
                x.curr = 0;
                y.has_digit = false;
                y.first_number = true;
            }
        } else if (input[i] >= '0' && input[i] <= '9') {
            if (y.point) {
                x.multiplier *= 10;
            }
            if (y.has_digit == true && x.curr == 0 && y.point == false) {
                return INVALID_INPUT;
            }
            x.curr = x.curr * 10 + (input[i] - '0');
            y.has_digit = true;
        } else if (input[i] == '=') {
            if (y.first_number == true && y.has_digit == true && y.second_number == false) {
                x.num2 = x.curr / x.multiplier;
                y.point = false;
                x.multiplier = 1;
                x.curr = 0;
                y.has_digit = false;
                y.second_number = true;
            }
        }
    }
    if (y.has_digit == true && y.first_number == true && y.second_number == true && y.is_number3_negative == false) {
        x.true_result = x.curr / x.multiplier;
    } else if (y.has_digit == true && y.first_number == true && y.second_number == true && y.is_number3_negative == true) {
        x.true_result = -1 * (x.curr / x.multiplier);
    }

    if (operation == '/' && x.num2 == 0) {
        return DIVISION_BY_ZERO;
    }

    ERROR_CODES calc_ok = calculate(operation, x.num1, x.num2, &x.calc_res);
    if (check_equal(x.true_result, x.calc_res) && calc_ok == SUCCESS) {
        return SUCCESS;
    } else {
        return SYSTEM_ERROR;
    }
}

int tests(void) {
    int counter = 0;
    int counter_passed_tests = 0, counter_failed_tests = 0;
    const int buffer_size = 60; // FIXME get_file_size  / seek () 
                                // calloc 
                                // fread 
  //
    char buffer[buffer_size];
    FILE *fp = fopen("tests.txt", "r");
    if (!fp) {
        return FILE_NOT_OPENED;
    }

    while (fgets(buffer, buffer_size, fp) != NULL) {
        counter++;
        if (read_and_check(buffer) == SUCCESS) {
            counter_passed_tests++;
            printf("%d %s", counter, "Test passed!\n");
        } else {
            counter_failed_tests++;
            printf("%d Test failed! Error code: %d\n", counter, read_and_check(buffer));
            }
    }
    fclose(fp);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%d tests passed\n", counter_passed_tests);
    printf("%d tests failed\n", counter_failed_tests);
    return counter_failed_tests;
}

int main(){
  tests();
  return 0;
}
//gcc  -DTEST_BUILD
//#ifdef TEST_BUILD
//includet main() {
//    tests();
//    return 0;
//}
//#else
//int main() {
//  ...
//}
//#endif
