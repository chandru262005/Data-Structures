#include <stdio.h>
void main()
{
    int n;
    printf("Enter the no of elements");
    scanf("%d",&n);
    int a[n],temp[n],count;
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    int len=0;
    printf("Elements   Count");
    for(int i=0;i<n;i++)
    {
        count=0;
        int flg=1;
        for(int k=0;k<len;k++)
            {
              if(a[i]==temp[k]){
                flg=0;
                break;
            }
            }
        for(int j=i;j<n;j++)
        {
               if(flg==0)
            break;
            else{
                temp[len]=a[i];
                len++;

            }
            if(a[i]==a[j])
            count++;
             }
        if((count%2)!=0)
        printf("\n%d\t%d",a[i],count);
    }
    
}