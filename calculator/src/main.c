#include <stdio.h>
#include "io.h"
#include "math.h"
#include "calc_operations.h"


//enum COMMANDS {
//  exit = 'E',

//}
int main() {
    double number1 = NAN, number2 = NAN, res = NAN;
    char operation = '\0';
    bool flag = true;
    while (flag) {
        if (input(&number1, &number2, &operation) != SUCCESS){
            continue;
        }
        
        if (operation == 'E') {
            return false;
        } 
        if (calculate(operation, number1, number2, &res) == SUCCESS) {
            printf("Result: %.3f\n", res);
        } else {
            printf("Error: %d\n", output(number1, number2, operation));
        }
    }
}


