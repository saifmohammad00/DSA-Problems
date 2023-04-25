#include<bits/stdc++.h>
using namespace std;
int dig(int s, int a)
{
	if((s/10)==0)
	{
	  return a;
	}
	return dig(s/10, a+1);
}
int main()
{
	int n,k=1;
	cin>>n;
	cout<<dig(n, k);
	return 0;
}