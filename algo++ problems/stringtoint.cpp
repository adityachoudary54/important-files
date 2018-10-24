#include<iostream>
using namespace std;
int stringtoint(char a[],int len)
{
    if(len==0)
    {
        return 0;
    }
    return a[len-1]-'0'+10*stringtoint(a,len-1);
}
int main()
{
    char a[]="1234567";
    cout<<stringtoint(a,7);
    return 0;
}
