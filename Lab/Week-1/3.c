//To find the pivot element in rotated and sorted array
#include <stdio.h>
int pivot (int a[],int n){
  int min=0,max=n-1,mid,temp;
    while(min<max)
    {
      mid=(min+max)/2;
      if(a[mid-1]>a[mid])
        return mid;
      else if(a[mid]>a[mid+1])
        return mid+1;
      else if(a[mid]>a[min])
        min=mid+1;
      else if(a[mid]<a[max])
        max=mid-1;
       
    }

}
void main()
{
    int n;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements separated by space:");
    for(int i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("Pivot element:%d at index:%d",a[pivot(a,n)],pivot(a,n));

}