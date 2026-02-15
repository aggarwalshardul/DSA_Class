//WAP write a program on single linked list to insert at begginig and delete in beggining.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void linkedlist(struct Node *ptr){
    while (ptr != NULL){
        printf("%d ",ptr->data);
    ptr = ptr->next;
    }
}
struct Node *insert(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node *delete(struct Node *head){
    struct Node *ptr = head;

    if (head == NULL){
        return NULL;
    }

    head = head->next;
    free(ptr);
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head ->next = second;

    second->data = 15;
    second->next = third;

    third->data = 8;
    third->next = NULL;

    linkedlist(head);
    head = insert(head,18);
    printf("After insertion at first \n");
    linkedlist(head);
    head = delete(head);
    printf("After deleting at first\n");
    linkedlist(head);

    return 0;
}