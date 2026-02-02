#include <stdio.h>
int main(){
    int x;
    int *ptr1 = &x;
    printf("%zu",sizeof(ptr1));
    return 0;
    
}