struct node
    {
        int data;
        struct node *next;
    };

struct node* insertion(struct node *temp,int x)
{
      temp->data=x;
        if(x==0)
            temp->next=NULL;
        else
            temp->next=(struct node *)malloc(sizeof(struct node));

        temp=temp->next;

        return temp;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("Address of temp = %d temp next = %d Data = %d\n",temp,temp->next,temp->data);
        temp=temp->next;
    }
}

int data_sum(struct node *head)
{
    struct node *temp;
    temp=head;
    int sum=0;
    while(temp!=NULL)
    {
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}

void delete_data(struct node *head,int x)
{
    struct node *temp,*prev;
    temp=head;

    while(temp!=NULL && temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp!=NULL)
    prev->next=temp->next;
    else
    printf("Data to delete is not present in linked list");

}

