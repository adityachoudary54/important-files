#include<iostream>
#include<set>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
    int n,l;
    set<int> a;
    cin>>n>>l;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.insert(x);
    }
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    double d=0;
    auto t=a.end();
    t--;
    for(auto it=a.begin();it!=t;it++)
    {
        int x=*it;
        int y=*(++it);
        it--;
        if((y-x)>d)
            d=y-x;
        //cout<<x<<" "<<y<<" ";
    }
  /*  cout<<d;
    cout<<endl;*/
    auto u=a.begin(),v=a.end();
    int upper_lim=l-*t;
    int lower_lim=*u-0;
    //cout<<upper_lim<<" "<<lower_lim<<" "<<*u<<" "<<*t<<endl;
    double rad1=d/2;
    double rad2=(double)(max(upper_lim,lower_lim));
    if(rad1>rad2)
        cout<<rad1;
    else
        cout<<rad2;
}
