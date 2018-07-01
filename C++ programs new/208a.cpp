#include<iostream>
using namespace std;
int main()
{
    string a;
    char b[200];
    int i,j,k;
    k=0;
    cin>>a;
    for(i=0,j=0;i<a.size();i++)
    {
        if(a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B'&&j==0)
        {
            i=i+2;
        }
        else if(j==0)
        {
            b[j]=a[i];
            j++;
            k=0;
        }
        else if(a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B'&&k==0)
        {
            i=i+2;
            b[j]=' ';
            j++;
            k++;
        }
        else if(a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B')
        {
            i=i+2;
        }
        else
        {
            b[j]=a[i];
            j++;
            k=0;
        }
    }
    if(b[j-1]==' ')
        b[j-1]='\0';
    else
        b[j]='\0';
    cout<<b;
}
