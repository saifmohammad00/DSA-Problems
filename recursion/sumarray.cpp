#include<bits/stdc++.h>
using namespace std;
int sum(int pk[], int ps, int v)
{
    if(ps==0)
    {
      return v;
    }
    v=v+pk[ps-1];
    return sum(pk, ps-1, v);
}
int main()
{
	int n,x=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	cout<<sum(arr, n, x);
	return 0;
}