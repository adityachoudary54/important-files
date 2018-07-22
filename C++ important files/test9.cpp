#include<iostream>
using namespace std;
int main()
{
    int i,j;
    i=0;
   /* while(i>5)
    {
        cout<<i;
        i++;
    }*/
    i=0;
    do
    {
        cout<<"Chose from anyone"<<endl;
        cout<<"1-> exit()"<<endl;
        cout<<"2-> display()"<<endl;
        cin>>i;
        if(i==2)
            cout<<i<<endl;
    }while(i!=1);
    return 0;
}
