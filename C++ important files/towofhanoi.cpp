#include<iostream>
using namespace std;
void toh(int n,char s,char h,char d)
{
    if(n<=0)
    return;
    else
    {
        toh(n-1,s,d,h);//move (n-1) disks from source with the help of destination to the helper
        cout<<"Move "<<n<<"th disk to "<<d<<endl;//move nth disk to the destination
        toh(n-1,h,s,d);//using source as helper move disks from helper to destination
    }
}
int steps(int n)
{
    if(n==0)
        return 0;
    else
        return 2*steps(n-1)+1;
}
int main()
{
    int n;
    cin>>n;
    cout<<steps(n)<<endl;
    toh(n,'A','B','C');
}
