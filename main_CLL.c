#include <stdio.h>
#include <stdlib.h>
#include "CLL.h"
int main()
{
    printf("Welcome TO the Circular Linked Lists :\n");
    int i,j,n,k;
    struct node *head,*temp,*last;
    printf("Enter number\n0. to create\n1. to insert\n2. to display full linked list (head to head)\n3.to delete\n4.to find sum\n-1 to Exit\n\n");
    scanf("%d",&i);
    while(i!=-1)
    {

     switch(i)
     {
       case 0 : head=(struct node *)malloc(sizeof(struct node));
            temp=(struct node *)malloc(sizeof(struct node));

            head->next=temp;
            printf("Enter your Data to Create a Circular Linked List and enter Zero(0) to Stop inserting Data\n");
            while(temp!=NULL)
            {

               scanf("%d",&n);
               temp->data=n;
               last=temp;
               temp=insertion(temp,n);

            }
            last->next=head->next;
            break;
       case 1: printf("First ,Enter the new data to insert and then enter the data after which you want this new data :\n");
               scanf("%d%d",&j,&k);
              // temp=(struct node *)malloc(sizeof(struct node));
               insert_data(head->next,j,k);
               break;
       case 2: display((head->next));
               break;

       case 3: printf("Enter the data to delete : ");
               scanf("%d",&k);
               delete_data(head->next,k);
               break;
       case 4 :printf("The sum of data from head to end is %d .\n\n",data_sum(head->next));
               break;

       default : printf("We will See\n\n");
       break;
     }
     printf("Enter number\n0. to create\n1. to insert\n2. to display full linked list\n3.to delete\n4.to find sum\n-1 to Exit\n\n");
    scanf("%d",&i);

    }
    return 0;
}
