#include <stdio.h>
#include <stdlib.h>

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

void insertion(int a[],int n)
{
    int ele,pos;
    printf("Enter the element and position:");
    scanf("%d %d",&ele,&pos);
    n++,pos--;
    int temp=a[pos];
    a[pos]=ele;
    pos++;
    while(pos<n)
    {
        int temp1=a[pos];
        a[pos]=temp;
        temp=temp1;
        pos++;
    }
    display(a,n);
}

void deletion(int a[],int n)
{
  int i,ind;
  printf("Enter the position:");
  scanf("%d",&ind);
  n--,ind--;
  while(ind<n)
  {
      a[ind]=a[ind+1];
      ind++;
  }
  display(a,n);
}

void merge(int a[],int n)
{
    int i,n1;
    printf("Enter the length of array 2:");
    scanf("%d",&n1);
    int b[n1];
    for(i=0;i<n1;i++)
    {
        printf("Enter element:");
        scanf("%d",&b[i]);
    }
    int c[n+n1];
    for(i=0;i<n;i++)
        c[i]=a[i];
    for(i=0;i<n1;i++)
        c[i+n]=b[i];
    display(c,n+n1);
}

void split(int a[],int n)
{
    int spl,i;
    printf("Enter the no of splits:");
    scanf("%d",&spl);
    int split[spl+1];
    split[spl]=n;
    printf("Enter the positions:");
    for(i=0;i<spl;i++)
    {
        scanf("%d",&split[i]);
    }
    int j=0;
    for(i=0;i<spl+1;i++)
    {
        printf("\nArray %d:",i+1);
        while(j<split[i])
        {
            printf("%d ",a[j]);
            j++;
        }
        j=split[i];

    }

}

void rotate(int a[],int n)
{
    int rot,i;
    printf("Enter no of rotations:");
    scanf("%d",&rot);
    for(i=0;i<rot;i++)
    {
        int temp=a[0],j=0;
        while(j<n-1)
        {
            a[j]=a[j+1];
            j++;
        }
        a[n-1]=temp;
    }
    display(a,n);
}

int main()
{
    int n,i,ch;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    printf("1.Insert\n2.Delete\n3.Merge\n4.Split\n5.Rotate\n6.Display\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
            insertion(a,n);
            break;

    case 2:
        {
            deletion(a,n);
            break;
        }
    case 3:

        {
            merge(a,n);
            break;
        }
    case 4:
        {
            split(a,n);
            break;
        }
    case 5:
        {
            rotate(a,n);
            break;
        }
    case 6:
        {
            display(a,n);
            break;
        }
    default:
        {
            printf("Invalid choice");
        }
    }
    return 0;
}
