#include <stdio.h>
#define Maxsize 2
int queue[Maxsize], rear = -1, front = 0;
void enqueue()
{
    int n;
    if (rear == Maxsize - 1)
        printf("\nQueue is overflow");
    else
    {
        printf("Enter an element for the insertion:");
        scanf("%d", &n);
        rear++;
        queue[rear] = n;
    }
}
void display()
{
    if (front > rear)
        printf("\nQueue is Empty");
    else
    {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
    }
}
void dequeue()
{
    int n;
    if (front > rear)
        printf("\nQueue is empty");
    else
    {
        n = queue[front];
        front++;
        printf("\nDeleted element:%d", n);
    }
}
int main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n---------Queue Menu-----------");
        printf("\n1.Insert 2.Delete 3.Display 4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting---------");
            break;
        default:
            printf("!!!Invalid choice!!!");
             break;
        }
    }
    printf("\nProgrammed by Roshan Yadav");
    return 0;
}