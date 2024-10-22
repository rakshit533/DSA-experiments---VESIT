#include <stdio.h>

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
        printf("Pass %d: ", i + 1);
        displayArray(arr, n);
        printf("Explanation: In this pass, the minimum element %d was found and swapped with element %d.\n", arr[i], arr[minIdx]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d: ", i + 1);
        displayArray(arr, n);
        printf("Explanation: In this pass, the largest unsorted element moved to its correct position at the end of the array.\n");
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("Pass %d: ", i);
        displayArray(arr, n);
        printf("Explanation: In this pass, the element %d was inserted into the sorted section of the array.\n", key);
    }
}

int main()
{
    int arr[100], n, choice, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    do {
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int tempArr[100];
        for (i = 0; i < n; i++) {
            tempArr[i] = arr[i];
        }
        switch (choice) {
        case 1:
            printf("Selection Sort:\n");
            selectionSort(tempArr, n);
            break;
        case 2:
            printf("Bubble Sort:\n");
            bubbleSort(tempArr, n);
            break;
        case 3:
            printf("Insertion Sort:\n");
            insertionSort(tempArr, n);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
