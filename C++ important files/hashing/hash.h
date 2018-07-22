#include<cstring>
using namespace std;
template<typename T>
class node
{
    public:
    string key;
    T value;
    node* next;

    node(string k,T v)
    {
        key=k;
        value=v;
        next=NULL;
    }
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};

template<typename T>
class hashtable
{
    node<T>** buckets;
    int cs;
    int ts;
    int hasfn(string key)
    {
        int L=key.length();
        int ans=0;
        int p=1;
        for(int i=0;i<L;i++)
        {
            ans=ans+key[L-i-1]*p;
            p=p*37;
            p%=ts;
            ans%=ts;
        }
        return ans;
    }
    void rehash()
    {
        node<T>** oldBuckets=buckets;
        int oldts=ts;
        ts=ts<<1;
        buckets=new node<T>*[ts];
        //init with null
        for(int i=0;i<oldts;i++)
            buckets[i]=NULL;
        cs=0;
        //iterate over old table
        for(int i=0;i<oldts;i++)
        {
            node<T>* temp=oldBuckets[i];
            if(temp!=NULL)
            {
                while(temp!=NULL)
                {
                    insert(temp->key,temp->value);
                    temp=temp->next;
                }
                delete oldBuckets[i];
            }
        }
        delete [] oldBuckets;
    }
public:
    hashtable(int ds=7)
    {
        cs=0;
        ts=ds;
        buckets=new node<T>*[ts];
        for(int i=0;i<ts;i++)
        {
            buckets[i]=NULL;
        }
    }
    void insert(string key,T value)
    {
        int i=hasfn(key);
        node<T>* n=new node<T>(key,value);
        n->next=buckets[i];
        buckets[i]=n;
        cs++;
        float lf=(float)cs/ts;
        if(lf>0.7)
        {
            rehash();
        }
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            cout<<"Bucket "<<i<<"  ->";
            node<T> *temp=buckets[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<" ->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    //pointer is used to check if a value is present or not
    T* search(string key)
    {
        int i=hasfn(key);
        node<T> *temp=buckets[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp=temp->next;
        }
        return NULL;
    }

    T& operator[](string key)// by reference return krne se actual node mein changes kr skte hain
    {
        T* temp=search(key);
        if(temp==NULL)
        {
            T newBox;
            insert(key,newBox);
            return *search(key);
        }
        return *temp;
    }

    void remove(string key)
    {
        int i=hasfn(key);
        node<T> *temp=buckets[i];
        node<T> *del,*next,*prev;
        prev=NULL;
        while(temp!=NULL)
        {
            next=temp->next;
            if(temp->key==key&&prev==NULL)
            {
                buckets[i]=next;
                temp->next=NULL;
                delete temp;
                break;
            }
            else if(temp->key==key)
            {
                prev->next=next;
                temp->next=NULL;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
};
