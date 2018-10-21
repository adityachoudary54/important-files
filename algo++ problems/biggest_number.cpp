#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
int main()
{
    string a[100];
    int n,t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,myCompare);
        for(int i=0;i<n;i++)
            cout<<a[i];
        cout<<endl;
    }

}
