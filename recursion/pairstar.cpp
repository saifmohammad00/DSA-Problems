#include<bits/stdc++.h>
using namespace std;
char pairstar(char in[])
{
	if(in[0]=='\0')
	{
	   return 0;
	}
	if(in[0]!=in[1])
	{
	  return pairstar(in+1);
	}
	if(in[0]==in[1])
	{
	   int i;
	   for(i=0;in[i]!='\0';i++)
	   {
	      
	   }
	   for(int j=i;j!=0;j--)
	   {
	     in[j+1]=in[j];
	   }
	   in[1]='*';
	}
	return pairstar(in);
}
int main()
{
	char in[100];
	cin>>in;
	pairstar(in);
	cout<<in;
	return 0;
}