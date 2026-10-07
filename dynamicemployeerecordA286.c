#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee *emp;
    int n = 0, choice, i, id;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    if (emp == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    do
    {
        printf("\n===== Employee Record System =====\n");
        printf("1. Add Employee Details\n");
        printf("2. Display Employee Details\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                for (i = 0; i < n; i++)
                {
                    printf("\nEnter details for Employee %d\n", i + 1);

                    printf("Enter ID: ");
                    scanf("%d", &emp[i].id);

                    printf("Enter Name: ");
                    scanf(" %[^\n]", emp[i].name);

                    printf("Enter Salary: ");
                    scanf("%f", &emp[i].salary);
                }
                printf("\nEmployee details added successfully.\n");
                break;

            case 2:
                printf("\n===== Employee Details =====\n");

                for (i = 0; i < n; i++)
                {
                    printf("\nEmployee %d\n", i + 1);
                    printf("ID     : %d\n", emp[i].id);
                    printf("Name   : %s\n", emp[i].name);
                    printf("Salary : %.2f\n", emp[i].salary);
                }
                break;

            case 3:
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &id);

                for (i = 0; i < n; i++)
                {
                    if (emp[i].id == id)
                    {
                        printf("\nEmployee Found!\n");
                        printf("ID     : %d\n", emp[i].id);
                        printf("Name   : %s\n", emp[i].name);
                        printf("Salary : %.2f\n", emp[i].salary);
                        break;
                    }
                }

                if (i == n)
                {
                    printf("\nEmployee not found.\n");
                }
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    free(emp);

    return 0;
}
