#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
char stack[Max];
char infix[Max], postfix[Max];
int top = -1;
void push(char);
char pop();
int isEmpty();
void intopost();
int space(char);
void print();
int precedence(char);
int main()
{
    printf("Enter the infix expressions:");
    gets(infix);
    intopost();
    print();
    printf("Programmed by Roshan Yadav");
    return 0;
}
void intopost()
{
    int i, j = 0;
    char next, symbol;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol)) // if space then return 1(true) then if(!(true))=if(false) so if case not run for space
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                    postfix[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';

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
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
void print()
{
    printf("The equivalent postfix expression is:");
    for(int i=0;i<strlen(infix);i++)
    {
        printf("%c", postfix[i]);
    }
    printf("\n");
}
void push(char c)
{
    if (top == Max - 1)
    {
        printf("Sack overflow\n");
        return; // not return value only indicate the end of the function
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
        exit(1); //terminates entire program
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