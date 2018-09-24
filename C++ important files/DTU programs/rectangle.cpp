#include<iostream>
using namespace std;
class rectangle;
class s{
public:
    int per(rectangle& a);
};
class rectangle
{
    int l,b;
public:
    rectangle(int a,int s)
    {
        l=a;
        b=s;
    }
    friend area(rectangle&);
    friend int s::per(rectangle&);
};

int s::per(rectangle& a)
{
    return 2*(a.l+a.b);
}

int area(rectangle& a)
{
    return a.l*a.b;
}
int main()
{
    int m,n;
    cout<<"Enter the dimensions of rectangle:";
    cin>>m>>n;
    rectangle a(m,n);
    s q;
    cout<<"Area is:"<<area(a)<<endl;
    cout<<"Perimeter is:"<<q.per(a);
    return 0;
}
