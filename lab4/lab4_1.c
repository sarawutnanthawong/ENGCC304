#include <stdio.h>

int main(){
    int day = 0;
    printf("Input Day : ");
    scanf("%d", &day);
    int seconds = 0;
    seconds = day * 24 * 60 * 60;
    printf("%d day = %d seconds",day ,seconds);
    return 0;
}