//#ifndef QUEUE_H
//#define QUEUE_H
// QUEUE_H

template<typename T>
class Queue
{
    int f,r;
    int ms;
    int cs;
    T *arr;
public:
    Queue(int s=5)
    {
        f=0;
        ms=s;
        r=ms-1;
        arr=new T[ms];
        cs=0;
    }
    void push_data(T data)
    {
        if(cs<ms)
        {
            r=(r+1)%ms;
            arr[r]=data;
            cs++;
        }
    }
    void pop()
    {
        if(cs>0)
         f=(f+1)%ms;
         cs--;
    }
    bool isEmpty()
    {
        return cs==0;
    }
    bool isFull() const
    {
        return cs=ms;
    }
    T front()
    {
        return arr[f];
    }
    int size() const
    {
        return cs;
    }
    ~Queue()
    {
        if(arr!=NULL)
            delete [] arr;
    }
};
//#endif // QUEUE_H
