//linked list creation
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void display(node* temp)
{
 int i=0;
    while(temp!=NULL)
    {
        printf("Node %d\tData %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}

node* create(node* ptr)
{
    
    ptr->next=(node*)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&ptr->next->data);
    ptr->next->next=NULL;
    ptr=ptr->next;
    return ptr;
}

node* reverse(node* ptr)
{
    node* prev=NULL;
    node* cur=ptr;
    node* nex=ptr->next;
    while(nex!=NULL)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;

    }
    return prev;
   
}

void delete(node* ptr,int n)
{
    node* temp;
    while(n)
    {
        temp=ptr;
        ptr=ptr->next;
        n--;
    }
    temp->next=ptr->next;
    free(ptr);
}

void insert(node* ptr,int n)
{
    node* temp;
    while(n)
    {
        temp=ptr;
        ptr=ptr->next;
        n--;
    }
    temp->next=(node*)malloc(sizeof(node));
    printf("Enter new data:");
    scanf("%d",&temp->next->data);
    temp->next->next=ptr;
}

void swapp(node* ptr,int n)//YET TO BE DONE
{
    // node* prev=NULL;
    // node* cur=ptr;
    // node* nex=ptr->next;
    // while(n)
    // {
    //     nex=cur->next;
    //     cur->next=prev;
    //     prev=cur;
    //     cur=nex;

    //     n--;
    // }
    // temp->next=(node*)malloc(sizeof(node));
    // printf("Enter new data:");
    // scanf("%d",&temp->next->data);
    // temp->next->next=ptr;
}

void main()
{
    int n,ch,yn=1,pos;
    node* head=(node*)malloc(sizeof(node));
    while(yn)
    {
    printf("1,Create\n2.Display\n3.Reverse\n4.Insert\n5.Delete\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
             printf("Enter head data:");
             scanf("%d",&head->data);
             printf("Enter the no of nodes:");
             scanf("%d",&n);
           node* temp=head;
           for(int i=0;i<n;i++)
           {
               temp=create(temp);
           }
           break;
        case 2:
             printf("\nLinked list:\n");
             display(head);
             break;
        case 3:
            head=reverse(head);
            printf("\nReversed Linked List:\n");
            display(head);
            break;
        case 4:
            printf("Enter position:");
            scanf("%d",&pos);
            insert(head,pos);
            n++;
            break;
        case 5:
            printf("Enter position:");
            scanf("%d",&pos);
            delete(head,pos);
            n--;
            break;
        case 6:
            printf("Enter the index between 0 and %d",n-1);
            scanf("%d",&pos);
            swapp(head,pos);
            break;


    }
    printf("\nDo you want to continue:(1/0)");
    scanf("%d",&yn);
    }
}