#include<iostream>
using namespace std;
struct chord
{
    int val;
    string note;
}a[3],b[6][3];
int store=0;
void permut(chord a[],int n,int j)
{
    if(j==n-1)
    {
        for(int i=0;i<n;i++)
        {
            (b[store][i]).note=a[i].note;
            b[store][i].val=a[i].val;
            if((b[store][i].val<b[store][i-1].val)&&i!=0)
                b[store][i].val=b[store][i].val+12;
            //cout<<b[store][i].note<<" ";
        }
        //cout<<endl;
        //cout<<b[store][0].note;
        store++;
        return;
    }
    for(int i=j;i<n;i++)
    {
        swap(a[i],a[j]);
        permut(a,n,j+1);
        swap(a[i],a[j]);
    }
}
void val(chord *a)
{
    if(a->note=="C")
            a->val=1;
        else if(a->note=="C#")
            a->val=2;
        else if(a->note=="D")
            a->val=3;
        else if(a->note=="D#")
            a->val=4;
        else if(a->note=="E")
            a->val=5;
        else if(a->note=="F")
            a->val=6;
        else if(a->note=="F#")
            a->val=7;
        else if(a->note=="G")
            a->val=8;
        else if(a->note=="G#")
            a->val=9;
        else if(a->note=="A")
            a->val=10;
        else if(a->note=="B")
            a->val=11;
        else if(a->note=="H")
            a->val=12;
}
int main()
{
   // string b;
    int i,j;
    for(i=0;i<3;i++)
    {
        if(i!=2)
            getline(cin,a[i].note,' ');
        else
            cin>>a[i].note;
    }
    for(i=0;i<3;i++)
    {
        val(&a[i]);
    }

    permut(a,3,0);
    for(i=0;i<store;i++)
    {
        for(j=0;j<3;j++)
        {
            if((b[i][1].val-b[i][0].val==4)&&(b[i][2].val-b[i][1].val==3))
            {
                cout<<"major";
                return 0;
            }
            else if((b[i][1].val-b[i][0].val==3)&&(b[i][2].val-b[i][1].val==4))
            {
                cout<<"minor";
                return 0;
            }
            //cout<<b[i][j].val<<" ";
        }
       // cout<<endl;
    }
    cout<<"strange";
    return 0;
}
