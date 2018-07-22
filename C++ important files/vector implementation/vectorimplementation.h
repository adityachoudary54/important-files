#ifndef VECTOR_H//checks whether the given header file is present in a file or not.
#define VECTOR_H
// template<class T> can also be used. further research needed.
template<typename T>
class Vector
{
    T *arr;
    int cs;
    int ms;
public:
//functions which dont change value in members of a class are known as const functions
    Vector(int ds=4)
    {
        arr=new T [ds];
        cs=0;
        ms=ds;
    }
    void push_back(const T d)//here we use the word const since the given value isnt changing in the function
    {
        if(cs==ms)
        {
            //expand the vector
            T *oldarr=arr;
            arr=new T[2*ms];
            ms=ms<<1;
            for(int i=0;i<cs;i++)
            {
                arr[i]=oldarr[i];
            }
            delete [] oldarr;//command for deleting an array
            oldarr=NULL;
        }
        arr[cs]=d;
        cs++;
    }
    void pop_back()
    {
        if(cs>0)
        {
            cs--;
        }
    }
    int size () const// this line is used so that function is not able to modify the contents of the function.
    {
        return cs;
    }
    int capacity () const
    {
        return ms;
    }
    T operator[](int i) const
    {
        return arr[i];//we have direct access to this object so we can directly use.
    }
};
#endif
