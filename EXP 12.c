#include <stdio.h>
#include <string.h>

#define MAX 100

int binarySearch(char arr[][MAX], int left, int right, char* target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(arr[mid], target);

        if (res == 0)
            return mid;
        if (res < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, result;
    char target[MAX];

    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &n);

    char dictionary[n][MAX];
    printf("Enter the words in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", dictionary[i]);
    }

    printf("Enter the word to search: ");
    scanf("%s", target);

    result = binarySearch(dictionary, 0, n - 1, target);

    if (result != -1)
        printf("Word '%s' found at index %d.\n", target, result);
    else
        printf("Word '%s' not found in the dictionary.\n", target);

    return 0;
}

