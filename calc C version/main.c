#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main() {
    char input[100];
    double ans = 0.0;

    printf(">> ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    while (strcmp(input, "EXIT") != 0) {
        double result = calculate(input, ans);
        printf("%.2lf\n", result);
        ans = result;

        printf(">> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
    }

    return 0;
}