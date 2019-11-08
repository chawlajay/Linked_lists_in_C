#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count;
//Doubly linked list structure for Student information
struct student{

int roll_no;
char name[50];
float cgpa;
struct student *prev;
struct student *next;
};

// Create the Doubly Linked List function
struct student *createList()
{
 struct student *head;
 int r;
 float f;
 char n[50],enter;
 head=(struct student *)malloc(sizeof(struct student));
    printf("Enter the roll no :");
    scanf("%d",&r);
    fflush(stdin);
    printf("Enter the name :");
    getchar();
    gets(n);

    printf("Enter CGPA :");
    scanf("%f",&f);

    head->roll_no=r;
    strcpy(head->name,n);
    head->cgpa=f;
    head->next=NULL;
    head->prev=NULL;
    count++;
    return head;
}
struct student *insertion(struct student *head)
{
    struct student *temp,*new_node,*bef;
    int r,i,p;
    char n[50];
    float f;

    new_node=(struct student *)malloc(sizeof(struct student));
    printf("Enter the roll no :");
    scanf("%d",&r);
    fflush(stdin);
    printf("Enter the name :");
    getchar();
    gets(n);

    printf("Enter CGPA :");
    scanf("%f",&f);

    new_node->roll_no=r;
    strcpy(new_node->name,n);
    new_node->cgpa=f;
    new_node->next=NULL;
    new_node->prev=NULL;
    printf("Where do you want to insert the new node ? Enter number accordingly :\n1.At front of the list\n2.At end of the list\n3. In middle of list\n");
    scanf("%d",&i);

    switch(i)
    {
        case 1: new_node->next=head;
                head->prev=new_node;
                head=new_node;
                count++;
                break;
        case 2 :
                  temp=head;
                  while(temp->next!=NULL)
                    temp=temp->next;

                  temp->next=new_node;
                  new_node->prev=temp;
                  count++;
                break;
        case 3 : printf("Enter the position ,where to insert the new node\n");
                 scanf("%d",&p);
                 if(p>0)
                 {
                   //  printf("%d",count);
                         if(p==1)
                         {
                             new_node->next=head;
                             head->prev=new_node;
                             head=new_node;
                         }
                         else if(p>count)
                         {

                             temp=head;
                             while(temp->next!=NULL)
                             temp=temp->next;

                             temp->next=new_node;
                             new_node->prev=temp;
                         }
                         else
                         {
                             int j=1;
                             temp=head;
                             while(j!=p-1)
                             {
                                temp=temp->next;
                                j++;
                             }

                             new_node->next=temp->next;
                             new_node->prev=temp;
                             temp->next->prev=new_node;
                             temp->next=new_node;
                         }
                         count++;
                 }
                 else
                 {
                     printf("Invalid position");
                 }
                 break;

    }

    return head;
}

struct student *deletion(struct student *head)
{
 int i,j,k;
 struct student *temp,*bef;
 printf("How do you want to delete the student record? \nEnter a number accordingly\n1.By entering a Position\n2. By entering a student Roll no.\n");
 scanf("%d",&i);
 switch(i)
 {
     case 1: printf("Enter the position for deletion");
             scanf("%d",&j);
             if(j>count || j<1)
             {
                 printf("Invalid Position");
             }
             else
             {
                 temp=head;
                 k=1;
                 if(j!=1)
                 {
                     while(k!=j)
                     {
                         bef=temp;
                        temp=temp->next;
                        k++;
                     }
                     bef->next=temp->next;
                     temp->next->prev=bef;
                 }
                 else
                 {
                     printf("Student of Roll No. %d and Name %s with CGPA %f is deleted from record",temp->roll_no,temp->name,temp->cgpa);
                  head=head->next;
                  head->prev=NULL;
                 }
                 count--;
             }
             break;
      case 2: printf("Enter the roll no for deletion");
             scanf("%d",&j);
             if(head!=NULL)
             {
                     temp=head;
                     k=head->roll_no;
                     if(j!=k)
                     {
                         while(k!=j && temp!=NULL)
                         {
                             bef=temp;
                             temp=temp->next;
                             if(temp!=NULL)
                             k=temp->roll_no;
                         }

                         if(temp!=NULL)
                         {
                             printf("Student of Roll No. %d and Name %s with CGPA %f is deleted from record",temp->roll_no,temp->name,temp->cgpa);
                             bef->next=temp->next;
                             temp->next->prev=bef;
                             count--;
                         }
                         else
                         {
                              printf("Student with given Roll No. %d is Not found in the record",j);
                         }
                     }
                     else
                     {
                         printf("Student of Roll No. %d and Name %s with CGPA %f is deleted from record",head->roll_no,head->name,head->cgpa);
                         head=head->next;
                         head->prev=NULL;
                         count--;
                     }
             }
             else
             {
                  printf("Student with given Roll No. %d is Not found in the record",j);
             }
             break;

 }
 return head;
}

