#include "../input/calc_operations.h" // FIXME: relative include
#include <stdio.h>
#include <string.h>

double input(double *number1, double *number2, char *operation) {

  // FIXME: bad copypaste
  // 1. function
  // 2. macros
  //

#define INPUT_NUM(num)                                                         \
  do {                                                                         \
    printf("Input first number, then press enter: ");                          \
    if (scanf("%lf", number1) == 0) {                                          \
      printf("You entered an invalid symbol. Please try again.");              \
      return INVALID_NUMBER_INPUT;                                             \
    }                                                                          \
  } while (0)

  INPUT_NUM(number1);
  INPUT_NUM(number2);

  printf("Input an operation: * / + -, then press enter: ");
  //                                   nice
  //.,................................. ||
  //....................................\/
  if (scanf(" %c", operation) != 1 || strchr("*/+-", *operation) == NULL) {
    printf("You entered an invalid operation. Please try again.");
    return INVALID_OPERATION_INPUT;
  }

  assert(scanf(" %c", operation) != 1 || strchr("*/+-", *operation) == NULL);

// #define CHECK(cond, text, err)                                                 \
//   do {                                                                         \
//     if (!(condition)) {                                                        \
//       printf(text);                                                            \
//       return err;                                                              \
//     }                                                                          \
//   } while (0)

  // CHECK(scanf(" %c", operation) != 1 || strchr("*/+-", *operation) == NULL,
  //       "you are dumb.", INVALID_NUMBER_INPUT);

  return OK; // nice
}

double output(double number1, double number2, char operation) {
  double res = 0.0;
  ERROR_CODES error;
  if (calculate(operation, number1, number2, &res, &error)) {
    printf("Result: %.3f\n", res);
  } else {
    printf("Operation returned false. Please try again.\n");
  }

  return 0; // why double? and why 0 if you have 'OK';
}
