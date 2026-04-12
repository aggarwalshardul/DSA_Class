//push the visted stack
//remove the most recent page if the user enteres back
//not store page twice if enterd continuously
//display the current browsing history

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char pages[MAX];
    int top;
} Stack;


int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char page[]) {
    if (isFull(s)) {
        printf("MEMORY OVERFLOW");
        return;
    }

    if (!isEmpty(s) && strcmp(s->pages[s->top], page) == 0) {
        printf("Duplicate");
        return;
    }

    s->top++;
    strcpy(s->pages[s->top], page);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("No pages to go back.\n");
        return;
    }

    printf("Going back from: %s\n", s->pages[s->top]);
    s->top--;
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("No browsing history.\n");
        return;
    }

    printf("\nBrowsing History:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%s\n", s->pages[i]);
    }
}

void currentPage(Stack *s) {
    if (isEmpty(s)) {
        printf("No current page.\n");
        return;
    }

    printf("Current Page: %s\n", s->pages[s->top]);
}

void totalPages(Stack *s) {
    printf("Total Pages: %d\n", s->top + 1);
}

int main() {
    Stack s;

    char input[100];
    int choice;

    while (1) {
        printf("\n1. Visit Page\n2. Back\n3. Display History\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter page name: ");
                scanf("%s", input);
                push(&s, input);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                display(&s);
                currentPage(&s);
                totalPages(&s);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
