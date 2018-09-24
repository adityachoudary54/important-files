#include<stdio.h>
void heapify(int A[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    int temp;
    if(left<n&&A[left]>A[largest])
        largest=left;
    if(right<n&&A[right]>A[largest])
        largest=right;
    if(largest!=i)
    {
        temp=A[largest];
        A[largest]=A[i];
        A[i]=temp;
        i=largest;
        heapify(A,n,i);
    }
}
void makeheap(int A[],int n)
{
    int j=n/2-1;
    while(j>=0)
    {
        heapify(A,n,j);
        j--;
    }
}
void insertinheap(int A[],int* n,int x)
{
    int temp,parent,i;
    A[*n]=x;
    temp=*n;
    *n=*n+1;
    while(temp>0)
    {
        parent=(temp-1)/2;
        if(A[parent]<A[temp])
        {
            i=A[parent];
            A[parent]=A[temp];
            A[temp]=i;
            temp=parent;
        }
        else
            break;
    }
}

int deleteinheap(int A[],int* n)
{
    int temp;
    temp=A[0];
    A[0]=A[*n-1];
    A[*n-1]=temp;
    *n=*n-1;
    heapify(A,*n,0);
    return temp;
}

void heapsort(int A[],int n)
{
    int m=n;
    int i;
    for(i=1;i<m;i++)
        deleteinheap(A,&n);
}
int main()
{
    int a[100]={12,78,38,25,60,30,40,9,10};
    int size;
    size=9;
    int i;
    makeheap(a,size);
    insertinheap(a,&size,100);
    for(i=0;i<size;i++)
        printf("%3d ",a[i]);
    printf("\n");
    printf("%d\n",deleteinheap(a,&size));
    for(i=0;i<size;i++)
        printf("%3d ",a[i]);
    printf("\n");
    heapsort(a,size);
    for(i=0;i<size;i++)
        printf("%3d ",a[i]);
    return 0;
}
