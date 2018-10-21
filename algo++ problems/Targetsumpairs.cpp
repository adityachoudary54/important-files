#include<iostream>
#include<unordered_map>
using namespace std;
void method1(int input[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(input[i]+input[j]==target)
            {
                if(input[i]<input[j])
                    cout<<input[i]<<" and "<<input[j]<<endl;
                else
                    cout<<input[j]<<" and "<<input[i]<<endl;
            }
        }
    }
}

void method2(int input[],int n,int target)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[input[i]]=target-input[i];
    }
    for(int i=0;i<n;i++)
    {
        if(m[target-input[i]]==input[i]&&input[i]<target-input[i])
            cout<<input[i]<<" and "<<target-input[i]<<endl;
    }
}

int main()
{
    int input[1000],n,target;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    cin>>target;
    method2(input,n,target);
    return 0;
}
