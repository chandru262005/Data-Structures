//Program to find the maximum subarray [Kadane's Algo]
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    int cur_sum=0,max_sum=a[0];
    for(int i=0;i<n;i++)
    {
        cur_sum+=a[i];
        if(cur_sum>max_sum)
            max_sum=cur_sum;
         if(cur_sum<0)
            cur_sum=0;
        
     }
     printf("Maximum sum of Subarray is %d",max_sum);
}