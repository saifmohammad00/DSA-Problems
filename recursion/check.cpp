#include<bits/stdc++.h>
using namespace std;
int check(int pk[], int p,int q)
{

	if(p==0)
	{
		cout<<"false";
		return false;
	}
	if(q==pk[p-1])
	{
		cout<<"true";
	  return true;
	}
	return check(pk, p-1,q);
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
	int x;
	cin>>x;
	check(arr, n, x);
	return 0;
}