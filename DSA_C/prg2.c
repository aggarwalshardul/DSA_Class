//Create an array 'a1' with 'n' elements.Insert an element in i th position and also delete an element from j th position
#include <stdio.h>
 #include <stdlib.h>
 int main(){
    int n, a1[10], x, y;
    printf("Enter number of elemesnts :");
    scanf("%d", &n);

    printf("Enter %d element : ",n);
    for (int i = 0 ; i<n ; i++){
        scanf("%d", &a1[i]);
    }

    printf("Enter the position and value to insert :");
    scanf("%d  %d", &x  , &y);
    for (int i = n ; i>x ; i--){
        a1[i] = a1[i-1];
    }
    a1[x] = y;
    
    printf("Array after insertion is : ");
    for (int i = 0 ; i<n+1 ; i++){
        printf("%d ", a1[i]);
    }
    return 0;
}
