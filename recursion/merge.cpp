#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int s,int mid,int e)
{
	int i=s;
	int l=s;
	int k=mid+1;
	int temp[10000];
	while(i<=mid && k<=e)
	{
       if(arr[i]<arr[k])
       {
         temp[l]=arr[i];
          i++;
       }
       else
       {
          temp[l]=arr[k];
          k++;
       }
       l++;
	}
	if(i>mid)
	{
		while(k<=e)
		{
			temp[l]=arr[k];
			k++;l++;
		}
	}
	else
	{
		while(i<=mid)
		{
          temp[l]=arr[i];
             i++;l++;
		}
	}
	for(int l=s;l<=e;l++)
	{
	   arr[l]=temp[l];
	}
}
void mergesort(int arr[], int s, int e)
{
	if(s<e)
	{
	int mid=(s+e)/2;
	mergesort(arr, s, mid);
	mergesort(arr, mid+1, e);
	merge(arr,s,mid,e);
   }
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	}
	mergesort(arr, 0, n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}