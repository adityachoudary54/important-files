#include<iostream>
#include"stack.h"
#include"vectorimplementation.h"
#include<cstring>
using namespace std;
class book{
public:
    int price;
    char name[20];
    book(){}//this line is neccessary beacause without it object of stack of book type wouldnt be created.
    book(int p,char *n)
    {
        price=p;
        strcpy(name,n);
    }
    void print()
    {
        cout<<price<<endl;
        cout<<name<<endl;
    }
    friend ostream& operator<<(ostream& os,book &b)
    {
        b.print();
        return os;
    }
};
int main()
{
    Stack<int> s;
    s.push(8);
    s.push(4);
    s.push(2);
   // reverse_stk(s);
    while(!s.isempty())
    {
        cout<<s.top()<<endl;
        s.pop();

    }
    Stack<book> sb;
    book b1(100,"C++");
    book b2(200,"java");
    book b3(300,"python");
    sb.push(b1);
    sb.push(b2);
    sb.push(b3);
    while(!sb.isempty())
    {
        book tp=sb.top();
        cout<<tp;
        sb.pop();

    }
    return 0;
}

























