#include<bits/stdc++.h>
using namespace std;
char deletechar(char in[])
{
    if(in[0]=='\0')
    {
       return 0;
    }
    if(in[0]!='x')
    {
    	return deletechar(in+1);
    }
	else
	{
		int i;
	  for(i=1;in[i]!='\0';i++)
	  {
	    in[i-1]=in[i];
	  }
	  in[i-1]=in[i];

	}
	return deletechar(in);
}
int main()
{
	char in[100];
	cin>>in;
	deletechar(in);
	cout<<in;
	return 0;
}