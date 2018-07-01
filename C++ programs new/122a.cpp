#include<iostream>
using namespace std;
int main()
{
    int x,i,a[4],y,j,key;
    cin>>x;
    key=1;
    y=x;
    if(x%4==0||x%7==0)
    {
        cout<<"YES";
        return 0;
    }
    else
    {   i=0;
        while(y>0)
        {
            a[i]=y%10;
            y=y/10;
            i++;
        }
        for(j=0;j<i;j++)
        {
            if(a[j]!=4&&a[j]!=7)
            {
                key=0;
            }
        }
        if(!key)
        {
            if(x%47==0||x%74==0)
            {
                key=1;
            }
        }
    }
    if(key)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
