#include<iostream>
#define size 8
using namespace std;
struct Queue
{
    int A[100];
    int front,rear;
};
void insertq(Queue &q,int x)
{
    //cout<<q.rear<<" "<<q.front<<endl;
    if((q.rear+1)%size==q.front)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        q.A[q.rear]=x;
        q.rear=(q.rear+1)%size;
    }
}
int deleteq(Queue &q)
{
    if(q.front==q.rear)
    {
        return -1;
    }
    int x=q.A[q.front];
    q.front=(q.front+1)%size;
    return x;
}
void displayq(Queue q)
{
    int x=deleteq(q);
    while(x!=-1)
    {
        cout<<x<<" ";
        x=deleteq(q);
    }
    cout<<endl;
}
int main()
{
    Queue a;
    a.front=a.rear=0;
    char choice;
    do
    {
        int x;
        cout<<"Enter the operation you want to perform:"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case '1':cin>>x;
                     insertq(a,x);
            break;
            case '2':deleteq(a);
            break;
            case '3':displayq(a);
            break;
            case '4':choice='n';
            break;
        }
    }while(choice!='n');
    //display(a);
    return 0;
}
