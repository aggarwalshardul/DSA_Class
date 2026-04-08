//WAP to implement a stack data stuctures using array
//includes push pop peek display check overflow and under flow conditions.

#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int item){
       if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = item;
        printf("%d pushed into stack\n", item);
    }
    
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    
    } else {
        int item = stack[top];
        top--;
        printf("%d is deleted",item);
    }
}

void peek(){
    if (top<0){
        printf("Stack is empty\n");
        return;
    }
    printf("Top stack value: %d",stack[top]);
    
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}