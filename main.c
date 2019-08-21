#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linked_lists.h"
 struct node *head,*temp,*prev,*new1,*copyh;


int main()
{
    int x,sum=0,del,bd,dn,bh;
//head node is the very first node and important one in Linked List
    head=(struct node *)malloc(sizeof(struct node));
    temp=head;
    printf("Enter the data to make linked list and enter 0 to end the List");
    while(temp!=NULL)
    {
        scanf("%d",&x);
        temp=insertion(temp,x);
    }
//Display the list
    display(head);
//Summation of all data
    printf("Sum of all data is  %d\n",data_sum(head));
//Deletion of data
    printf("Enter data to delete :");
    scanf("%d",&del);

    delete_data(head,del);

    display(head);
//Insertion of data before head or After some particular data in list
    printf("\nFor inserting data before head enter 1 otherwise any number \t");
    scanf("%d",&x);


    if(x==1)
    {
        printf("Enter data to be inserted before head : ");
        scanf("%d",&bh);

        copyh=(struct node *)malloc(sizeof(struct node));
        copyh->data=head->data;
        copyh->next=head->next;
        head->data=bh;
        head->next=copyh;
    }
    else
    {
        printf("For Insertion,\nEnter the data to be inserted : ");
        scanf("%d",&dn);

        new1=(struct node *)malloc(sizeof(struct node));
        new1->data=dn;

        printf("Enter data after which new data will be inserted : ");
        scanf("%d",&bd);
        temp=head;
        while(temp!=NULL && temp->data!=bd)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
           new1=(struct node *)malloc(sizeof(struct node));
           new1->data=dn;
           new1->next=temp->next;
           temp->next=new1;
        }
    }
//displays the updated list
    display(head);
//deletion of head or other node
    printf("To delete head enter 1 otherwise any number :");
    scanf("%d",&x);
    if(x==1)
    {
        head->data=head->next->data;
        head->next=head->next->next;


    }
    else
    {
        printf("Enter data to delete :");
        scanf("%d",&del);
        delete_data(head,del);
    }

    display(head);
    return 0;
}
