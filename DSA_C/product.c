//Find the product of two matrix using pointers.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2, i, j, k;
    int a[10][10], b[10][10], res[10][10];

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Column of first matrix not equal to row of second.\n");
        return 0;
    }

    
    int *ptrA = &a[0][0];
    int *ptrB = &b[0][0];
    int *ptrRes = &res[0][0];

    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", (ptrA + i * c1 + j));

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", (ptrB + i * c2 + j));

    
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            *(ptrRes + i * c2 + j) = 0;

    
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                *(ptrRes + i * c2 + j) += (*(ptrA + i * c1 + k)) * (*(ptrB + k * c2 + j));

            }
        }
    }

    printf("Product of Matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", *(ptrRes + i * c2 + j));
        }
        printf("\n");
    }

    return 0;
}