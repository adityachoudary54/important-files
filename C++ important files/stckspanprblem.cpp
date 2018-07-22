#include<iostream>
#include<stack>
using namespace std;
int stk_day(stack<int> &stk,int a[])
{
    int val=stk.top();
    stk.pop();
    while(!stk.empty())
    {
        if(a[val]<a[stk.top()])
            return stk.top();
        else
            stk.pop();
    }
    stk.push(val);
    return 0;
}
int main()
{
    int a[]={1,5,17,2,6,3,9,4};
    //int a[]={100, 80, 60, 70, 60, 75, 85};
    int i,num,val,k;
    num=((char*)(&a+1)-(char*)(&a))/4;
    stack<int> stk;
    //stk.push(0);
    cout<<num;
    for(i=0;i<=num;i++)
    {
        if(stk.empty())//stack khali hai toh usmein push kro
            stk.push(i);
        else if(a[stk.top()]<a[i])// agr top se chota element milgya toh top wale ka output do
        {
            val=stk.top();
            stk.pop();
            if(stk.empty())
            {
                cout<<"Stock span of day "<<a[val]<<" is:"<<val+1<<endl;
                stk.push(i);
            }
            else
            {
                //stk.push(val);
                //k=stk_day(stk,a);
                cout<<"Stock span of day "<<a[val]<<" is:"<<val-stk.top()<<endl;
                stk.push(i);
            }

        }
        else//agr top se chota ni mila toh top ko ya toh update kro ya phir naye bde ko push krdo
        {
            val=stk.top();
            stk.pop();
            if(stk.empty())
            {
                cout<<"Stock span of day "<<a[val]<<" is:"<<val+1<<endl;
                stk.push(val);
                stk.push(i);
            }
            else
            {
                stk.push(val);
                k=stk_day(stk,a);
                cout<<"Stock span of day "<<a[val]<<" is:"<<val-k<<endl;
                stk.push(i);
            }

        }
    }
    return 0;

}
