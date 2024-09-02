//A simple linked list demonstration

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* create(struct node *temp)
{
    temp->next=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d", &temp->next->data);
    temp->next->next=NULL;
    return temp->next;
}
int main()
{
  struct node* head = (struct node*)malloc(sizeof(struct node));
  if(head==NULL)
  printf("Memory allocation failed");
  else{
    printf("Head data:");
    scanf("%d",&head->data);
  }
  struct node *t=head;
  for(int i=0;i<4;i++)
  {
    t=create(t);
  }
  struct node* temp=head;
  do
  {
    printf("\nData:%d",temp->data);
    temp=temp->next;
  }while(temp != NULL);
  return 0;
}