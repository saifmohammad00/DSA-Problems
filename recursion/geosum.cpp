#include<bits/stdc++.h>
using namespace std;
double geosum(int k)
{
	if(k==0)
	{
	return 1;
	}
	// cout<<k;
	return (1.0/(1 << k))+geosum(k-1);
}
int main()
{
	int k;
	cin>>k;
	cout<<geosum(k);
	return 0;
}