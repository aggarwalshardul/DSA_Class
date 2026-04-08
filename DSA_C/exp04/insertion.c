//WAP to insert in queue
// WAP to implement Queue (Insertion and Display)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void insertion() {
    int n, data;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        if (rear == MAX - 1) {
            printf("Queue Overflow\n");
            return;
        }

        printf("Enter value: ");
        scanf("%d", &data);

        if (front == -1) {   
            front = 0;
        }

        rear++;
        queue[rear] = data;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {

    insertion();
    display();

    return 0;
}