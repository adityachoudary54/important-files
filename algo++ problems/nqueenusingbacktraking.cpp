#include<iostream>
using namespace std;
int helper(int a[][100],int row,int col,int n)
{
        ///Row mein queen to nahi h
    for(int i=0;i<n;i++){
        if(a[row][i]==1){
            return false;
        }
    }
    ///Col mein queen to nahi h
    for(int i=0;i<n;i++){
        if(a[i][col]==1){
            return false;
        }
    }
    /// Diagonals
    ///Top Left
    int i=row,j=col;
    while(i>=0&&j>=0){
        if(a[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    ///Top Right
    i=row,j=col;
    while(i<n && j>=0){
        if(a[i][j]==1){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int cnt=0;
void disp(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<" "<<a[i][j]<<"  ";
        if(i!=n-1)
        cout<<endl<<endl;
        else
            cout<<endl;
    }
    for(int j=0;j<n;j++)
        cout<<"----";
    cout<<endl;
}
int nqueen(int a[][100],int j,int n)
{
    if(j>=n)
    {
        //disp(a,n);
        cnt++;
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        if(helper(a,i,j,n))
        {
            a[i][j]=1;
            if(nqueen(a,j+1,n))
            {
                return 1;
            }
            a[i][j]=0;
        }
    }
    return 0;
}
int main()
{
    int a[100][100]={0};
    int n;
    cin>>n;
    nqueen(a,0,n);
    cout<<cnt;
    return 0;
}
