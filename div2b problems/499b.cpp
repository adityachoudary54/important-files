#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string,string> ump;
    int n,m;
    string lec[3000];
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        string a,b;
        cin>>a>>b;
        ump[a]=b;
    }
    for(int i=0;i<n;i++)
        cin>>lec[i];
    for(int i=0;i<n;i++)
    {
        if((ump[lec[i]]).size()>=lec[i].size())
            cout<<lec[i]<<" ";
        else
            cout<<ump[lec[i]]<<" ";
    }
}
