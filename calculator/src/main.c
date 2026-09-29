#include "../input/io.h"

int main() {
    double number1 = 0, number2 = 0;
    char operation = '\0';
    if (input(&number1, &number2, &operation)) {
        output(number1, number2, operation);
    }
    return 0;
}

