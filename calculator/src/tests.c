#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../input/calc_operations.h"
#include <math.h>


bool read_and_check(char input[60]) {
    double num1 = 0.0, num2 = 0.0;
    double calc_res = 0.0, true_result = 0.0;
    double curr = 0.0;
    bool has_digit = false, first_number = false, second_number = false;
    bool is_negative_1 = false, is_negative_3 = false;
    bool first_zero = false;
    bool point = false;
    int point_counter = 0;
    char operation = '\0';
    ERROR_CODES error;

    if (input == NULL) {
        return INVALID_INPUT;
    }

    for (int i = 0; i < 60 && input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            continue;
        } else if (input[i] == '.') {
            point = true;
        } else if (input[i] == '-' && is_negative_3 == false && second_number == true) {
            is_negative_3 = true;
        } else if (input[i] == '-' && is_negative_1 == false && first_number == false && !has_digit) {
            is_negative_1 = true;
        } else if (strchr("+-*/", input[i]) != NULL) {
            operation = input[i];
            if (has_digit && first_number == false) {
                if (is_negative_1 == false) {
                    num1 = curr * pow(10, (-point_counter));
                    point = false;
                    point_counter = 0;
                    curr = 0;
                    has_digit = false;
                    first_number = true;
                } else {
                    num1 = -1 * (curr * pow(10, (-point_counter)));
                    point = false;
                    point_counter = 0;
                    curr = 0;
                    has_digit = false;
                    first_number = true;
                }
            }
        } else if (input[i] >= '0' && input[i] <= '9') {
            if (point) {
                point_counter++;
            }
            if (has_digit == true && curr == 0) {
                return false;
            }
            curr = curr * 10 + (input[i] - '0');
            has_digit = true;
        } else if (input[i] == '=') {
            if (first_number == true && has_digit == true && second_number == false) {
                num2 = curr * pow(10, (-point_counter));
                point = false;
                point_counter = 0;
                curr = 0;
                has_digit = false;
                second_number = true;
            }
        }
    }
    if (has_digit == true && first_number == true && second_number == true && is_negative_3 == false) {
        true_result = curr * pow(10, (-point_counter));
    } else if (has_digit == true && first_number == true && second_number == true && is_negative_3 == true) {
        true_result = -1 * (curr * pow(10, (-point_counter)));
    }

    if (operation == '/' && num2 == 0) {
        return false;
    }

    bool calc_ok = calculate(operation, num1, num2, &calc_res, &error);
    if (check_equal(true_result, calc_res) && calc_ok == true) {
        return OK;
    } else {
        return false;
    }
}

int tests(void) {
    double number1 = 0, number2 = 0;
    int counter = 0;
    int counter_passed_tests = 0, counter_failed_tests = 0;
    char operation = '\0';
    char bad_output[] = "Error code: %s\n";
    char buffer[60];
    FILE *fp = fopen("tests.txt", "r");
    if (fp) {
        while (fgets(buffer, 60, fp) != NULL) {
            counter++;
            if (read_and_check(buffer)) {
                counter_passed_tests++;
                printf("%d %s", counter, "Test passed!\n");
            } else {
                counter_failed_tests++;
                printf("%d %s", counter, "Test failed!\n");
            }
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("%d tests passed\n", counter_passed_tests);
    printf("%d tests failed\n", counter_failed_tests);
    return 0;
}

int main() {
    tests();
    return 0;
}