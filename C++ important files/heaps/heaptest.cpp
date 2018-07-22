#include<iostream>
#include "heap.h"
using namespace std;
int main()
{
    Heap h;//default arrangement mein minheap sbse pehle hai
    //jisko change kia ja skta hai
    //heap is also known as priority queue
    //can be used to sort object;
    int a[]={7,6,5,4,3,1,2,9,110,15};
    for(int i=0;i<10;i++)
    {
        h.push(a[i]);
    }
    while(!h.isempty())
    {
        cout<<h.getTop()<<" ";
        h.pop();
    }
    return 0;
}
