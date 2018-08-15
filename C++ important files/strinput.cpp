#include<iostream>
using namespace std;
int main()
{
    string a[1000];
    int i,t,n;
    char ch,ch1;
    t=0;
    cin>>n;
    cin.get();//this will only work.
    for(i=0;i<n;i++)
    {
        getline(cin,a[i],'\n');
        //cout<<a[i];
    }
    for(i=0;i<n;i++)
        if(t<a[i].size())
            t=a[i].size();
    cout<<t;
    ch='a';
    ch1='a';
    char c='a';
    ch=ch+ch1+c;// jb 256 se badi value ho toh val%256 hojata hai convert krne ke liye
    cout<<int(ch);
  //  cout<<(16>>1);
    return 0;
}
