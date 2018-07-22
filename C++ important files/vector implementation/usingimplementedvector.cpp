#include<iostream>
#include"Vectorimplementation.h"
using namespace std;
int main()
{
    Vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i*i);
    for(int i=0;i<10;i++)
        cout<<v[i]<<" ";
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
  /*  v.push_back("aditya");
    cout<<v[0];*/
    return 0;
}
