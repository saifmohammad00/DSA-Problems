#include<bits/stdc++.h>
using namespace std;
char towerofhanoi(char n,char a,char b,char c)
{
	if(n==1)
	{
	  cout<<a<<" "<<c<<endl;
	  return 0;
	}
	towerofhanoi(n-1,a,c,b);
	cout<<a<<" "<<c<<endl;
	return towerofhanoi(n-1,b,a,c);
}
int main()
{
	int n;
	char a='a',b='b',c='c';
	cin>>n;
	towerofhanoi(n,a,b,c);
	return 0;

}