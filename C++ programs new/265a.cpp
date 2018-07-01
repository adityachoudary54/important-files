#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    string a,b;
    cin>>a>>b;
    for(i=0,j=0;i<b.size();++i)
    {
        if(b[i]==a[j])
        {
            j=j+1;
        }
    }
    cout<<j+1;
}
