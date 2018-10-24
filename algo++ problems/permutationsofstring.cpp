#include<iostream>
using namespace std;
void permutations(char input[],int i)
{
    if(input[i]=='\0')
    {
        cout<<input<<endl;
        return ;
    }
    for(int k=i;input[k]!='\0';k++)
    {
        swap(input[i],input[k]);
        permutations(input,i+1);
        swap(input[i],input[k]);//Backtracking - to restore the original array
    }
}
int main()
{
    char input[]="abc";
    permutations(input,0);
    return 0;
}
