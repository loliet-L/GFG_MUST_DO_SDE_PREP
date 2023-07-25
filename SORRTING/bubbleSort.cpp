#include<bits/stdc++.h>
using namespace std;

// 1 2 3 4 5 

void bubbleSort(int arr[] ,int n)
{
    for(int i=n-1;i<=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[j+1])swap(arr[j],arr[j+1]);
        }
    }

}

int main()
{
    int arr[5]={2,4,1,5,3};
    int n=5;
    for(int i=n-1;i<=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
        }
    }
    for(int i=0;i<5;i++)cout<<arr[i]<<" ";
}