#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
char stack[Max];
char infix[Max], prefix[Max];
int top = -1;
void push(char);
char pop();
int isEmpty();
void intopre();
int space(char);
void print();
int precedence(char);
int main()
{
    printf("Enter the infix expressions:");
    gets(infix);
    intopre();
    print();
    printf("Programmed by Roshan Yadav");
    return 0;
}
void intopre()
{
    int i, j = 0;
    char next, symbol;
    for (i =strlen(infix)-1; i>-1; i--)
    {
        symbol = infix[i];
        if (!space(symbol))
        {
            switch (symbol)
            {
            case ')':
                push(symbol);
                break;
            case '(':
                while ((next = pop()) != ')')
                    prefix[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    prefix[j++] = pop();
                push(symbol);
                break;
            default:
                prefix[j++] = symbol;
            }
        }
    }
    while (!isEmpty())
        prefix[j++] = pop();
    prefix[j] = '\0';

}
int space(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
void print()
{
    printf("The equivalent prefix expression is:");
    for(int i=strlen(infix)-1;i>-1;i--)
    {
        printf("%c", prefix[i]);
    }
    printf("\n");
}
void push(char c)
{
    if (top == Max - 1)
    {
        printf("Sack overflow\n");
        return; // indicate the end of the function
    }
    top++;
    stack[top] = c;
}
char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}