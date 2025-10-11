#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ฟังก์ชันนับจำนวนคำในไฟล์
int countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "b.txt");
    if (file == NULL) {
        printf("Cannot open file '%s'\n", filename);
        return -1;
    }

    int count = 0;
    int inWord = 0; // ตัวแปรเช็คว่าอยู่ในคำหรือไม่
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (!isspace(ch)) {
            if (!inWord) {
                inWord = 1; // เริ่มคำใหม่
                count++;
            }
        } else {
            inWord = 0; // เจอ space/enter/tab จบคำ
        }
    }

    fclose(file);
    return count;
}

int main() {
    char filename[100];
    printf("Enter file name:\n");
    scanf("%s", filename);

    int totalWords = countWordsInFile(filename);
    if (totalWords != -1) {
        printf("Total number of words in '%s' : %d words\n", filename, totalWords);
    }

    return 0;
}
