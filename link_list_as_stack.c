#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node stack;
stack *top = NULL;
void push()
{
    int n;
    printf("Enter your desire value:");
    scanf("%d",&n);
    stack *newnode;
    newnode = (stack *)malloc(sizeof(stack));
    newnode->data = n;
    newnode->next = top;
    top = newnode;
}
void show()
{
    stack *temp;
    temp = top;
    if (temp == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("The elements inside stack is:\n");
        while (temp != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
void pop()
{
    stack *temp;
    temp = top;
    if (top == NULL)
        printf("stack is empty\n");
    else
    {
        printf("popped value=%d", top->data);
        top = top->next;
        free(temp);
    }
}
int main()
{
    printf("*********Stack operations using pointer***********");
    printf("\n-----------------------------------------------");
    int choice=0;
    while (choice != 4)
    {
        printf("\nchoose one from the below options:\n");
        printf("1->push	2->pop	3->show	4->Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
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