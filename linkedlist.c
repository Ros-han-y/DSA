#include <stdio.h>
#include <stdlib.h>
struct slist
{
    int data;
    struct slist *next;
};
typedef struct slist node;
node *start = NULL;
void creat()
{
    node *temp, *temp1;
    temp = (node *)malloc(sizeof(node));
    temp->next=NULL;
    printf("\nEnter element in Node:");
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
void show()
{
    node *temp;
    temp = start;
    if (temp == NULL)
        printf("\nList is Empty");
    else
    {
        printf("\nThe elements inside list are:\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
void insert_first()
{
    int n;
    node *new1;
    if (start == NULL)
        printf("\nList not found");
    else
    {
        new1 = (node *)malloc(sizeof(node));
        printf("Enter new element to insert in node:");
        scanf("%d", &n);
        new1->data = n;
        new1->next = NULL;
        new1->next = start;
         start = new1;
    }
}
void insert_last()
{
    int n;
    node *new1, *temp;
    if (start == NULL)
        printf("\nList not found");
    else
    {
        printf("Enter new element to insert in node:");
        scanf("%d", &n);
        new1 = (node *)malloc(sizeof(node));
        new1->data = n;
        new1->next = NULL;
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new1;
    }
}
void insert_middle()
{
    node *new1, *prev, *behind;
    int n, pos, i = 1;
    if (start == NULL)
        printf("List not found");
    else
    {
        printf("Enter valid position(i.e existing position):");
        scanf("%d", &pos);
        printf("Enter new element:");
        scanf("%d", &n);
        new1 = (node *)malloc(sizeof(node));
        new1->data = n;
        new1->next = NULL;
        behind = start;
        while (i < pos)
        {
            prev = behind;
            behind= behind->next;
            i++;
        }
        prev->next = new1;
        new1->next = behind;
    }
}
void delete_first()
{
    node *temp;
    if (start == NULL)
        printf("list not found");
    else
    {
        temp = start;
        start = temp->next;
        printf("Deleted node containing:%d", temp->data);
        free(temp);
    }
}
void delete_last()
{
    node *temp, *prev;
    if (start == NULL)
        printf("list not found");
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted node containing:%d", temp->data);
        free(temp);
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
        while (i < pos)
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
    printf("*********Implementing Linked List***********");
    printf("\n-----------------------------------------------");
    int choice = 0;
    while (choice != 9)
    {
        printf("\nchoose one from the below options:\n");
        printf("1->creat\n2->Display\n3->Insert at begining \n4->Insert at middle\n5->Insert at last\n6->Delete from first\n7->Delete from middle\n8->Delete from last \n9->Exit");
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