#include<iostream>
using namespace std;
class personal
{
public:
    int p();
    int (personal::*x)();
};
int personal::p(){
    return 2;
}
int main()
{
    personal a;
    a.x=&personal::p;
    cout<<((a.*(a.x))());
}
