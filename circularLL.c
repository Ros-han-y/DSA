#include <stdio.h>
#include <stdlib.h>
struct clist
{
    int data;
    struct clist *next;
};
typedef struct clist node;
node *start = NULL, *last = NULL, *newnode;
void creat()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter element in Node:");
    scanf("%d", &newnode->data);
    if (start == NULL)
    {
        start = newnode;
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        newnode->next = start;
    }
}
void show()
{
    node *temp;
    if (start == NULL)
        printf("Empty circular linked list");
    else
        temp = start;
    printf("Circular linked list contains:\n");
    do
    {
    printf("%d\t",temp->data);
    temp=temp->next;
    } while(temp!=start);
}
void insert_first()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter element in Node:");
    scanf("%d", &newnode->data);
    if (start == NULL)
        printf("circular linked list not found!! first create it....");
    else
    {
        newnode->next = start;
        start = newnode;
        last->next = newnode;
    }
}
void insert_middle()
{
    node *prev, *behind;
    int  pos, i = 1;
    if (start == NULL)
        printf("List not found");
    else if (start == last)
        printf("!!!only one element so middle insertion not possible!!!");
    else
    {
        printf("Enter valid position(i.e existing position):");
        scanf("%d", &pos);
        newnode = (node *)malloc(sizeof(node));
        printf("Enter new element:");
        scanf("%d", &newnode->data);
        behind = start;
        while (i < pos && behind!=last)
        {
            prev = behind;
            behind = behind->next;
            i++;
        }
        prev->next = newnode;
        newnode->next = behind;
    }
}
void insert_last()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter element in Node:");
    scanf("%d",& newnode->data);
    if (start == NULL)
    {
        printf("circular linked list not found!! firstly create it....");
    }
    else
    {
        last->next = newnode;
        last = newnode;
        newnode->next = start;
    }
}
void delete_first()
{
    node *temp;
    temp = start;
    if (start == NULL)
        printf("Empty Circular linked list");
    else if (start == last)
    {
        start = NULL;
        last = NULL;
        free(temp);
    }
    else
    {
        start = start->next;
        last->next = start;
        printf("Deleted node containing:%d", temp->data);
        free(temp);
    }
}
void delete_last()
{
    node *temp;
    temp = last;
    if (last == NULL)
        printf("Empty circular linked list");
    else if (start == last)
    {
        start = NULL;
        last = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != last)
            temp = temp->next;
        temp->next = start;
        printf("Deleted node containing:%d", temp->data);
        free(last);
    last=temp;
    }
}
void delete_middle()
{
    int i=1, pos;
    node  *prev, *behind,*temp;
    if (start == NULL)
        printf("List not found:");
    else
    {
        printf("Enter the valid Position(i.e existing position):");
        scanf("%d", &pos);
        temp=start;
        while (i < pos && temp != last)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        behind=temp->next;
        prev->next = behind;
        printf("Deleted node containing:%d", temp->data);
        free(temp);
    }
}
int main()
{
    printf("*********Implementing Circular Linked List***********");
    printf("\n-----------------------------------------------");
    int choice = 0;
    while (choice != 9)
    {
        printf("\nchoose one from the below options:\n");
        printf("1->creat\n2->Display\n3->Insert at begining \n4->Insert at middle\n5->Insert at last\n6->Delete from first\n7->Delete from middle\n8->Delete from last\n9->Exit");
        printf("\n---------------------------");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creat();
            break;
        case 2:
            show();
            break;
        case 3:
            insert_first();
            break;
        case 4:
            insert_middle();
            break;
        case 5:
            insert_last();
            break;
        case 6:
            delete_first();
            break;
        case 7:
            delete_middle();
            break;
        case 8:
            delete_last();
            break;
        case 9:
            printf("Exiting.......\n");
            break;
        default:
            printf("!! Invalid choice !!");
            break;
        }
    }
    printf("Programmed by Roshan Yadav");
    return 0;
}

