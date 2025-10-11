#include <stdio.h>

struct Student {
    char Name[20];
    char ID[5];
    float ScoreSub1;
    float ScoreSub2;
    float ScoreSub3;
    float ScoreSub4;
    float ScoreSub5;
} typedef S;

const char* grade(float score) {
    if (score >= 80) return "A";
    else if (score >= 75) return "B+";
    else if (score >= 70) return "B";
    else if (score >= 65) return "C+";
    else if (score >= 60) return "C";
    else if (score >= 55) return "D+";
    else if (score >= 50) return "D";
    else return "F";
}

float average(float s1, float s2, float s3, float s4, float s5) {
    return (s1 + s2 + s3 + s4 + s5) / 5.0;
}

int main() {
    S student[3];
    int i;

    printf("Enter the details of 3 students :\n");

    for (i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name:\n");
        scanf(" %[^\n]", student[i].Name);

        printf("ID:\n");
        scanf(" %s", student[i].ID);

        printf("Scores in Subject 1:\n");
        scanf("%f", &student[i].ScoreSub1);
        printf("Scores in Subject 2:\n");
        scanf("%f", &student[i].ScoreSub2);
        printf("Scores in Subject 3:\n");
        scanf("%f", &student[i].ScoreSub3);
        printf("Scores in Subject 4:\n");
        scanf("%f", &student[i].ScoreSub4);
        printf("Scores in Subject 5:\n");
        scanf("%f", &student[i].ScoreSub5);
    }

    printf("\n");

    for (i = 0; i < 3; i++) {
        float avg = average(student[i].ScoreSub1, student[i].ScoreSub2,
                            student[i].ScoreSub3, student[i].ScoreSub4, student[i].ScoreSub5);

        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", student[i].Name);
        printf("ID: %s\n", student[i].ID);
        printf("Scores: %.0f %.0f %.0f %.0f %.0f\n",
               student[i].ScoreSub1, student[i].ScoreSub2,
               student[i].ScoreSub3, student[i].ScoreSub4, student[i].ScoreSub5);
        printf("Grades: %s %s %s %s %s\n",
               grade(student[i].ScoreSub1), grade(student[i].ScoreSub2),
               grade(student[i].ScoreSub3), grade(student[i].ScoreSub4),
               grade(student[i].ScoreSub5));
        printf("Average Scores: %.1f\n\n", avg);
    }

    return 0;
}
