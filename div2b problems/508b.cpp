#include<iostream>
using namespace std;
int main()
{
    int i=0,data=-1,index=-1;
    char a[100000];
    char ch='a';
    cin>>ch;
    while(ch!='\n')
    {
        a[i]=ch;
        cin.get(ch);
        i++;
    }
    a[i]='\0';
    //cout<<a;
    for(int j=0;a[j]!='\0';j++)
    {
        if(a[j]%2==0)
        {
            if(data=-1)
            {
                data=a[j];
                index=j;
                if(a[j]<a[i-1])
                {
                    //swap(a[j],a[i-1]);
                    break;
                }
            }
            else if(a[j]<a[i-1])
            {
                data=a[j];
                index=j;
                break;
            }
            else
            {
                data=a[j];
                index=i;
            }
        }
    }
    if(index!=-1)
    {
        swap(a[index],a[i-1]);
        cout<<a;
    }
    else
        cout<<-1;
    return 0;
}
