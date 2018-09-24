#include<iostream>
using namespace std;
struct node
{
    int value;
    struct node* next;
};

void addattail(node* &head,int d)
{
    node* ptr=new node;
    ptr->value=d;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=ptr;
}

void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->value<<"->";
        head=head->next;
    }
    cout<<endl;
}

void rearrange(node* &head)
{
    node *p,*q;
    int temp;
    if(head==NULL||head->next==NULL)
        return;
    p=head;
    q=head->next;
    while(q!=NULL)
    {
        temp=p->value;
        p->value=q->value;
        q->value=temp;
        p=q->next;
        if(p!=NULL)
            q=p->next;
        else
            q=NULL;
    }
}
int main()
{
    node* head;
    head=NULL;
    for(int i=1;i<=7;i++)
    {
        addattail(head,i);
    }
    display(head);
    rearrange(head);
    display(head);
    return 0;
}
