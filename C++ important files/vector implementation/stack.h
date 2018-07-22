#ifndef stack_h
#define stack_h

#include"vectorimplementation.h"
template<typename T>// removes function overloading
class Stack
{
    Vector<T> v;
public:
    void push(T data)
    {
        v.push_back(data);
    }
    void pop()
    {
        v.pop_back();
    }
    T top() const
    {
        return v[v.size()-1];
    }
    bool isempty () const// const function dusre const ki hi baat maanega agr aisa nhin hai toh use bhaga dega.
    {
        return v.size()==0;
    }
    int size () const
    {
        return v.size();
    }
    void operator=(Stack<T> s)
    {
        while(!s.isempty())
        {
            v.push_back(s.top());
            s.pop();
        }
    }
};
#endif // stack_h
