#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[100];
    int length, isPalindrome = 1;

    printf("Enter word:\n");
    scanf("%s", word);

    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    length = strlen(word);

    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Pass.\n");
    else
        printf("Not Pass.\n");

    return 0;
}
