#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    for(int i=0;i<10;i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }

    // doubly ended queue
    //push_front push_back pop_front pop_back

    return 0;
}
