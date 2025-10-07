#include <stdio.h>

int main(){
    int score = 0;
    printf("Enter your score: ");
    scanf("%d", &score);
    if( score >= 80) {
        printf("A");
    } else if (score >= 75) {
        printf("B+");
    } else if (score >= 70) {
        printf("B");
    } else if (score >= 65) {
        printf("C+");
    } else if (score >= 60) {
        printf("C");
    } else if (score >= 65) {
        printf("D+");
    } else if (score >= 50) {
        printf("D");    
    } else if (score>= 49) {
        printf("F");
    } else {
        printf("please enter number only.");
    }
    return 0;
}