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

void insert_data(struct node *head,int newdata,int placedata)
{
    struct node *temp,*newnode;
    temp=head;
    while(temp->data!=placedata)
    {
        temp=temp->next;
        if(temp==head)
        {
            printf("Given Data not found in list\n\n");
            break;
        }
    }
    if(temp!=head)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=newdata;
        newnode->next=temp->next;
        temp->next=newnode;
    }

}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    printf("\n");
    do
    {
        printf("Address of temp = %d temp next = %d Data = %d\n",temp,temp->next,temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("Address of temp = %d temp next = %d Data = %d\n",temp,temp->next,temp->data);
}

void delete_data(struct node *head,int x)
{
    struct node *temp,*prev;
    temp=head;
    if(head->data==x)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=head->next;
    }
    else
    {

            do
            {
                prev=temp;
                temp=temp->next;
            }
            while(temp!=head && temp->data!=x);

            if(temp!=head)
            prev->next=temp->next;
            else
            printf("Data to delete is not present in linked list");
    }
}

int data_sum(struct node *head)
{
    int sum=0;
    struct node *temp;
    sum=head->data;
    temp=head->next;
    while(temp!=head)
    {
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}
