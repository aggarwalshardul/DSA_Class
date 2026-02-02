// Find the sum of of rows and coloums of matrix of given order (row x coloum)

#include <stdio.h>

int main() {
    int r, c, i, j, sum;
    int matrix[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
   
    printf("\nRow Sums :\n");
    for (i = 0; i < r; i++) {
        sum = 0;
        for (j = 0; j < c; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of Row %d: %d\n", i + 1, sum);
    }

    printf("Column Sums :\n");
    for (j = 0; j < c; j++) {
        sum = 0;
        for (i = 0; i < r; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of Column %d: %d\n", j + 1, sum);
    }

    return 0;
}