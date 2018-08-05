#include<iostream>
using namespace std;
int main()
{
    int n,t;
    char a[50];
    cin>>n;
    cin>>t;
    for(int i=0;i<n;i++)
        cin>>a[i];
    a[n]='\0';
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<n-1;)
        {
            if(a[j]=='B'&&a[j+1]=='G')
            {
                swap(a[j],a[j+1]);
                j+=2;
            }
            else
            j++;
        }
        //cout<<a<<endl;
    }
    cout<<a;
}
