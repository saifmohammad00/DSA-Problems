#include<bits/stdc++.h>
using namespace std;
int zeros(int n, int s)
{   
	if((n/10)==0)
	{
	return s;
	}
	if((n%10)==0)
	{
	   s++;
	}
	return zeros(n/10, s);

}
int main()
{
	int n,s=0;
	cin>>n;
	cout<<zeros(n,s);
	return 0;
}