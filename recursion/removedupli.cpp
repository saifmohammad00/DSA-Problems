#include<iostream>
using namespace std;
char dupli(char st[])
{
	int i;
	for(i=0;st[i]!='\0';i++)
	{

	}
	if(i==0)
	{
	  return 0;
	}
	if(st[0]==st[1])
	{
		int j;
		for(j=1;st[j]!='\0';j++)
		{
			st[j]=st[j+1];
	    }
	    dupli(st);
	}
	return dupli(st+1);
}
int main()
{
	char st[100];
	cin>>st;
	dupli(st);
	cout<<st;
	return 0;

}