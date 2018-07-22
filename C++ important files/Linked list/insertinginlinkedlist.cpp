#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    //Init list
    node(int d):data(d),next(NULL){}
   /* ~node()
    {  // cout<<"Deleting node "<<data<<endl;
        //if(next!=NULL)
        //    delete next;
    }*/
};



void addatfront(node* &head,int d)//head is taken by reference sincce we need to modify it.
{
    //insert at front
    node *t=new node(d);
  //  t->data=d;
  //either remove the init condition and use the above line or do as given.
    t->next=head;
    head=t;
}
void addattail(node* &head,int d)//can be done just like addatfront using a tail pointer or in this manner
{
    node* t=new node(d);
    if(head==NULL)
    {
        head=t;
        return;
    }
    node *temp;
    for(temp=head;temp->next!=NULL;temp=temp->next);
    temp->next=t;
}
node* takeinput()
{
    node* head=NULL;
    int d;
    cin>>d;
    while(d!=-1)
    {
            addattail(head,d);
            cin>>d;
    }
    return head;
}
void addinmid(node* &head,int d,int pos)
{
    node* t=new node(d);
    int i;
    i=1;
    node *temp;
  //  cout<<"sahi";
    if(pos==1)
    {
        t->next=head;
        head=t;
        //cout<<"sahi";
        return;
    }
    for(temp=head;i<pos-1;temp=temp->next,i++);
   // cout<<temp->data;
    t->next=temp->next;
    temp->next=t;
}
void deletefront(node* &head)
{
    node* temp;
    temp=head->next;
    delete head;
    head=temp;
}
void printele(node* head)
{
    node* temp;
    for(temp=head;temp!=NULL;temp=temp->next)
        cout<<temp->data<<"->";
}
int length(node* head)
{
    int i;
    i=0;
    for(;head!=NULL;head=head->next,i++);
    return i;
}
node* findelerecur(node* head,int x)
{
   // static int i;
    if(head==NULL)
        return NULL;
    if(head->data==x)
        return head;
//    i++;
    findelerecur(head->next,x);
}
node* findmid(node* head)
{
    node* temp;
    temp=head;
    int i,j;
    i=0;
    for(;head!=NULL;head=head->next,i++);
    //cout<<i;
    for(j=0;j<(i-1)/2;temp=temp->next,j++);
   // cout<<j;
    return temp;
}
void bubsort(node* &head)
{
    node *cur,*prev,*nexti;
    int n=length(head);
    int i=0;
    for(i=0;i<n-1;i++)
    {
        prev=NULL;
        cur=head;
        while(cur->next!=NULL)
        {
            if(cur->data>(cur->next->data))
            {
                nexti=cur->next;
                //for adjusting the nodes
                cur->next=nexti->next;
                nexti->next=cur;
                //for handling value in head and prev
                if(prev==NULL)
                {
                    head=nexti;
                    prev=head;//prev=nexti is also correct;
                }
                else
                {
                    prev->next=nexti;
                    prev=prev->next;//prev=nexti is also correct
                }
            }
            else
            {
                nexti=cur->next;
                prev=cur;
                cur=nexti;
            }
        }
    }
}
node* ithelementformend(node* head,int pos)//imp concept remember!!!!!!!!
{
    node *aage,*piche;
    aage=piche=head;
    for(int i=1;aage!=NULL;i++,aage=aage->next)
    {
        if(i>pos)
            piche=piche->next;
    }
    return piche;
}

ostream& operator<<(ostream &os,node *a)//here we use actual cout by the use of reference and we return cout in order for proper working
{
   /* while(a)
    {
        os<<a->data<<" ";//cout<<a->data<<" "; is also valid
        a=a->next;
    }*/
    printele(a);
    return os;
}

