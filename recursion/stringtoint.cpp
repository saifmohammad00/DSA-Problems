#include<bits/stdc++.h>
using namespace std;
int strtoint(char in[])
{
	int a=in[0]-48;
	if(in[0]=='\0')
	{
		return a;
	}
	cout<<a;
	return strtoint(in+1);
}
int main()
{
	char in[100];
	cin>>in;
	strtoint(in);
	return 0;
}