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

struct node* recreverse(struct node* head)
{
    if(head->next==NULL||head==NULL)
        return head;
    struct node* temp=recreverse(head->next);
    struct node* cur=head;
    (cur->next)->next=cur;
    cur->next=NULL;
    return temp;
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
        printf("%d\n",head->data);
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
        printf("%d\n",head->data);
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
        printf("%d\n",head->data);
    }
}

void midelement(struct node* head)
{
    struct node* fast=head->next;
    for(;fast!=NULL&&fast->next!=NULL;head=head->next,fast=fast->next->next);
    printf("%d\n",head->data);
}

struct node* mergelistdec(struct node* head1,struct node* head2)
{
    struct node* res=NULL;
    struct node* ptr=NULL;
    struct node* temp=NULL;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            ptr=head1->next;
            head1->next=res;
            res=head1;
            head1=ptr;
        }
        else
        {
            ptr=head2->next;
            head2->next=res;
            res=head2;
            head2=ptr;
        }
    }
    if(head1!=NULL)
    {
        ptr=head1;
        while(ptr!=NULL)
        {
            ptr=head1->next;
            head1->next=res;
            res=head1;
            head1=ptr;
        }
        return res;
    }
    else
    {
        ptr=head2;
        while(ptr!=NULL)
        {
            ptr=head2->next;
            head2->next=res;
            res=head2;
            head1=ptr;
        }
        return res;
    }
}
int main()
{
    struct node* head,* head1,*head2,*temp1,*temp2;
    int ch,num,num1,num2,i;
    char cho;
    head=NULL;
    head2=NULL;
    head1=NULL;
    printf("Enter the operation that u want to perform->\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. delete matching element\n");
    printf("4. Reverse the linked list(iterative)\n");
    printf("5. Reverse the linked list(recursive)\n");
    printf("6. Length of the string\n");
    printf("7. Intersection of the linked list\n");
    printf("8. Display the linked list \n");
    printf("9. Display middle element\n");
    printf("10. exit()\n");
//    addatbegin(&head1,8);
//    addatbegin(&head1,6);
//    addatbegin(&head1,4);
//    addatbegin(&head1,2);
//    //display(head1);
//    addatbegin(&head2,7);
//    addatbegin(&head2,5);
//    addatbegin(&head2,3);
//    addatbegin(&head2,1);
//    //display(head2);
//    head=mergelistdec(head1,head2);
//    display(head);
    do
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:scanf("%d",&num);
                addatbegin(&head,num);
                break;
            case 2:scanf("%d",&num);
                addatend(&head,num);
                break;
            case 3:scanf("%d",&num);
                deleteelement(&head,num);
                break;
            case 4:reverseitr(&head);
                break;
            case 5:head=recreverse(head);
                break;
            case 6:printf("%d\n",length(head));
                break;
            case 8:display(head);
                break;
            case 7:scanf("%d",&num1);
                scanf("%d",&num2);
                for(i=0;i<num1;i++)
                        addatend(&head1,i);
                for(i=0;i<num2;i++)
                        addatend(&head2,i);
                temp1=head1;
                for(i=0;i<(num1-1)/2;i++)
                    temp1=temp1->next;
                temp2=head2;
                while(temp2->next!=NULL)
                    temp2=temp2->next;
                temp2->next=temp1;
                printf("Contents of list from head1 are:");
                display(head1);
                printf("Contents of list from head2 are:");
                display(head2);
                printf("Intersection point of the above lists is :");
                intersection(head1,head2);
                break;

            case 9:midelement(head);
                break;
            case 10:break;
            default:ch=10;
        }
    }while(ch!=10);
    return 0;
}

