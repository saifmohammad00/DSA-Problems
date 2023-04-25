#include<bits/stdc++.h>
using namespace std;
int firstindex(int pk[], int s, int y, int l)
{
	if(s==0)
	{
      return -1;
	}
	
	if(pk[0]==y)
	{
	   return l+1;
	}
	l++;
	return firstindex(pk+1, s-1, y, l);

	
}
int main()
{
	int n,m=-1;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	   cin>>arr[i];
	}
	int x;
	cin>>x;
	cout<<firstindex(arr, n, x, m);
	return 0;
}