#include <stdio.h>
#include <conio.h>
int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0)
        return b;
    else
        return gcd(b, r);
}
int main()
{
    int a, b, c;
    printf("Enter two numbers to get their GCD:\n");
    scanf("%d%d", &a, &b);
    if (a > b)
        c = gcd(a, b);
    else
        c = gcd(b, a);
    printf("GCD of(%d,%d)=%d\n", a, b, c);
    printf("Programmed by Roshan Yadav");
    return 0;
}