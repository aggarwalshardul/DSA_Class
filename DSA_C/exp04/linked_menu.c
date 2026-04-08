// Queue using Linked List (Menu Driven)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertion() {
    struct Node* newNode;
    int value;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Overflown.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element inserted \n");
}

void deletion() {
    struct Node* temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {  
        rear = NULL;
    }

    free(temp);
}

void display() {
    struct Node* temp;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Menu (Linked List) ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}