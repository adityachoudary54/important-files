#include<iostream>
#include<algorithm>
using namespace std;
struct person
{
    string name;
    int salary;
};
bool makecompname(person a,person b)
{
    return a.name<b.name;
}
bool makecomp(person a,person b)
{
    if(a.salary>b.salary)
        return true;
    else if(a.salary==b.salary)
        return a.name<b.name;
    else
        return false;
}
int main()
{
    person a[100000];
    int n,min_sal;
    cin>>min_sal>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].salary;
        if(a[i].salary<min_sal)
        {
            n--;
            i--;
        }
    }
    sort(a,a+n,makecomp);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].salary<<endl;
    }
    return 0;
}
