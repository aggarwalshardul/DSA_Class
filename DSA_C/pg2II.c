// Create an array 'a1' with 'n' elements.
// also delete an element from jth position of 'a1'

#include <stdio.h>
 #include <stdlib.h>
 int main(){
    int n, a1[10],x;
    printf("Enter number of elements :");
    scanf("%d", &n);

    printf("Enter %d element : ",n);
    for (int i = 0 ; i<n ; i++){
        scanf("%d", &a1[i]);
    }

    printf("Enter the position to delete  :");
    scanf("%d", &x);
    for (int i = x ; i<n-1 ; i++){
        a1[i] = a1[i+1];
   }
    printf("Array after deletion is : ");
    for (int i = 0 ; i<n-1 ; i++){
        printf("%d ", a1[i]);
    }
    return 0;
}