#include<iostream>
using namespace std;
struct dragon
{
    int st,bon;
}a[1000];
int partition(dragon a[],int start,int end)
{
	int i,pindex,pivot;
	dragon t;
	pindex=start;
	i=start;
	pivot=a[end].st;
	while(i<=end-1)
	{
		if(a[i].st<=pivot)
		{
		 t=a[pindex];
		 a[pindex]=a[i];
		 a[i]=t;
			pindex++;
		}
		i++;
	}
	t=a[end];
	a[end]=a[pindex];
	a[pindex]=t;
	/*printf("\nThe array at this moment is :");
	for(i=start;i<=end;i++)
	{
		printf("%d ",a[i]);
	}*/
	return pindex;
}
int quicksort(dragon a[],int start,int end)
{
	int pindex;
	if(start<end)
	{
		pindex=partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
	return 0;
}

int main()
{
    int s,n,i,t;
    cin>>s>>n;
    t=1;
    for(i=0;i<n;i++)
        cin>>a[i].st>>a[i].bon;
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        if(s>a[i].st)
            s=s+a[i].bon;
        else
        {
            t=0;
            break;
        }
    }
    if(t)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;

}

