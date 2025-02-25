#include <stdio.h>
#include <conio.h>
int stack[100], i, j, choice = 0, n, top = -1;
void push()
{
    int value;
    if (top == n-1)
        printf("\nstack overflow");
    else
    {
        printf("Enter the value:");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}
void pop()
{
    if (top == -1)
        printf("Stack is Empty");
    else
    printf("%d is popped out from stack",stack[top]);
        top--;
}
void show()
{
	printf("Inside stack:\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is Empty");
    }
}
int main()
{
    printf("Enter the number of elements in the stack:");
    scanf("%d", &n);
    printf("*********Stack operations using array***********");
    printf("\n-----------------------------------------------");
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