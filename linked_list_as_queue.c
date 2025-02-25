#include <stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue node;
node *start=NULL;
int  rear = -1, front = 0;
void enqueue()
{
     node *temp, *temp1;
    temp = (node *)malloc(sizeof(node));
    temp->next=NULL;
    printf("Enter element in Queue:");
    scanf("%d", &temp->data);
    if (start == NULL)
        start = temp;
    else
    {
        temp1 = start;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}
void display()
{
    node *temp;
    temp = start;
    if (temp == NULL)
        printf("\nQueue is empty");
    else
    {
        printf("\nThe elements inside  Queue:\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
void dequeue()
{
     node *temp;
    if (start == NULL)
        printf("Queue is empty");
    else
    {
        temp = start;
        start = temp->next;
        printf("Deleted element is:%d", temp->data);
        free(temp);
    }
}
int main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n---------Queue Menu using pointer-----------");
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