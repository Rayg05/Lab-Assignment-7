#include <stdio.h>
#include <stdbool.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n, int swapCount[]) {
    int i, j, min_idx, totalSwaps = 0;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
            swapCount[arr[min_idx]]++;// Increment swap count for the moved number
            swapCount[arr[i]]++; // 
            totalSwaps++;
        }
    }
    printf("Total number of swaps: %d\n", totalSwaps);
}

void bubbleSort(int arr[], int n, int swapCount[]) {
    int i, j, totalSwaps = 0; // Initialize total swaps to zero
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapCount[arr[j]]++; // Increment swap count for the moved number
                swapCount[arr[j+1]]++;
                totalSwaps++;
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
    printf("Total number of swaps: %d\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(array1) / sizeof(array1[0]);

    // Initialize swap count arrays
    int swapCount1[100] = {0}; // Assuming the maximum number in the arrays is 100
    int swapCount2[100] = {0};
    int swapCount3[100] = {0}; // Assuming the maximum number in the arrays is 100
    int swapCount4[100] = {0};
    
    printf("BUBBLE SORTS:\n\n");
    printf("Array 1:\n");
    bubbleSort(array1, n, swapCount1);
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped: %d\n", array1[i], array1[i], swapCount1[array1[i]]);
    }
    printf("Array 2:\n");
    bubbleSort(array2, n, swapCount2);
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped: %d\n", array2[i], array2[i], swapCount2[array2[i]]);
    }
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    printf("SELECTION SORTS:\n\n");
    
    printf("\nArray 2:\n");
    selectionSort(array3, n, swapCount3);
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped: %d\n", array3[i], array3[i], swapCount3[array3[i]]);
    }
    
    printf("\nArray 2:\n");
    selectionSort(array4, n, swapCount4);
    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped: %d\n", array4[i], array4[i], swapCount4[array4[i]]);
    }

    return 0;
}
