#include <stdio.h>
int main()
{
    int a[100], key, i, n;
    printf("Enter the number of element you want in array:");
    scanf("%d", &n);
    printf("Enter %d number in array:\n",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number you want to search:");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("%d is present at location:%d", key, i + 1);
            break;
        }
    }
    if(i==n)
    printf("%d is not present in array",key);
    printf("\nProgrammed by Roshan Yadav");
    return 0;
}