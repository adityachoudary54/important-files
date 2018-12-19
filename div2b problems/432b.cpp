#include<iostream>
using namespace std;
struct games
{
    int home,away;
};
int main()
{
    games input[100000],output[100000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input[i].home>>input[i].away;
        output[i].home=output[i].away=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j)
            {
                if(input[i].home!=input[j].away)
                {
                    output[i].home++;
                    output[j].away++;
                }
                else
                {
                    output[i].home++;
                    output[j].home++;
                }
                if(input[j].home!=input[i].away)
                {
                    output[j].home++;
                    output[i].away++;
                }
                else
                {
                    output[j].home++;
                    output[i].home++;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<output[i].home<<" "<<output[i].away<<endl;
    return 0;
}
