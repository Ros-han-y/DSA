#include <stdio.h>
#include <conio.h>
void TOH(int n, char S, char D, char I)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, S, D);
        return;
    }
    TOH(n - 1, S, I, D);
    printf("Move disk %d from %c to %c\n", n, S, D);
    TOH(n - 1, I, D, S);
}
int main()
{
    int n;
    printf("Enter no of disk:");
    scanf("%d", &n);
    TOH(n, 'S', 'D', 'I');
    printf("Programmed by Roshan Yadav");
}