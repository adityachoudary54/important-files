#include<iostream>
using namespace std;
int get_max(int arr[],int n)
{
    int maxi=arr[0];
    for(int i=0;i<n;i++)
    {
        if(maxi<arr[i])
            maxi=arr[i];
    }
    return maxi;
}

void count_sort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = get_max(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        count_sort(arr, n, exp);
    }

}
int main()
{
    int a[]={5,4,1,1,20,7,3,5,9,10};
    radixsort(a,sizeof(a)/4);
    //cout<<sizeof(a)/4<<endl;
    for(int i=0;i<sizeof(a)/4;i++)
        cout<<a[i]<<" ";
    return 0;
}
