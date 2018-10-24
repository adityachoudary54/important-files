#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
//    char *p;
//    char sample_string[]="codingjunction";
//    p=sample_string;
//    p+=6;
//    printf("%s",p);
//
//    void *c;
//    int a=5;
//    c=int(&a);
//    cout<<*c;
//    return 0;

//    int **a=new int*[2];
//    for(int i=0;i<2;i++)
//        a[i]=new int[2];
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<2;j++){
//            cin>>a[i][j];
//        }
//    }
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<2;j++){
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }

//    int *ptr=(int*)malloc(sizeof(int));
//    ptr=NULL;
//    free(ptr);

//    int a=5,b=10;
//    int &x=a;
//    x=b;
//    cout<<x;

//    int arr[]={0,1,2,3,4};
//    int i,*ptr;
//    for(ptr=arr,i=0;ptr+i<=arr+4;ptr++,i++)
//        cout<<*(ptr+i);
//    return 0;

    int a=10,*j;
    void *k;
    j=k=&a;
    j++;
    k++;
    cout<<j<<k;
    return 0;
}
