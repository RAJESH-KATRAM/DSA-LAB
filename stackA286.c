#include <stdio.h>

#define MAX 5

int main()
{
    int stack[MAX];
    int top = -1;
    int choice, value, i;

    while (1)
    {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (top == MAX - 1)
            {
                printf("Stack Overflow");
            }
            else
            {
                printf("Enter value: ");
                scanf("%d", &value);

                top++;
                stack[top] = value;

                printf("Element pushed successfully");
            }
        }

        else if (choice == 2)
        {
            if (top == -1)
            {
                printf("Stack Underflow");
            }
            else
            {
                printf("Popped element: %d", stack[top]);
                top--;
            }
        }

        else if (choice == 3)
        {
            if (top == -1)
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Stack elements:\n");

                for (i = top; i >= 0; i--)
                {
                    printf("%d\n", stack[i]);
                }
            }
        }

        else if (choice == 4)
        {
            break;
        }

        else
        {
            printf("Invalid choice");
        }
    }

    return 0;
}
