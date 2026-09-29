
// FIXME: relative path in include
// clang main.c -I./include/stin
//
// /usr/include ; /usr/lib/include/ ...
//
#include "io.h"

int main() {
    double number1 = 0, number2 = 0; // NaN maybe
    char operation = '\0';

    if (input(&number1, &number2, &operation)) {
        // logic??
        // fixme: split into function
        output(number1, number2, operation);
    }

    return 0;
}

