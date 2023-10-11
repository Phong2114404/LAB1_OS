#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

double calculate(char* input, double ans) {
    char* token;
    double num1, num2;
    char operator;
    double result = 0.0;
    char* error = "SYNTAX ERROR";

    token = strtok(input, " ");
    if (strcmp(token, "ANS") == 0) {
        num1 = ans;
    } else {
        num1 = atof(token);
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        return num1;
    }

    operator = token[0];

    token = strtok(NULL, " ");
    if (strcmp(token, "ANS") == 0) {
        num2 = ans;
    } else {
        num2 = atof(token);
    }

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                error = "MATH ERROR";
            }
            break;
        case '%':
            result = (int)num1 % (int)num2;
            break;
        default:
            return atof(error);
    }

    return result;
}