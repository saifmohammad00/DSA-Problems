#include<bits/stdc++.h>
using namespace std;
char replacepi(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{

	}
	if(i==0)
	{
		return 0;
	}
	if(s[0]=='p')
	{
		if(s[1]=='i')
		{
			for(int j=i+1;j!=1;j--)
			{
               s[j+2]=s[j];
			}
			s[0]='3';
			s[1]='.';
			s[2]='1';
			s[3]='4';
		}
	}
	return replacepi(s+1);
}	
int main()
{
	char arr[100];
	cin>>arr;
	replacepi(arr);
	cout<<arr;
	return 0;
}