#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int choice, value, i;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rear == MAX - 1)
                {
                    printf("Queue Overflow");
                }
                else
                {
                    printf("Enter value: ");
                    scanf("%d", &value);

                    if (front == -1)
                        front = 0;

                    rear++;
                    queue[rear] = value;

                    printf("Element inserted");
                }
                break;

            case 2:
                if (front == -1 || front > rear)
                {
                    printf("Queue Underflow");
                }
                else
                {
                    printf("Deleted element: %d", queue[front]);
                    front++;
                }
                break;

            case 3:
                if (front == -1 || front > rear)
                {
                    printf("Queue is empty");
                }
                else
                {
                    printf("Queue elements:\n");

                    for (i = front; i <= rear; i++)
                    {
                        printf("%d ", queue[i]);
                    }
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}
