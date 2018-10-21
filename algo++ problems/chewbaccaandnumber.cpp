#include<iostream>
using namespace std;
int main()
{
    string a;
    int i=0;
    cin>>a;
    char b[20];
    for(i=0;i<a.size();i++)
    {
        int num=a[i]-'0';
        int inv_num=9-num;
        if(num==9&&i==0)
            b[i]=num+'0';
        else
            b[i]=min(num,inv_num)+'0';
    }
    b[i]='\0';
    cout<<b;
}
