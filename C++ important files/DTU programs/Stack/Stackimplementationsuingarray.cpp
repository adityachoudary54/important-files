#include<iostream>
#define stack_size 5
using namespace std;
struct Stack
{
    int A[100];
    int top;
};
int pop(Stack &a)
{
    if(a.top==-1)
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    int x=a.A[a.top];
    a.top--;
    return x;
}
void push(Stack &a,int x)
{
    if(a.top==stack_size-1)
        cout<<"Stack is full"<<endl;
    else
    {
        a.top++;
        a.A[a.top]=x;
    }
}
void display(Stack a)
{
    while(a.top!=-1)
    {
        cout<<pop(a)<<endl;
    }
}
int main()
{
    Stack a;
    a.top=-1;
    char choice;
    do
    {
        int x;
        cout<<"Enter the operation you want to perform:"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case '1':cin>>x;
                     push(a,x);
            break;
            case '2':pop(a);
            break;
            case '3':display(a);
            break;
            case '4':choice='n';
            break;
        }
    }while(choice!='n');
    //display(a);
    return 0;
}
