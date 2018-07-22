#include<iostream>
using namespace std;
void pi(char *a,int i)
{
    int j;
    //base case
    if(a[i]=='\0'||a[i+1]=='\0')
    {
        return ;
    }
    //rec case
    if(a[i]=='p'&&a[i+1]=='i')
    {
        for(j=0;a[j]!='\0';j++);
        for(;j>=i+2;j--)
        {
            a[j+2]=a[j];
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        pi(a,i+4);
    }
    else
    {
        pi(a,i+1);
    }

}
int main()
{
    char a[100];
    cin>>a;
    pi(a,0);
    cout<<a;
}