void search(struct student *head)
{
    int i,j,k;
    char n[50];
    float p,f;
    struct student *temp;
    printf("How do you want to search the student record? \nEnter a number accordingly\n1. By entering a student Roll no.\n2.By entering the name of student(case sensitive)\n3. By Using CGPA ");
 scanf("%d",&i);
 switch(i)
 {

      case 1: printf("Enter the roll no to search");
             scanf("%d",&j);
             temp=head;
             k=head->roll_no;
             while(k!=j && temp!=NULL)
             {
                 temp=temp->next;
                 if(temp!=NULL)
                 k=temp->roll_no;
             }

             if(temp!=NULL)
             {
                 printf("Student of Roll No. %d is present in the record by Name of %s and with CGPA %f\n",temp->roll_no,temp->name,temp->cgpa);

             }
             else
             {
                  printf("Student with given Roll No. is Not found in the record\n");
             }
             break;
      case 2: printf("Enter the name of student to search :\n");
              char n[50],stu_name[50];
             getchar();
   gets(n);
             temp=head;

             while( temp!=NULL)
             {
                 if(!strcmp(temp->name,n))
                    break;

                 temp=temp->next;

             }

             if(temp!=NULL)
             {
                 printf("Student of Roll No. %d and Name %s is found in the record with CGPA %f",temp->roll_no,temp->name,temp->cgpa);

             }
             else
             {
                  printf("Student with given Name is Not found in the record");
             }
             break;
    case 3:  printf("Enter the CGPA to search");
             scanf("%f",&f);
             temp=head;
             p=head->cgpa;
             while(p!=f && temp!=NULL)
             {
                 temp=temp->next;
                 if(temp!=NULL)
                 p=temp->cgpa;
             }

             if(temp!=NULL)
             {
                 printf("Student of Roll No. %d by Name of %s and with CGPA %f is present in the record\n",temp->roll_no,temp->name,temp->cgpa);

             }
             else
             {
                  printf("Student with given CGPA is Not found in the record\n");
             }
             break;

      default :printf("Invalid choice");
                break;
 }

}

void display(struct student *head)
{
    struct student *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("Student Name : %s\nStudent Roll No. : %d\nStudent's CGPA : %f\n",temp->name,temp->roll_no,temp->cgpa);
        temp=temp->next;
    }
}


int main()
{
    struct student *head,*temp;
    int i,j;

    printf("Enter any number accordingly.\n1. To Create Doubly Linked List\n2. To insert a node\n3. To delete a node\n4. To search a node\n5. To display all the nodes\n6. To exit from program");
    scanf("%d",&i);

    while(i!=6)
    {

    switch(i)
    {
        case 1 : head=createList();
                 break;
        case 2 : head=insertion(head);
                 break;
        case 3 : head=deletion(head);
                 break;
        case 4 : search(head);
                 break;
        case 5 : display(head);
                 break;

    }

    printf("\nEnter a number accordingly.\n1. To Create Doubly Linked List\n2. To insert a node\n3. To delete a node\n4. To search a node\n5. To display all the nodes\n6. To exit from program");
    scanf("%d",&i);

    }
    return 0;
}
