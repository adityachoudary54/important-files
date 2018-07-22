#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char input[100];
    cin>>input;
    int i,j,k,t;
    t=strlen(input);
    for(i=0;i<t;i++)// woh position specify krne ke liye jisse substring bnega
    {
        for(j=i;j<t;j++)//initial set krne ke liye
        {
            for(k=i;k<=j;k++)//substring print krne ke liye
            {
                cout<<input[k];
            }
            cout<<endl;
        }
    }
    return 0;
}
