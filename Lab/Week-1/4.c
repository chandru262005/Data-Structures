//Program to find the next larger element in unsorted array
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
       printf("Enter element %d:",i+1);
       scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]<a[j])
            {
                printf("\nNext greater element of %d is %d",a[i],a[j]);
                break;
            }
            if(j==n-1)
              printf("\nNext greater element of %d is -1",a[i]);
        }
    }
}