#include<iostream>
#include<stack>
using namespace std;
void pushAtbottom(stack<int> &s,int a)
{
    if(s.empty())
    {
        s.push(a);
        return;
    }
    // otherwise
    int t=s.top();
    s.pop();
    pushAtbottom(s,a);
    s.push(t);
}
void reverse(stack<int> &s)
{
    //base case
    if(s.size()==0)
        return;
    //normal case
    int top=s.top();
    s.pop();
    reverse(s);
    pushAtbottom(s,top);// this function is used to add the top number to bottom
}
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main()
{
    stack<int> s;
    for(int i=1;i<10;i++)
        s.push(i);
    print(s);
    cout<<endl;
    reverse(s);
    print(s);
    return 0;
}
