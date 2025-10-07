#include <stdio.h>
#include <string.h>

int main() {
    int number;
    char str[50];
    printf("Enter a number: ");
    scanf("%s", str);

    printf("Result: ");
    for (int i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case '0': printf("Zero "); break;
            case '1': printf("One "); break;
            case '2': printf("Two "); break;
            case '3': printf("Three "); break;
            case '4': printf("Four "); break;
            case '5': printf("Five "); break;
            case '6': printf("Six "); break;
            case '7': printf("Seven "); break;
            case '8': printf("Eight "); break;
            case '9': printf("Nine "); break;
            default: printf("Invalid "); break;
        }
    }

    return 0;
}