#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<string> ss;
void permutstr(char input[],int i)
{
    if(input[i]=='\0')
    {
        cout<<input<<endl;
        string s(input);
        //ss.insert(s);
        return ;
    }
    for(int j=i;input[j]!='\0';j++)
    {   //rec case
        swap(input[i],input[j]);
        permutstr(input,i+1);
        //backtrack restore original array
        swap(input[i],input[j]);
    }
}
int main()
{
    char input[100];
    cin>>input;
    permutstr(input,0);
    /*for(auto it=ss.begin();it!=ss.end();it++)
        cout<<*it<<endl;*/
    return 0;
}
