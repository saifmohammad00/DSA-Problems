#include<bits/stdc++.h>
using namespace std;
int sumdig(int n)
{
	if(n/10==0)
	{
	   return n%10;
	}

	return (n%10)+sumdig(n/10);
}
int main()
{
	int n;
	cin>>n;
	cout<<sumdig(n);
	return 0;
}