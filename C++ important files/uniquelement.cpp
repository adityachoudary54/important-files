#include<iostream>
using namespace std;
int main()
{
    int n,a[100],ans;
    cin>>n;
    ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans=ans^a[i];
    }
    // this solution makes use of the fact that any no. which repeats even no. of times gets cancelled when using xor operator
    cout<<ans;
    return 0;
}
