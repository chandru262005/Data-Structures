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
    int rot,i,dir;
    printf("Enter the direction:\n0.Right\n1.Left\n");
    scanf("%d",&dir);
    printf("Enter no of rotations:");
    scanf("%d",&rot);
    if(dir)
    {
    for(i=0;i<rot;i++)
    {
        int temp=a[n-1],j=n-1;
        while(j>0)
        {
            a[j]=a[j-1];
            j--;;
        }
        a[0]=temp;
    }
    }
    else{
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
    }
    display(a,n);
}
void copy(int a[],int n)
{
    printf("Copied array:\n");
    display(a,n);
}
void swap(int a[],int n)
{
    int i,j,temp;
    printf("Enter the indexes to be swapped:");
    scanf("%d %d",&i,&j);
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    display(a,n);
}
void update(int a[],int n)
{
    int i,j;
    printf("Enter the index and the element:");
    scanf("%d %d",&i,&j);
    a[i]=j;
    display(a,n);
}
int main()
{
    int *a,n,i,ch,cho;
    label:
    printf("1.Initialization\n2.Delete\n3.Merge\n4.Split\n5.Rotate\n6.Display\n7.Copy\n8.Swap\n9.Traverse\n10.Updating\n11.Insertion\nEnter choice:");
    scanf("%d",&ch);
    printf("Enter the no of elements:");
    scanf("%d",&n);
    *a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter element:");
        scanf("%d",&a[i]);
    }


    switch(ch)
    {
    case 1:
       {
        printf("1.Initialization\n2.Delete\n3.Merge\n4.Split\n5.Rotate\n6.Display\n7.Copy\n8.Swap\n9.Traverse\n10.Updating\n11.Insertion\nEnter choice:");
        scanf("%d",&ch);
           break;
       }
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
            display(a,n);    //traversing and displaying
            break;
        }
    case 7:
        {
            copy(a,n);
            break;
        }
    case 8:
        {
            swap(a,n);
            break;
        }
    case 9:
        {
            display(a,n);
            break;
        }
    case 10:
        {
            update(a,n);
            break;
        }
    case 11:
        {
            insertion(a,n);
            break;

        }
    default:
        {
            printf("Invalid choice");
        }
    }
    printf("continue:");
    scanf("%d",&cho);
    if(cho)
    goto label;
    return 0;
}
