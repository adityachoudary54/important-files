#include<fstream>
using namespace std;
int main()
{
    int a[100],n,i,c1,c2;
    string b;
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs>>n>>b;
    for(i=1;i<=n/2;i++)
    {
        if(b[i-1]=='R')
        {
            ofs<<n/2+i<<" "<<i<<endl;
        }
        else
        {
            ofs<<i<<" "<<n/2+i<<endl;
        }
    }
}
