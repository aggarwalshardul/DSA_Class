//Structure Demonstration: Structure are used to group different data type under a single name enabling organized data storage and acess
// Structure Demonstration:
// Structures are used to group different data types under a single name
// to represent a real-world entity (Employee).

#include <stdio.h>


struct Employee {
    int emp_id;
    char emp_name[30];
    float salary;
};

int main() {
    struct Employee e;

    
    printf("Enter Employee ID: ");
    scanf("%d", &e.emp_id);

    printf("Enter Employee Name: ");
    scanf("%s", e.emp_name);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    
     printf("\nEmployee Details:\n");
    printf("ID     : %d\n", e.emp_id);
    printf("Name   : %s\n", e.emp_name);
    printf("Salary : %.2f\n", e.salary);

    return 0;
}
