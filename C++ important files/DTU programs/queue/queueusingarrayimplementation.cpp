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
    if((q.rear+1)%size==q.front)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        if(q.rear==-1)
        {
            q.front=0;
            q.rear=0;
            q.A[q.rear]=x;
        }
        else
        {
            q.rear=(q.rear+1)%size;
            q.A[q.rear]=x;
        }
    }
}
int deleteq(Queue &q)
{
    int x;
    if(q.front==-1)
    {
        cout<<"empty queue"<<endl;
        return -1;
    }
    if(q.front==q.rear)
    {
        //cout<<"Empty queue"<<endl;
        x=q.A[q.front];
        q.front=q.rear=-1;
        return x;
    }
    x=q.A[q.front];
    q.front=(q.front+1)%size;
    return x;
}
void displayq(Queue q)
{
    while(q.front!=-1)
        cout<<deleteq(q)<<endl;
}
int main()
{
    Queue a;
    a.front=a.rear=-1;
    insertq(a,2);
    insertq(a,3);
    insertq(a,4);
    insertq(a,5);
    insertq(a,6);
    insertq(a,7);
    insertq(a,8);
    insertq(a,9);
    insertq(a,9);
    displayq(a);
    deleteq(a);
    deleteq(a);
    displayq(a);
    deleteq(a);deleteq(a);deleteq(a);deleteq(a);displayq(a);deleteq(a);deleteq(a);deleteq(a);
    cout<<a.front<<a.rear<<endl;
    return 0;
}
