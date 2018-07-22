#include<iostream>
using namespace std;
int main()
{
    int a,c,n;
    char ch;
    string no_part,dus_1,dus_2,input[100],start,endi;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>input[i];
    for(int i=0;i<n;i++)
    {
        if(input[i].size()<=10)
        {
            cout<<input[i]<<endl;
        }
        else
        {
            c='0';
            a=input[i].size()-2;
            if(a<10)
                no_part=a+c;
            else
            {
                dus_1=a/10+c;
                dus_2=(a%10)+c;
                no_part=dus_1+dus_2;
            }
            input[i]=input[i][0]+no_part+input[i][a+1];
            cout<<input[i]<<endl;
        }
    }
    return 0;
}
