#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    float r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    float hyp=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    float ans=hyp/(2*r);
    int ans_int=ans;
    if(ans==ans_int)
    {
        cout<<ans_int;
    }
    else
        cout<<ans_int+1;
}
