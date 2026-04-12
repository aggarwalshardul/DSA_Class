//insert a new complaint into the list 
// insert complaint of type Electricity at beginning o fthe list
//insert all other complaints at the end of the list
//reject duplplicate complaints if the same SAP ID enters the same complaint type again
//display all valid complaints
//display the total number of valid complaint and rejected duplicate complaints

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int SAPID;
    char Complaint_Type[50];
    char description[100];   
    int room_no;
    struct node* next;
} complaint;

complaint* head = NULL;

int valid_count = 0;
int duplicate_count = 0;

int isDuplicate(int SAPID, char type[]) {
    complaint* temp = head;
    while (temp != NULL) {
        if (temp->SAPID == SAPID && strcmp(temp->Complaint_Type, type) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

complaint* createNode(int SAPID, char type[], char desc[], int room_no) {
    complaint* newnode = (complaint*)malloc(sizeof(complaint));
    newnode->SAPID = SAPID;
    strcpy(newnode->Complaint_Type, type);
    strcpy(newnode->description, desc);
    newnode->room_no = room_no;
    newnode->next = NULL;
    return newnode;
}

void insertBeginning(complaint* newnode) {
    newnode->next = head;
    head = newnode;
}

void insertEnd(complaint* newnode) {
    if (head == NULL) {
        head = newnode;
        return;
    }

    complaint* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertComplaint(int SAPID, char type[], char desc[], int room_no) {
    if (isDuplicate(SAPID, type)) {
        printf("DUPLICATE Complaint!");
        duplicate_count++;
        return;
    }

    complaint* newnode = createNode(SAPID, type, desc, room_no);

    if (strcmp(type, "electricity") == 0) {
        insertBeginning(newnode);
    } else {
        insertEnd(newnode);
    }

    valid_count++;
}

void display() {
    complaint* temp = head;

    if (temp == NULL) {
        printf("No complaints found.\n");
        return;
    }

    printf("\nValid Complaints:\n");
    while (temp != NULL) {
        printf("SAP ID: %d | Room: %d | Type: %s | Desc: %s\n",
               temp->SAPID, temp->room_no,
               temp->Complaint_Type, temp->description);
        temp = temp->next;
    }
}


int main() {
    int choice, SAPID, room_no;
    char type[50];
    char desc[100];

    while (1) {
        printf("\n1. Add Complaint\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter SAP ID: ");
                scanf("%d", &SAPID);

                printf("Enter Room No: ");
                scanf("%d", &room_no);

                printf("Enter Complaint Type: ");
                scanf("%s", type);

                printf("Enter Description: ");
                scanf(" %[^\n]", desc); // read full line

                insertComplaint(SAPID, type, desc, room_no);
                break;

            case 2:
                display();
                printf("\nTotal Valid Complaints: %d\n", valid_count);
                printf("Duplicate Rejected: %d\n", duplicate_count);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
