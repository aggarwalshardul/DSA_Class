#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

int countStudents() {
    int count = 0;
    struct Student* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertBeginning() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Roll Number: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = head;
    head = newNode;

    printf("Student inserted at beginning successfully!\n");
}

void insertEnd() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    struct Student* temp = head;

    printf("Enter Roll Number: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Student inserted at end successfully!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    struct Student* temp = head;
    struct Student* prev = NULL;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

   
    if (temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("Student deleted \n");
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student deleted successfully!\n");
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    struct Student* temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("\nStudent Found:\n");
            printf("Roll: %d\n", temp->roll);
            printf("Name: %s\n", temp->name);
            printf("Marks: %.2f\n", temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student not found!\n");
}

void displayStudents() {
    struct Student* temp = head;

    if (temp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Display Students\n");
        printf("6. Count Students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBeginning();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                displayStudents();
                break;
            case 6:
                printf("Total Students: %d\n", countStudents());
                break;
            case 7:
                printf("Exiting \n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
