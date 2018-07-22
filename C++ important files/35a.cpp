#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int index,a,b;
    cin>>index;
    for(int i=0;i<3;i++)
    {
        cin>>a>>b;
        if(a==index)
            index=b;
        else if(b==index)
            index=a;
    }
    cout<<index;
    return 0;
}
