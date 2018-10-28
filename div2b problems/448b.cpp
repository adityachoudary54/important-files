#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<char,int> ump1,ump2;
    string a,b;
    cin>>a>>b;
    if(a.size()==b.size())
    {
        for(int i=0;i<26;i++)
        {
            char ch='a'+i;
            ump1[ch]=0;
        }
        for(int i=0;i<a.size();i++)
        {
            ump1[a[i]]+=1;
            ump1[b[i]]-=1;
        }
        for(int i=0;i<a.size();i++)
        {
            if(ump1[a[i]]!=0)
            {
                cout<<"need tree"<<endl;
                return 0;
            }
        }
        cout<<"array"<<endl;
    }
    else
    {
        for(int i=0;i<26;i++)
        {
            char ch='a'+i;
            ump1[ch]=0;
        }
        for(int i=0;i<a.size();i++)
        {
            ump1[a[i]]+=1;
        }
        for(int i=0;i<b.size();i++)
        {
            if(ump1[b[i]]==0)
            {
                cout<<"need tree"<<endl;
                return 0;
            }
            ump1[b[i]]--;
        }
        int i,j;
        for(i=0,j=0;i<a.size()&&j<b.size();)
        {
            if(a[i]!=b[j])
            {
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        if(j==b.size())
            cout<<"automaton"<<endl;
        else
            cout<<"both"<<endl;
    }
    return 0;
}
