#include<iostream>
#include<unordered_map>
using namespace std;
void init(unordered_map<int,string> &u)
{
    u[0]=" ";
    u[1]=" ";
    u[2]="ABC";
    u[3]="DEF";
    u[4]="GHI";
    u[5]="JKL";
    u[6]="MNO";
    u[7]="PQRS";
    u[8]="TUV";
    u[9]="WXYZ";

}
void keypad(char input[],char output[],unordered_map<int,string> ump,int i,int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    string x=ump[input[i]-'0'];
    for(int k=0;k<x.size();k++)
    {
        output[j]=x[k];
        keypad(input,output,ump,i+1,j+1);
    }
}
int main()
{
    unordered_map<int,string> ump;
    char input[]="666";
    char output[100];
    init(ump);
    keypad(input,output,ump,0,0);
    return 0;
}
