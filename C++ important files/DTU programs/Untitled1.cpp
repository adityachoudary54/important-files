#include<iostream>
using namespace std;
class time
{
    int hours,minutes,seconds;
public:
    time()
    {
        hours=minutes=seconds=0;
    }
    time(int hr,int minu,int sec)
    {
        hours=minutes=seconds=0;
        seconds=sec;
        if(seconds>=60)
        {
            minutes+=(seconds/60);
            seconds=seconds%60;
        }
        minutes+=minu;
        if(minutes>=60)
        {
            hours+=(minutes/60);
            minutes=minutes%60;
        }
        hours+=hr;
    }
    time(const time &a)
    {
        hours=a.hours;
        minutes=a.minutes;
        seconds=a.seconds;
    }
    void display();
    void add(time a1,time a2);
};

void time::display()
{
    cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
}

void time::add(time a1,time a2)
{
    hours=minutes=seconds=0;
    seconds=a1.seconds+a2.seconds;
    if(seconds>=60)
    {
        minutes+=(seconds/60);
        seconds=seconds%60;
    }
    minutes+=(a1.minutes+a2.minutes);
    if(minutes>=60)
    {
        hours+=(minutes/60);
        minutes=minutes%60;
    }
    hours+=(a1.hours+a2.hours);
}

int main()
{
    time a(2,15,15),b(3,46,48),c;
    a.display();
    b.display();
    c.add(a,b);
    c.display();
    time d=c;
    d.display();
    return 0;
}
