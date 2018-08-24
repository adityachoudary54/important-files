#include<iostream>
using namespace std;
struct poly
{
    int coef;
    int exp;
};
void polyinput(poly p1[],int &size1)
{
    cin>>size1;
    for(int i=0;i<size1;i++)
    {
        cout<<"enter the coefficient "<<i+1<<":";
        cin>>p1[i].coef;
        cout<<"enter the exponent:";
        cin>>p1[i].exp;
    }
}
void polyoutput(poly p1[],int size1)
{
    for(int i=0;i<size1;i++)
    {
        if(i!=(size1-1))
            cout<<"("<<p1[i].coef<<")"<<"x^"<<p1[i].exp<<" + ";
        else
        {
            cout<<"("<<p1[i].coef<<")"<<"x^"<<p1[i].exp;
        }
    }
}
void polyadd(poly p1[],poly p2[],poly p3[],int size1, int size2, int &size3)
{
    int i=0,j=0,k=0;
    while(i<size1&&j<size2)
    {
        if(p1[i].exp>p2[j].exp)
        {
            p3[k].exp=p1[i].exp;
            p3[k].coef=p1[i].coef;
            i++;k++;
        }
        else if(p1[i].exp==p2[j].exp)
        {
            p3[k].exp=p1[i].exp;
            p3[k].coef=p1[i].coef+p2[j].coef;
            i++;j++;k++;
        }
        else
        {
            p3[k].exp=p2[j].exp;
            p3[k].coef=p2[j].coef;
            k++;j++;
        }
    }
    while(i<size1)
    {
        p3[k].exp=p1[i].exp;
        p3[k].coef=p1[i].coef;
        i++;k++;
    }
    while(j<size2)
    {
        p3[k].exp=p2[j].exp;
        p3[k].coef=p2[j].coef;
        j++;k++;
    }
    size3=k;
}
void multerm(poly p1[],poly p2,poly res[],int size1)
{
    for(int i=0;i<size1;i++)
    {
        res[i].exp=p2.exp+p1[i].exp;
        res[i].coef=p2.coef*p1[i].coef;
    }
}
void copypoly(poly p1[],poly p2[],int size1,int &size2)
{
    size2=size1;
    for(int i=0;i<size1;i++)
    {
        p2[i].exp=p1[i].exp;
        p2[i].coef=p1[i].coef;
    }
}
void polymult(poly p1[],poly p2[],poly p3[],int size1, int size2, int &size3)
{
    poly p4[40],p5[40];
    size3=0;
    int size4=size1,size5;
    for(int i=0;i<size2;i++)
    {
        multerm(p1,p2[i],p4,size1);
        polyadd(p3,p4,p5,size3,size4,size5);
        copypoly(p5,p3,size5,size3);
    }
}
int main()
{
    int size1,size2,size3;
    poly p1[20],p2[20],p3[20];
    polyinput(p1,size1);
    polyinput(p2,size2);
    polymult(p1,p2,p3,size1,size2,size3);
    polyoutput(p3,size3);
    return 0;
}
