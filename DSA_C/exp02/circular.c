//WAP write a program on circular linked list to insert at begining delete in begining.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head){
    if(head == NULL){
        printf("List is empty");
        return;
    }

    struct Node* ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
}

int countNodes(struct Node* head){
    if(head == NULL){
        return 0;
    }

    int count = 0;
    struct Node* ptr = head;

    do{
        count++;
        ptr = ptr->next;
    } while(ptr != head);

    return count;
}

struct Node* insert(struct Node* head, int data){

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    
    if(head == NULL){
        ptr->next = ptr;   
        return ptr;
    }

    struct Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    ptr->next = head;
    temp->next = ptr;

    return ptr;  
}

struct Node* delete(struct Node* head){

    if(head == NULL){
        return NULL;
    }

    
    if(head->next == head){
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* last = head;

    while(last->next != head){
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
    return head;
}

int main(){

    struct Node* head = NULL;

    head = insert(head, 8);
    head = insert(head, 15);
    head = insert(head, 7);

    printf(" Circular Linked List:\n");
    display(head);
    printf("\nTotal Nodes: %d", countNodes(head));

    head = insert(head, 18);
    printf("\n\nAfter Insertion at Beginning:\n");
    display(head);
    printf("\nTotal Nodes: %d", countNodes(head));

    head = delete(head);
    printf("\n\nAfter Deletion at Beginning:\n");
    display(head);
    printf("\nTotal Nodes: %d", countNodes(head));

    return 0;
}
