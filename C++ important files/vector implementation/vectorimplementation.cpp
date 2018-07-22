class Vector
{
    int *arr;
    int cs;
    int ms;
public:
//functions which dont change value in members of a class are known as const functions
    Vector(int ds=4)
    {
        arr=new int [s];
        cs=0;
        ms=ds;
    }
    void push_back(const int d)//here we use the word const since the given value isnt changing in the function
    {
        if(cs==ms)
        {
            //expand the vector
            int *oldarr=arr;
            arr=new int[2*ms];
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
    int size const()
    {
        return cs;
    }
    int capacity const()
    {
        return ms;
    }
    int operator[](int i)
    {
        return arr[i];//we have direct access to this object so we can directly use.
    }
};
