#include <stdio.h>

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[100];
    int n = 0;
    
    printf("Enter value:\n");

    while (scanf("%d", &arr[n]) == 1) {
        n++;
        if (getchar() == '\n') break;
    }

    printf("Index: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");


    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    int minVal = findMin(arr, n);
    int maxVal = findMax(arr, n);
    printf("Min : %d\n", minVal);
    printf("Max : %d\n", maxVal);

    return 0;
}
