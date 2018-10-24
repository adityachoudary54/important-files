#include<iostream>
#include<unordered_map>
using namespace std;
void init(unordered_map<int,string> &a)
{
    a[1]="one";
    a[2]="two";
    a[3]="three";
    a[4]="four";
    a[5]="five";
    a[6]="six";
    a[7]="seven";
    a[8]="eight";
    a[9]="nine";
    a[0]="zero";
}

void disp(int n,unordered_map<int,string> a)
{
    if(n==0)
        return;
    disp(n/10,a);
    cout<<a[n%10]<<" ";
}

int main()
{
    unordered_map<int,string> a;
    init(a);
    int n;
    cin>>n;
    disp(n,a);
    return 0;
}
