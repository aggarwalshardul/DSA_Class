//WAP write a program on doubly linked list to insert at begginig.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void display(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

    if(ptr == NULL){
        printf("Memory allocation is failed");
        return head;
    }

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if(head != NULL){
        head->prev = ptr;
    }

    return ptr;   // new head
}

struct Node* deleteAtFirst(struct Node* head) {

    if(head == NULL){
        return NULL;
    }

    struct Node* ptr = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }

    free(ptr);
    return head;
}

int main(){

    struct Node* head = NULL;
    struct Node* second;
    struct Node* third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 15;
    second->prev = head;
    second->next = third;

    third->data = 8;
    third->prev = second;
    third->next = NULL;

    printf("Linked List:\n");
    display(head);

    // Insert at beginning
    head = insertAtBeginning(head, 18);
    printf("\nAfter Insertion at Beginning:\n");
    display(head);

    // Delete at beginning
    head = deleteAtFirst(head);
    printf("\nAfter Deletion at Beginning:\n");
    display(head);

    return 0;
}
