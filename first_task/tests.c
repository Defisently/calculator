#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "calc_operations.h"


bool check_equal(int num1, int num2) {
    const double EPSILON = 1e-6;
    if (abs(num1 - num2) < EPSILON) {
        return true;
    } else {
        return false;
    }
}

bool check(char input[60]) {
    int num1 = 0, num2 = 0;
    int calc_res = 0, true_result = 0;
    int curr = 0;
    bool has_digit = false, first_number = false, second_number = false;
    bool is_negative_1 = false, is_negative_3 = false;
    bool first_zero = false;
    char operation = '\0';
    ERROR_CODES error;

    if (input == NULL) {
        return false;
    }

    for (int i = 0; i < 60 && input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            continue;
        } else if (input[i] == '-' && is_negative_3 == false && second_number == true) {
            is_negative_3 = true;
        } else if (input[i] == '-' && is_negative_1 == false && first_number == false && !has_digit) {
            is_negative_1 = true;
        } else if (strchr("+-*/", input[i]) != NULL) {
            operation = input[i];
            if (has_digit && first_number == false) {
                if (is_negative_1 == false) {
                    num1 = curr;
                    curr = 0;
                    has_digit = false;
                    first_number = true;
                } else {
                    num1 = -1 * curr;
                    curr = 0;
                    has_digit = false;
                    first_number = true;
                }
            }
        } else if (input[i] >= '0' && input[i] <= '9') {
            if (has_digit == true && curr == 0) {
                return false;
            }
            curr = curr * 10 + (input[i] - '0');
            has_digit = true;
        } else if (input[i] == '=') {
            if (first_number == true && has_digit == true && second_number == false) {
                num2 = curr;
                curr = 0;
                has_digit = false;
                second_number = true;
            }
        }
    }
    if (has_digit == true && first_number == true && second_number == true && is_negative_3 == false) {
        true_result = curr;
    } else if (has_digit == true && first_number == true && second_number == true && is_negative_3 == true) {
        true_result = -1 * curr;
    }

    if (operation == '/' && num2 == 0) {
        return false;
    }

    bool calc_ok = calculate(operation, num1, num2, &calc_res, &error);
    if (check_equal(true_result, calc_res) && calc_ok == true) {
        return true;
    } else {
        return false;
    }
}

int tests(void) {
    int number1 = 0, number2 = 0;
    char operation = '\0';
    char bad_output[] = "Error code: %s\n";
    char buffer[60];
    FILE *fp = fopen("tests.txt", "r");
    if (fp) {
        while (fgets(buffer, 60, fp) != NULL) {
            if (check(buffer)) {
                printf("%s", "Test passed!\n");
            } else {
                printf("%s", "Test failed!\n");
            }
        }
    }
    return 0;
}

int main() {
    tests();
    return 0;
}