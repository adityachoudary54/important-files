#include<iostream>
using namespace std;
void subseq(char input[],char output[],int i, int j)
{
    //base case
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    output[j]=input[i];//input wala ya toh hoga ya toh nhin hoga
    subseq(input,output,i+1,j+1);
    //excluding the ith character
    subseq(input,output,i+1,j);
}
int main()
{
    char a[]="aabc";
    char b[3];
    subseq(a,b,0,0);
}
