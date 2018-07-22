#include<iostream>
using namespace std;
struct keypad
{
    char key;
    string a;
}k;
void key_conv(keypad &k)
{
    if(k.key=='1')
        k.a="1";
    else if(k.key=='2')
        k.a="abc";
    else if(k.key=='3')
        k.a="def";
    else if(k.key=='4')
        k.a="ghi";
    else if(k.key=='5')
        k.a="jkl";
    else if(k.key=='6')
        k.a="mno";
    else if(k.key=='7')
        k.a="pqrs";
    else if(k.key=='8')
        k.a="tuv";
    else if(k.key=='9')
        k.a="wxyz";
    else if(k.key=='*')
        k.a="*";
    else if(k.key=='0')
        k.a="0";
    else if(k.key=='#')
        k.a="#";
}
void phone(char input[],int i,char output[],int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
    }
    keypad k;
    k.key=input[i];
    key_conv(k);
    //cout<<k.key<<" "<<k.a<<endl;
    for(int m=0;m<k.a.size();m++)
    {
        output[j]=k.a[m];
        phone(input,i+1,output,j+1);
    }
}
int main()
{
    char input[100];
    char output[100];
    cin>>input;
    phone(input,0,output,0);
    return 0;
}
