#include<iostream>
using namespace std;
void printstr(char *input,char *output,int i=0,int j=0)
{
    //base case
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //rec case two options
    //take 1 char at a time
    char ch;
    int digi=input[i]-'0';
    ch=64+digi;
    output[j]=ch;
    printstr(input,output,i+1,j+1);
    //take 2 char at a time
    if(input[i+1]!='\0')
    {
        int secdigi=input[i+1]-'0';
        int no=10*digi+secdigi;
        if(no<=26)
        {
            ch=64+no;
            output[j]=ch;
            printstr(input,output,i+2,j+1);
        }

    }

}
int main()
{
    char a[100],b[100];
    cin>>a;
    printstr(a,b,0,0);
}
