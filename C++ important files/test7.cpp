#include<iostream>
using namespace std;
int main()
{
    int pos_moves[][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<2;j++)
            cout<<pos_moves[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
