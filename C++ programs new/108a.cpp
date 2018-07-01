#include<iostream>
#include<iomanip>
using namespace std;
struct time
{
    int hr;
    int minu;
}a1,b1;
int swapdigi(int *a);
int main()
{
    int i,temp;
    char ch;
    cin>>a1.hr>>ch>>a1.minu;
    if(a1.hr<6||(a1.hr>=10&&a1.hr<16)||(a1.hr>=20&&a1.hr<24))
    {
        temp=a1.hr;
        temp=swapdigi(&temp);
        if(temp>a1.minu)
            cout<<setfill('0')<<setw(2)<<a1.hr<<':'<<setfill('0')<<setw(2)<<temp<<endl;
        else
        {
            a1.hr=a1.hr+1;
            temp=a1.hr;
            if(a1.hr<6||(a1.hr>=10&&a1.hr<16)||(a1.hr>=20&&a1.hr<24))
                cout<<setfill('0')<<setw(2)<<a1.hr<<':'<<setfill('0')<<setw(2)<<swapdigi(&temp)<<endl;
            else if(a1.hr==6)
            {
                a1.hr=10;
                temp=a1.hr;
                cout<<setfill('0')<<setw(2)<<a1.hr<<':'<<setfill('0')<<setw(2)<<swapdigi(&temp)<<endl;
            }
            else if(a1.hr==16)
            {
                a1.hr=20;
                temp=a1.hr;
                cout<<setfill('0')<<setw(2)<<a1.hr<<':'<<setfill('0')<<setw(2)<<swapdigi(&temp)<<endl;
            }
            else if(a1.hr==24)
            {
                a1.hr=0;
                temp=a1.hr;
                cout<<setfill('0')<<setw(2)<<a1.hr<<':'<<setfill('0')<<setw(2)<<swapdigi(&temp)<<endl;
            }
        }
    }
    else
    {
        if(a1.hr<10)
        {
            a1.hr=10;
            temp=a1.hr;
            cout<<setfill('0')<<setw(2)<<a1.hr<<':'<<setfill('0')<<setw(2)<<swapdigi(&temp)<<endl;
        }
        else if(a1.hr>=16&&a1.hr<20)
        {
            a1.hr=20;
            temp=a1.hr;
            cout<<setfill('0')<<setw(2)<<a1.hr<<':'<<setfill('0')<<setw(2)<<swapdigi(&temp)<<endl;
        }
    }

}
int swapdigi(int *a)
{
    int temp;
    temp=*a/10;
    *a=(*a-(*a/10)*10)*10+temp;
    return *a;
}
