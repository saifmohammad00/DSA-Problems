#include<bits/stdc++.h>
using namespace std;
int fu(int x, int n)
{
    // cout<<n<<endl;
	if(n==0)
	{
	return 1;
	}
	return x*fu(x, n-1);
}
int main()
{
	int x,n;
	cin>>x>>n;
	cout<<fu(x, n);
    return 0;
}