node* mergelist(node* head1,node* head2)
{
     node *head,*nextnode;
     head=NULL;
     while((head1!=NULL)&&(head2!=NULL))
     {
         if((head1->data)<(head2->data))
         {
             if(head==NULL)
             {
                 head=head1;
                 nextnode=head1->next;
                 head1->next=NULL;
                 head1=nextnode;
                 nextnode=head;
                 //cout<<head->data<<" "<<nextnode->data<<endl;
             }
             else
             {
                 nextnode->next=head1;
                 head1=nextnode->next->next;
                 nextnode=nextnode->next;
                 nextnode->next=NULL;
                // cout<<nextnode->data<<" "<<head1->data<<endl;
             }
         }
         else
         {
                if(head==NULL)
                {
                    head=head2;
                    nextnode=head2->next;
                    head2->next=NULL;
                    head2=nextnode;
                    nextnode=head;
                }
                else
                {
                    nextnode->next=head2;
                    head2=nextnode->next->next;
                    nextnode=nextnode->next;
                    nextnode->next=NULL;
                   // cout<<nextnode->data<<" "<<head2->data<<endl;
                }
         }
        /* if(head1==NULL)
            cout<<"sahi hai";
         printele(head);
         cout<<endl;*/

    }
    //cout<<"glt hai";
    if(head1!=NULL)
    {   if(head==NULL)
        {
            head=head1;
            nextnode=head1->next;
            head1->next=NULL;
            head1=nextnode;
            nextnode=head;
        }
        while(head1)
        {
            nextnode->next=head1;
            head1=nextnode->next->next;
            nextnode=nextnode->next;
            nextnode->next=NULL;
        }
    }
    if(head==NULL)
    {
        head=head2;
        nextnode=head2->next;
        head2->next=NULL;
        head2=nextnode;
        nextnode=head;
    }
    while(head2)
    {
        nextnode->next=head2;
        head2=nextnode->next->next;
        nextnode=nextnode->next;
        nextnode->next=NULL;
    }

    return head;
}
node* smartmergelist(node* head1,node* head2)
{
    node* head;
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1->data<=head2->data)
    {
        head=head1;
        head->next=smartmergelist(head1->next,head2);
    }
    else
    {
        head=head2;
        head->next=smartmergelist(head1,head2->next);
    }
    //cout<<head<<"merged"<<endl;
    return head;
}

node* mergesort(node* head)
{
    node* right;
    node* left;
    node* mid;
    if(head==NULL)
        return head;
    if(head->next==NULL)
        return head;
    mid=right=findmid(head);
    //cout<<right<<endl;
    right=right->next;
    //cout<<right<<endl;
    left=head;
    mid->next=NULL;
  //  cout<<left<<" "<<right<<" strt"<<endl;
    left=mergesort(left);//this is imp since after sorting the left it changes so we have to keep track of that left
                        //since the connections created in a function are local to itself.
  //  cout<<left<<" "<<right<<" step1"<<endl;
    right=mergesort(right);
   // cout<<left<<" "<<right<<" step2"<<endl;
    head=smartmergelist(left,right);
   // cout<<left<<" "<<right<<" "<<" endi"<<endl;
    return head;
}
istream& operator>>(istream &is,node* &a)
{
    a=takeinput();
    return is;
}

node* reverseitr(node* &head)
{
    node* cur;
    node *nextnode,*prev;
    cur=head;
    prev=NULL;
    while(cur!=NULL)
    {
        nextnode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextnode;
    }
    head=prev;
    return head;
}
node* reverserec(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node *chotahead;
    //,*temp;
    //cout<<head<<endl;
    //chotahead=temp=reverserec(head->next);
    //cout<<temp->next;
  /*  while((temp->next)!=NULL)
    {
        //cout<<"sahi"<<endl;
        temp=temp->next;
    }*/
    //temp->next=head;
    //cout<<head<<"step1"<<endl;
    chotahead=reverserec(head->next);//chota head here is the required head pointer of the reversed list.
   // cout<<head<<"step2"<<endl;
    (head->next)->next=head;// 2 ke next mein 1 daal diya in 1 |<-2<-3<-4|
    head->next=NULL;//same in both approaches
    return chotahead;
}

