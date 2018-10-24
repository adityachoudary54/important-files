#include<iostream>
using namespace std;
int toh(int n,char source,char destination,char helper)
{
    if(n==0)
        return 0;
    int a=toh(n-1,source,helper,destination);
    cout<<"Moving "<<n<<"th disk from "<<source<<" to "<<destination<<endl;
    int b=toh(n-1,helper,destination,source);
    return a+b+1;
}
int main()
{
    int n;
    cin>>n;
    cout<<toh(n,'A','C','B');
    return 0;
}
