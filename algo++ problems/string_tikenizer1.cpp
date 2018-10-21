#include<iostream>
#include<cstring>
using namespace std;
char* mystrtok(char str[],char delim)
{
    static char* input=NULL;
    if(str!=NULL)
    {
        input=str;
    }
    //cout<<input<<endl;
    if(input==NULL)
    {
        return NULL;
    }
    char* output=new char[strlen(input)+1];//+1 is for '\0'
    //Return a word as dynamically allocated word array from my function
    //Read the word from input and i will store in output and just return the word till deleminator
    int i=0;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]!=delim)
        {
            //copy char into output array
            output[i]=input[i];
        }
        else
        {
            //you are now at delim
            output[i]='\0';
            input=input+i+1;
            return output;
        }
    }
    //Return the last word if no delimnator
    input=NULL;
    output[i]='\0';
    return output;
}
int main()
{
    char str[]="Hi, i am learning about strings in, C++";
    char *ptr;
    ptr=mystrtok(str,',');
    while(ptr!=NULL)
    {
        cout<<ptr<<endl;
        ptr=mystrtok(NULL,',');
    }
    return 0;
}
