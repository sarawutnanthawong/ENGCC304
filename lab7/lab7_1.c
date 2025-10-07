#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number;
    int randomnumber;
    int play;
    srand(time(NULL));
    do {
        printf("\n----------------------------\n");
        printf("1 for play game or -1 leave game: ");
        scanf("%d", &play);
        if (play == -1) {
            printf("see u again :)\n");
            break;
        }
        int score = 100;
        randomnumber = rand() % 100 + 1;
        printf("\ngame start %d ur score\n", score);
        printf("guess number (1-100):\n");
        do {
            scanf("%d", &number);

            if (number > randomnumber) {
                score -= 10;
                if (score <= 0) {
                    printf("sad ur lose score is 0\n");
                    break;
                }
                printf("ur number is too high number score now is : %d\n", score);
            } 
            else if (number < randomnumber) {
                score -= 10;
                if (score <= 0) {
                    printf("sad ur lose score is 0\n");
                    break;
                }
                printf("ur number is too low number score now is : %d\n", score);
            } 
            else {
                printf("wow ur correct %d\n", score);
                break;
            }
        } while (score > 0);
    } while (play == 1);
    return 0;
}
