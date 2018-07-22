#include<vector>
using namespace std;
class Heap
{
    bool minheap;
    vector<int> v;
    bool compare(int a,int b)
    {
        if(minheap)
        {
            return a<b;
        }
        else
        {
            return a>b;
        }
    }
    void heapify(int i)
    {
        int min_index=i;
        int left=2*i;
        int right=left+1;
        int lastindex=v.size()-1;
        if(left<=lastindex&&compare(v[left],v[min_index]))
        {
            min_index=left;
        }
        if(right<=lastindex&&compare(v[right],v[min_index]))
        {
            min_index=right;
        }
        if(min_index!=i)
        {
            swap(v[i],v[min_index]);
            heapify(min_index);
        }
    }
public:
    Heap(bool minH=true)
    {
        minheap=minH;
        v.push_back(-1);
    }
    void push(int d)
    {
        v.push_back(d);
        int index=v.size()-1;
        while(index>1&&compare(v[index],v[index/2]))
        {
            swap(v[index],v[index/2]);
            index=index>>1;
        }
    }
    int getTop()
    {
        if(v.size()>1)
        {
            return v[1];
        }
    }
    void pop()
    {
        int index=v.size()-1;
        swap(v[1],v[index]);
        v.pop_back();
        heapify(1);
    }
    int size()
    {
        return v.size()-1;
    }
    bool isempty()
    {
        return v.size()==1;
    }
};
