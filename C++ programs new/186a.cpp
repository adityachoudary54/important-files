#include<iostream>
using namespace std;
int main()
{
    string a,b;
    int i,a1,b1,k,ind1,ind2;
    k=0;
    cin>>a>>b;
    a1=a.size();
    b1=b.size();
    if(a1!=b1)
        cout<<"NO";
    else
    {
        for(i=0;i<a1;i++)
        {
            if(a[i]!=b[i])
                k++;
        }
        if(k>2||k==1)
            cout<<"NO";
        else
        {
            for(i=0;i<a1;i++)
            {
                if(a[i]!=b[i])
                {
                   if(k==2)
                        ind1=i;
                   else
                        ind2=i;
                   k--;
                }
            }
            if(a[ind1]==b[ind2]&&a[ind2]==b[ind1])
                cout<<"YES";
            else
                cout<<"NO";
        }

    }
    return 0;
}
