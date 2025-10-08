#include <stdio.h>
#include <stdlib.h>

// ------------------ Function Prototypes ------------------
void loadScores(char *filename, int student_ids[], int scores[], int *count);
void findMinMax(int scores[], int count, int *min, int *max);
void sortScores(int student_ids[], int scores[], int count);
int binarySearch(int student_ids[], int scores[], int count, int student_id);

// ------------------ Function Definitions ------------------

// อ่านข้อมูลจากไฟล์และเก็บใน array
void loadScores(char *filename, int student_ids[], int scores[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file '%s'\n", filename);
        return;
    }

    *count = 0;
    while (fscanf(file, "%d %d", &student_ids[*count], &scores[*count]) == 2) {
        (*count)++;
    }

    fclose(file);
    printf("Scores loaded successfully!\n");
}

// หาค่าต่ำสุดและสูงสุดของคะแนน
void findMinMax(int scores[], int count, int *min, int *max) {
    int *ptr = scores;
    *min = *max = *ptr;

    for (int i = 1; i < count; i++) {
        ptr = scores + i;
        if (*ptr < *min) *min = *ptr;
        if (*ptr > *max) *max = *ptr;
    }
}

// เรียงลำดับคะแนนจากต่ำไปสูง (Bubble Sort)
void sortScores(int student_ids[], int scores[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                // สลับคะแนน
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                // สลับรหัสนักเรียนตามคะแนน
                int tempID = student_ids[j];
                student_ids[j] = student_ids[j + 1];
                student_ids[j + 1] = tempID;
            }
        }
    }

    printf("Sorted Scores:\n");
    for (int i = 0; i < count; i++) {
        printf("Student ID: %d, Score: %d\n", student_ids[i], scores[i]);
    }
}

// ค้นหาคะแนนของนักเรียนด้วย binary search (ค้นหา student_id)
int binarySearch(int student_ids[], int scores[], int count, int student_id) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (student_ids[mid] == student_id)
            return scores[mid];
        else if (student_ids[mid] < student_id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

// ------------------ Main Program ------------------
int main() {
    int student_ids[100];
    int scores[100];
    int count = 0;
    int choice;
    int min, max;
    char filename[] = "scores.txt";

    do {
        printf("\nStudent Score Management\n");
        printf("1. Load Scores from File\n");
        printf("2. Show Min and Max Scores\n");
        printf("3. Sort Scores in Ascending Order\n");
        printf("4. Search Score by Student ID\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loadScores(filename, student_ids, scores, &count);
                break;
            case 2:
                if (count == 0) {
                    printf("Please load data first!\n");
                } else {
                    findMinMax(scores, count, &min, &max);
                    printf("Minimum Score: %d\n", min);
                    printf("Maximum Score: %d\n", max);
                }
                break;
            case 3:
                if (count == 0) {
                    printf("Please load data first!\n");
                } else {
                    sortScores(student_ids, scores, count);
                }
                break;
            case 4:
                if (count == 0) {
                    printf("Please load data first!\n");
                } else {
                    int id;
                    printf("Enter Student ID to Search: ");
                    scanf("%d", &id);
                    int result = binarySearch(student_ids, scores, count, id);
                    if (result != -1)
                        printf("Score for Student ID %d: %d\n", id, result);
                    else
                        printf("Student ID %d not found.\n", id);
                }
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

