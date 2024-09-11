//Bank management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct account{
    char name[25];
    int accno;
    int bal;
    int pass;
}acc;

void createacc(FILE *ptr,FILE *ptr1)
{
    acc s;
    int accno;
    printf("Enter name:");
    scanf("%s",s.name);
    printf("Enter acc no:");
    scanf("%d",&accno);
    rewind (ptr);
    while(fscanf(ptr,"%s %d %d",s.name,&s.accno,&s.bal)!=EOF)                //Checking wheteher the account exists or not
    {
        if(s.accno==accno)
          printf("Account already Exists.Without this knowledge why are you existing??");
          return;
     }
    printf("Enter initial deposit:");
    scanf("%d",&s.bal);
    printf("Enter password:");
    scanf("%d",&s.pass);
    fprintf(ptr,"%s %d %d\n",s.name,accno,s.bal);
    fprintf(ptr1,"%d %d\n",accno,s.pass);
}
void checkbal(FILE *ptr,FILE *ptr1)
{
   acc s;
   rewind(ptr1);
   rewind(ptr);
   int accno,pass;
   printf("Enter account no:");
   scanf("%d",&s.accno);
   while(fscanf(ptr1,"%d %d",&accno,&s.pass)!=EOF)                               //Checking for the existence of account in pass.txt
   {
        if(accno==s.accno){
            printf("Enter password:");
            scanf("%d",&pass);
            if(s.pass==pass)
            {
                while(fscanf(ptr,"%s %d %d",s.name,&s.accno,&s.bal)!=EOF)          //finding the account in acc.txt if the password is correct        
                {
                    if(s.accno==accno)
                      break;
                }
                 printf("\nAccount Holder:%s\n",s.name);
                 printf("Balance:%d",s.bal);
            }
            else
                printf("Wrong password!!try again lol\n");
           return;
        }
   }
   printf("\nAccount not exists.Why are wasting my time??");
}

void deposit(FILE *ptr)
{
    acc s;
    char c;
    rewind(ptr);
    int accno,amt;
    printf("Enter accno:");
    scanf("%d",&accno);
     while(fscanf(ptr,"%s %d %d",s.name,&s.accno,&s.bal)!=EOF)                //Checking wheteher the account exists or not
    {
        if(s.accno==accno)
        {
            printf("Enter the amount to be deposited:");
            scanf("%d",&amt);
            s.bal+=amt;     
            break;
     }
    }
     fseek(ptr,-18,SEEK_CUR);
            fprintf(ptr,"%d",s.bal);
            printf("%d",s.bal);

}

int main()
{
    int ch,end;
    FILE *ptr = fopen("acc.txt","a+");
    FILE *ptr1 = fopen("pass.txt","a+");
    if(ptr==NULL)
    {
        printf("Error in opening file");
        exit(-1);
    }
    
    while(end)
    {
    printf("1.Create account\n2.Check balance\n3.Deposit Money\n4.Withdraw Money\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            createacc(ptr,ptr1);
            break;
        }
        case 2:
        {
            checkbal(ptr,ptr1);
            break;
        }
        case 3:
        {
            deposit(ptr);
            break;
        }
    }
    printf("\nDo you want to continue?(1/0)");
    scanf("%d",&end);
    }
    fclose(ptr);
    fclose(ptr1);
    return 0;
}