//Linear search using memory allocation
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *arr;
    int search, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

   
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Element not found\n");
    }

    free(arr);

    return 0;
}
