//WAP to find sum of all array elements using recursion
#include <stdio.h>

int sum(int arr[], int n){
    if(n==0)
    return 0;
else
    return arr[n-1]+sum( arr,n-1);
}

int main(){
    int n;
    int elem[n];
    printf("Enter no. of elements");
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        printf("Enter element %d :",n+1);
        scanf("%d",&elem[i]);
    }
    int result = sum(arr,n);
    printf(result);

    return 0;
}