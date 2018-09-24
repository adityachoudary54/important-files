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
        cout<<"Empty queue"<<endl;
        return -1;
    }
    int x=q.A[q.front];
    q.front=(q.front+1)%size;
    return x;
}
void displayq(Queue q)
{
    cout<<q.front<<" "<<q.rear<<endl;
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
    insertq(a,8);
    insertq(a,3);
    insertq(a,4);
    insertq(a,5);
    insertq(a,6);
    insertq(a,7);
    insertq(a,8);
    insertq(a,9);
    //insertq(a,9);
    displayq(a);
    deleteq(a);
    deleteq(a);
    displayq(a);
    deleteq(a);deleteq(a);deleteq(a);deleteq(a);displayq(a);deleteq(a);deleteq(a);deleteq(a);
    cout<<a.front<<a.rear<<endl;
    return 0;
}
