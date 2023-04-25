#include<bits/stdc++.h>
using namespace std;
int allindices(int pk[], int p, int x, int t)
{
	if(p==0)
	{
	   return -1;
	}
	if(pk[0]==x)
	{
	   cout<<t+1<<" ";
	}
	t++;
	return allindices(pk+1, p-1, x, t);
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
	int x,t=-1;
	cin>>x;
	allindices(arr, n, x, t);
	return 0;

}