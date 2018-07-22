#include<iostream>
#include<math.h>
using namespace std;
void printarr(int a[][9],int num)
{
    int i,j;
    int t;
    t=sqrt(num);
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            cout<<a[i][j]<<" ";
            if((j+1)%t==0&&j!=num-1)
                cout<<"* ";
        }
        cout<<endl;
        if((i+1)%t==0&&i!=num-1)
                cout<<"*********************"<<endl;
    }

}

// checker wil check whether a number can be inserted at a certain position or not
bool checker(int z[][9],int m,int n,int num,int ins_num)
{
    if(z[m][n]!=0)
        return false;
    else
    {
        int i,j;
        //searching in row and column
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(z[i][n]==ins_num||z[m][j]==ins_num)
                {
                    //cout<<"glt1";
                    return false;
                }

            }
        }
        //identifying the box
        int rowstrt,colstrt,t;
        t=sqrt(num);
        rowstrt=m-m%t;
        colstrt=n-n%t;
        for(i=0;i<t;i++)
        {
            for(j=0;j<t;j++)
            {
                if(z[i+rowstrt][j+colstrt]==ins_num)
                    return false;
            }

        }
    }
    return true;
}
bool unassigned(int a[][9],int *m,int *n,int num)
{
    for(*m=0;*m<num;(*m)++)
    {
        for(*n=0;*n<num;(*n)++)
        {
            if(a[*m][*n]==0)
            {
                return true;
            }

        }
    }
    return false;
}
bool solver(int a[][9],int num)
{
    int row,col;
   // cout<<"welcome to the mystery"<<endl;
    if(!unassigned(a,&row,&col,num))
    {
       // cout<<"yeah"<<endl;
       return true;
    }
    int val;
    for(val=1;val<=num;val++)
    {
        if(checker(a,row,col,num,val))
        {
            a[row][col]=val;
          //  printarr(a,num);
            //cout<<endl;
           // cout<<row<<" "<<col<<"shi wala"<<endl;
            if(solver(a,num))
            {
                //cout<<"ooooh"<<endl;
                return true;
            }
           // cout<<row<<" "<<col<<"glt wala"<<endl;
            a[row][col]=0;
        }
    }
  //
   return false;
}

int main()
{
    int a[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solver(a,9);
    //cout<<checker(a,0,8,9,7);
    /*int row,col;
    unassigned(a,&row,&col,9);
    cout<<row<<" "<<col<<endl;*/
    printarr(a,9);
    return 0;
}
