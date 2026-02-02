//Store 'n' number (integer) is  any array . Conduct a linear search for a given number and report success and report success or failure in the form of a suitable message
#include <stdio.h>

void shardul(int arr[], int n, int search) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Element is not in the array\n");
    }
}

int main() {
    int n, search;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    shardul(arr, n, search);

    return 0;
}