void kreverse(node* &head,int k)
{
    node *ctr,*str,*itr,*str2;
    int i;
    ctr=head;
    if(k<=1)
        return ;
    while(ctr!=NULL)
    {

        for(i=0,itr=ctr;i<k;i++)
        {

            itr=itr->next;
            if(itr==NULL)
            {
                ctr=NULL;
                break;
            }
            if(ctr==head&&i==k-2)
                break;
        }

        if(ctr==head)
        {
            head=NULL;
            str=itr->next;
            itr->next=NULL;
            head=reverseitr(ctr);
            for(i=0,itr=head;i<k-1;i++)
                itr=itr->next;
            itr->next=str;
            ctr=itr;
        }
        else if(ctr!=NULL)
        {
            str=itr->next;
            str2=ctr->next;
            ctr->next=NULL;
            itr->next=NULL;
            ctr->next=reverseitr(str2);
          //  cout<<head<<endl;
            for(i=0,itr=ctr;i<k;i++)
                itr=itr->next;
            itr->next=str;
            ctr=itr;
        }
    }
}
void altnodedelete(node* head)
{
    node *cur,*nexti,*str;
   //
    cur=head;
    if(cur->next==NULL)
    {
        return ;
    }
    for(cur=head;cur!=NULL;)
    {
        nexti=cur->next->next;
        if(nexti==NULL)
        {
            str=cur->next;
            cur->next=NULL;
          //  cout<<str<<endl;
            delete str;
            break;
        }
        cur->next->next=NULL;
        str=cur->next;
        cur->next=nexti;
        delete str;
        cur=nexti;
        if(cur->next==NULL)
            cur=NULL;
    }
}

node* add_two_numbers(node* head1,node* head2)
{
    node *head;
    int t;
    head=NULL;
    head1=reverserec(head1);
    head2=reverserec(head2);
    while(head1&&head2)
    {  // cout<<1<<endl;
        if((head1->data+head2->data)>=10)
        {
            t=head1->data+head2->data;
            addatfront(head,t-10);
            deletefront(head1);
            deletefront(head2);
            head1->data+=1;
          //  cout<<head1<<endl;
          //  cout<<head2<<endl;
        }
        else
        {
            addatfront(head,head1->data+head2->data);
            deletefront(head1);
            deletefront(head2);
        }
    }
  //  cout<<head<<endl;
    if(head1==NULL)
    {
        while(head2)
        {
            if(head2->data>=10)
            {
                addatfront(head,head2->data-10);
                deletefront(head2);
                head2->data+=1;
            }
            else
            {
                addatfront(head,head2->data);
                deletefront(head2);
            }
        }
    }
    else
    {
        while(head1)
        {
            if(head1->data>=10)
            {
                addatfront(head,head1->data-10);
                deletefront(head1);
                head1->data+=1;
            }
            else
            {
                addatfront(head,head1->data);
                deletefront(head1);
            }
        }
    }
    return head;
}
int main()
{
   // node* head1=takeinput();
   // node* head2=takeinput();
   // node* head=takeinput();
    //addinmid(head,782,5);
  //  cout<<head1<<endl<<head2<<endl;
   /* head=mergesort(head);
    cout<<head<<endl;
    delete head;
    cout<<head;*/
    node *a,*b;
    cin>>a>>b;
    a=add_two_numbers(a,b);
    cout<<a;
    //printele(head);
    //bubsort(head);
    //cout<<endl;
   // cout<<ithelementformend(head,3)->data;
   /* cout<<length(head)<<endl;
    cout<<findmid(head)->data;
    cout<<findelerecur(head,1)->data;*/
    //deletefornt(head);
   // printele(head);
    return 0;
}
