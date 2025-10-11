#include <stdio.h>

void armstrong() {
    int number, result = 0, mul, cnt, rem;
    printf("Enter your number: ");
    scanf("%d", &number);

    int q = number;
    int count = 0;
    while (q != 0) {
        q = q / 10;
        count++;
    }
    q = number;
    while (q != 0) {
        rem = q % 10;
        mul = 1;
        cnt = count;
        while (cnt != 0) {
            mul = mul * rem;  
            cnt--;
        }

        result = result + mul;
        q = q / 10;
    }
    if (result == number)
        printf("%d is armstrong number\n", number);
    else
        printf("%d isn't armstrong number\n", number);
}

int main() {
    armstrong();
    return 0;
}
