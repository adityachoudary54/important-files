#include<iostream>
#include<queue>
#include<functional>
#include<cstring>
using namespace std;
class Person
{
public:
    char name[100];
    int money;
    Person()
    {

    }
    Person(char *n,int m)
    {
        strcpy(name,n);
        money=m;
    }
   /* print()
    {
        cout<<name<<" "<<money;
    }*/
};
class PersonCompare
{
public:
    bool operator()(const Person &p1,const Person &p2)
    {
        return p1.money>p2.money;//creates min heap
        //return p1.money<p2.money;//creates max heap
        //reverse of sorting case happens here
    }
};
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;//max heap
    priority_queue<int> p;//min heap
    priority_queue<Person,vector<Person>,PersonCompare> pp;
    //by default it is a max heap
    //vector<int> and greater<int> parameters are to be passed
    //when we want to get minheap.
    int a[]={7,6,5,4,3,1,2,9,110,15};
    for(int i=0;i<10;i++)
    {
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    Person p1("ABC",100);
    Person p2("Nimit",150);
    Person p3("Piyush",2);
    pp.push(p1);
    pp.push(p2);
    pp.push(p3);
    while(!pp.empty())
    {
        cout<<pp.top().name<<" "<<pp.top().money<<endl;
        pp.pop();
    }
    PersonCompare t;
    bool ans = t(p1,p2);
    cout<<ans;
    return 0;
}
