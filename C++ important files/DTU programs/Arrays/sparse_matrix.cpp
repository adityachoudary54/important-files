#include<iostream>
using namespace std;
struct sparse_matrix
{
    int row;
    int col;
    int val;
};
void sparsemat_output(sparse_matrix b[])
{
    int k=1;
    for(int i=0;i<b[0].row;i++)
    {
        for(int j=0;j<b[0].col;j++)
        {
            if(i==b[k].row&&j==b[k].col)
            {
                cout<<b[k].val<<" ";
                k++;
            }
            else
            {
                cout<<0<<" ";
            }
        }
        if(i!=b[0].row-1)
        cout<<endl;
    }
}
void sparsemat_input(sparse_matrix b[],int m,int n)
{
    int cnt2=0;
    b[0].row=m;
    b[0].col=n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            if(x!=0)
            {
                cnt2++;
                b[cnt2].row=i;
                b[cnt2].col=j;
                b[cnt2].val=x;
            }
        }
    }
    b[0].val=cnt2;
    //cout<<b[0].val<<endl;
}
void sparsemat_sum(sparse_matrix a[],sparse_matrix b[],sparse_matrix sum[])
{
    int i=1,j=1,k=1;
    //cout<<a[0].val<<" "<<b[0].val;
    while(i<=a[0].val&&j<=b[0].val)
    {
        if((a[i].row==b[j].row)&&(a[i].col==b[j].col))
        {
            sum[k].row=a[i].row;
            sum[k].col=a[i].col;
            sum[k].val=a[i].val+b[j].val;
            i++;j++;k++;
            //cout<<1<<" ";
        }
        else if((a[i].row<b[j].row)||((a[i].row==b[j].row)&&(a[i].col<b[j].col)))
        {
            sum[k].row=a[i].row;
            sum[k].col=a[i].col;
            sum[k].val=a[i].val;
            k++;
            i++;
            //cout<<2<<" ";
        }
        else
        {
            sum[k].row=b[j].row;
            sum[k].col=b[j].col;
            sum[k].val=b[j].val;
            k++;
            j++;
            //cout<<3<<" ";
        }
    }
    while(i<=a[0].val)
    {
        sum[k].row=a[i].row;
        sum[k].col=a[i].col;
        sum[k].val=a[i].val;
        k++;i++;
    }
    while(j<=b[0].val)
    {
        sum[k].row=a[j].row;
        sum[k].col=a[j].col;
        sum[k].val=a[j].val;
        k++;j++;
    }
    sum[0].row=a[0].row;
    sum[0].col=a[0].col;
    sum[0].val=k-1;
}
void sparsemat_mul(sparse_matrix a[100],sparse_matrix b[100],sparse_matrix mul[100])
{

}
int main()
{
    int m,n;
    sparse_matrix a[100],b[100],sum[100];
    cin>>m>>n;
    sparsemat_input(a,m,n);
    cin>>m>>n;
    sparsemat_input(b,m,n);
    /*for(int i=0;i<=a[0].val;i++)
    {
        cout<<a[i].row<<" "<<a[i].col<<" "<<a[i].val<<endl;
    }
    for(int i=0;i<=a[0].val;i++)
    {
        cout<<b[i].row<<" "<<b[i].col<<" "<<b[i].val<<endl;
    }*/
    sparsemat_sum(a,b,sum);
    sparsemat_output(sum);
    return 0;
}
