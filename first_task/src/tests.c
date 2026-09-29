#include "../input/calc_operations.h" // FIXME relative include
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// enum CMP_RESULT {
//     EQUAL   = 0,
//     NOT_EQUAL = 1
// }
// true / false
//
bool check_equal(double num1, double num2) {
  const double EPSILON = 1e-6;
  // abs
  //
  // return fabs(num1 - num2) < EPSILON;

  if (num1 >= num2) {
    if ((num1 - num2) < EPSILON) {
      // return OK; // OK -> all correct
      return true;
    } else {
      // return NOT_EQUAL;
      return false;
    }
  } else {
    if ((num2 - num1) < EPSILON) {
      return OK;
    } else {
      return NOT_EQUAL;
    }
  }
}

// array-to-pointer-decay
//
// struct testcase{
//     double true_res;
//     double num1, num2;
//     char op;
// };
//
// void init_testcase(testcase *self) {
//     self->true_res = 0;
//     self->calc_res = 0;
//     self->num1 = 0;
//     self->num2 = 0;
// }
//
// testcase test1;
// init_testcase(&test1);

// class testcase:
//     def __init__(self):
//         self.true_res = 0
//         self.calc_res = 0
//         ..

bool read_and_check(char *input) {
  // TODO: read abt structs
  double num1 = 0.0, num2 = 0.0;
  double calc_res = NAN, true_result = 0.0;
  double curr = 0.0;
  bool has_digit = false, first_number = false, second_number = false;
  bool is_negative_1 = false, is_negative_3 = false;
  bool first_zero = false;
  bool point = false;
  int point_counter = 0;
  char operation = '\0';

  ERROR_CODES error; // TODO: unint value

  // nice!
  if (input == NULL) {
    return INVALID_INPUT;
  }

  // TIP: use sscanf(input, "%c %f %f", operation, num1, num2);
  // or better read from file: fscanf(input, "%c %f %f", operation, num1, num2);

  for (int i = 0; i < 65 && input[i] != '\0'; i++) {
    if (input[i] == ' ') {
      continue;
    } else if (input[i] == '.') {
      point = true;
    } else if (input[i] == '-' && is_negative_3 == false &&
               second_number == true) {
      is_negative_3 = true;
    } else if (input[i] == '-' && is_negative_1 == false &&
               first_number == false && !has_digit) {
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
        point_counter++; // pow -> too expensive;
                         // multiplier = multiplier * 10;
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

  if (has_digit == true && first_number == true && second_number == true &&
      is_negative_3 == false) {
    true_result = curr * pow(10, (-point_counter));
  } else if (has_digit == true && first_number == true &&
             second_number == true && is_negative_3 == true) {
    true_result = -1 * (curr * pow(10, (-point_counter)));
  }

  if (operation == '/' && num2 == 0) {
    return false;
  }

  bool calc_ok = calculate(operation, num1, num2, &calc_res, &error);
  if (check_equal(true_result, calc_res) &&
      calc_ok == true) { // TODO: check error too
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

  const int buf_size = 60;
  // #define buf_size 60

  char buffer[60]; // TODO: hardcoded const
                   // read abt argv, pass test.txt as argv[0]

  FILE *fp = fopen("tests.txt", "r");

  if (!fp)
    return ERORR_FILE_NOT_OPENED;

  // if (fp) {
  // TODO: fread once, then work with buffer
  while (fgets(buffer, 60, fp) != NULL) {
    counter++;
    // parse test line -> struct testcase
    // run_testcase(testcase) -> true / false
    if (read_and_check(buffer)) {
      counter_passed_tests++;
      printf("%d %s", counter, "Test passed!\n");
    } else {
      counter_failed_tests++;
      printf("%d %s", counter, "Test failed!\n");
    }
  }
  // }
  printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("%d tests passed\n", counter_passed_tests);
  printf("%d tests failed\n", counter_failed_tests);

  //FIXME: fclose 

  return 0; // true / false; counter_failed_tests
}

//
// read abt sanitizers
// -fsanitize=address

int main(int argc, const char **argv) {
  tests();
  return 0;
}
