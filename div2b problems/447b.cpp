#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map <char,int> ump;
    int a[26],k,sum=0,maxi=-1;
    char index;
    string input;
    cin>>input;
    cin>>k;
    for(int i=0;i<26;i++)
        cin>>a[i];
    for(int i=0;i<26;i++)
    {
        char ch='a'+i;
        ump[ch]=a[i];
        if(a[i]>maxi)
        {
            maxi=a[i];
            index=ch;
        }
    }
    int i;
    for(i=0;i<input.size();i++)
        sum+=ump[input[i]]*(i+1);
    for(int j=i+1;j<=(i+k);j++)
    {
        sum+=maxi*j;
    }
    cout<<sum;
}
