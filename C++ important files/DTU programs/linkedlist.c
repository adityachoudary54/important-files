#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
void addatbegin(struct node** q,int num)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if(*q==NULL)
    {
        *q=temp;
    }
    else
    {
        temp->next=*q;
        *q=temp;
    }
}
void addatend(struct node** q,int num)
{
    struct node *temp,*r;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if(*q==NULL)
    {
        *q=temp;
    }
    else
    {
        r=*q;
        while(r->next!=NULL)
            r=r->next;
        r->next=temp;
    }
}

void deleteelement(struct node** q,int num)
{
    struct node* temp=*q,*prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            if(prev!=NULL)
            {
                prev->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
            else
            {
                *q=temp->next;
                temp->next=NULL;
                free(temp);
            }
            return ;
        }
        prev=temp;
        temp=temp->next;
    }
}
void display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d->",q->data);
        q=q->next;
    }
    printf("\n");
}

void reverseitr(struct node** head)
{
    struct node* cur;
    struct node *nextnode,*prev;
    cur=*head;
    prev=NULL;
    while(cur!=NULL)
    {
        nextnode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextnode;
    }
    *head=prev;
}

int length(struct node* head)
{
    if(head==NULL)
        return 0;
    return 1+length(head->next);
}

void intersection(struct node* head,struct node* head2)
{
    int l1,l2,i;
    i=0;
    l1=length(head);
    l2=length(head2);
    if((l1-l2)==0)
    {
        while(head!=head2)
        {
            head=head->next;
            head2=head2->next;
        }
        printf("%d",head->data);
    }
    else if(l1>l2)
    {
        while(i<(l1-l2))
        {
            head=head->next;
            i++;
        }
        while(head!=head2)
        {
            head=head->next;
            head2=head2->next;
        }
        printf("%d",head->data);
    }
    else
    {
        while(i<(l2-l1))
        {
            head2=head2->next;
            i++;
        }
        while(head!=head2)
        {
            head=head->next;
            head2=head2->next;
        }
        printf("%d",head->data);
    }
}

int main()
{
    struct node* head,* head2;
    head=NULL;
    head2=NULL;
    addatbegin(&head,2);
    addatbegin(&head,8);
    addatbegin(&head,6);
    addatbegin(&head,9);
    addatend(&head,1);
    addatend(&head,2);
    addatend(&head,3);
    addatend(&head,4);
   // deleteelement(&head,4);
    display(head);
    reverseitr(&head);
    display(head);
    addatend(&head2,1);
    addatend(&head2,2);
    addatend(&head2,3);
    addatend(&head2,4);
    display(head2);
    struct node* temp,*temp2;
    temp=head2;
    temp2=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        temp2=temp2->next;
        //printf("1");
    }
    printf("%d\n",temp2->data);
    temp->next=temp2;
    display(head2);
    //printf("%d",length(head));
    intersection(head,head2);
}
