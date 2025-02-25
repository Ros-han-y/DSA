#include<stdio.h>
#include<conio.h>
int fibo(int k)
{
    if(k==1 || k==2)
    return 1;
    else
    return fibo(k-1)+fibo(k-2);
}
int main()
{
    int n;
    printf("Enter the limit upto which you need fibonacci series:");
    scanf("%d",&n);
    printf("Your desired fibonacci series upto %d terms is:\n",n);
    for(int i=1;i<=n;i++)
    printf("%d\t",fibo(i));
    printf("\nprogrammed by Roshan Yadav");
    return 0;
}