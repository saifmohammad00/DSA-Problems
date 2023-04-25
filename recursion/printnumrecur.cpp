#include<bits/stdc++.h>
using namespace std;
int num(int a, int f)
{    
	if(a==1)
	{
	  return f;
	}
	cout<<f<<" ";
	return num(a-1, f+1);
}
int main()
{
	int n,x=1;
	cin>>n;
	cout<<num(n,x)<<" ";
	return 0;
}