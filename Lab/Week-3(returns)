#include <stdio.h>
#include <stdlib.h>
void input(int arr[],int n){
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
void output(int arr[],int n){
    int i;
    printf("\nSorted Array : ");
    for(i=0;i<n;i++)
        printf("%d,",arr[i]);
}
int bubble(int arr[], int n){
    int i,j,counter=0;
    for(i=0;i<n-1;i++){
        int check = 0;
        for(j=0;j<n-i-1;j++){
            counter++;
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                check = 1;
            }
        }
        if(!check)
            break;
    }
    return counter;
}
int selection(int arr[], int n){
    int i,j,counter=0;
    for(i=0;i<n;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            counter++;
            if(arr[min] > arr[j])
                min=j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    return counter;
}
int insertion(int arr[], int n){
    int i,j,counter=0;
}
int main()
{
    int n;
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d elements :\n",n);
    input(arr,n);
    int choice;
    printf("\nEnter:\n(1)Bubble Sort\n(2)Selection Sort\n(3)Insertion sort\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("\nBest case : %d iterations\nWorst case : %d iterations\nNumber of iterations for given array : %d",n-1,n*n,bubble(arr,n));
            break;
        case 2:
            printf("\nBest case : %d iterations\nWorst case : %d iterations\nNumber of iterations for given array : %d",n-1,n*n,selection(arr,n));
            break;
        case 3:
            printf("\nBest case : %d iterations\nWorst case : %d iterations\nNumber of iterations for given array : %d",n,n*n,insertion(arr,n));
            break;
        default:
            printf("\nINVALID CHOICE !!!");
            return;
    }
    output(arr,n);
    return 0;
}
