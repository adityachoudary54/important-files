#include<iostream>
#include<cstring>
using namespace std;
char* mystrtok(char* input,char delim)
{
    static char *output,*store;
    static int pos;
    int i,j;
    if(input!=NULL)
    {
        pos=0;
        for(i=pos;input[i]!='\0';i++)
            if(input[i]==delim)
                break;
        output=new char[strlen(input)+1];
        for(j=pos;j<i;j++)
        {
            output[j]=input[j];
        }
        output[j]='\0';
        pos=i+1;
        store=input;
    }
    else
    {
        int t=strlen(store);
        for(i=pos;(store[i]!=delim)&&(store[i]!='\0');i++);
        //cout<<i<<endl;
        if(i==t)
            delim='\0';
        if(pos>=t)
        {
            output=NULL;
        }
        else
        {
            i=0;
            //cout<<i<<"mid";
            for(j=pos;store[j]!=delim;j++,i++)
            {
                output[i]=store[j];
            }
            output[i]='\0';
            pos=j+1;
        }
    }
    return output;
}
int main()
{
    char input[]="Hey, this is something new.";
    char* token=mystrtok(input,' ');
    while(token!=NULL)
    {
        cout<<token<<endl;
        token=mystrtok(NULL,' ');
    }
    return 0;
}
