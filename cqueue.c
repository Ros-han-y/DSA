#include <stdio.h>
#define Maxsize 2
int cqueue[Maxsize], rear = -1, front = -1;
void enqueue()
{
    int n;
    if ((rear + 1) % Maxsize == front)
        printf("\nQueue is overflow");
    else
    {
        printf("Enter an element for the insertion:");
        scanf("%d", &n);
        if (rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
            rear = (rear + 1) % Maxsize;
        cqueue[rear] = n;
    }
}
void display()
{
    if (rear == -1 && front == -1)
        printf("\nQueue is Empty");
    else
    {
        int i;
        printf("Queue elements are:\n");
        {
            for ( i = front; i != rear; (i = (i + 1) % Maxsize))
                printf("%d\t", cqueue[i]);
        }
        printf("%d", cqueue[i]);
    }
}
void dequeue()
{
    int n;
    if (rear == -1 && front == -1)
        printf("\nQueue is empty");
    else
    {
        n = cqueue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % Maxsize;
        printf("\nDeleted element:%d", n);
    }
}
int main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n---------Circular Queue Menu-----------");
        printf("\n1.Enqueue 2.Dequeue 3.Traverse 4.Exit");
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