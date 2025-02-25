#include<stdio.h>
#include<conio.h>
int factorial(int n)
{
    if(n==0)
    return 1;
    else
    return n*factorial(n-1);
}
int main()
{
    int n,facto;
    printf("Enter the desire number to get factorial:");
    scanf("%d",&n);
    facto=factorial(n);
    printf("factorial of %d=%d",n,facto);
    printf("\nprogrammed by Roshan Yadav");
    return 0;
}