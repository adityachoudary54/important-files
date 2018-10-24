#include<iostream>
using namespace std;
void subsequence(char input[],char output[],int i,int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    output[j]=input[i];
   // cout<<output[j];
    subsequence(input,output,i+1,j+1);
    subsequence(input,output,i+1,j);
}
int main()
{
    char input[]="Adi";
    char output[100];
    subsequence(input,output,0,0);
    return 0;
}
